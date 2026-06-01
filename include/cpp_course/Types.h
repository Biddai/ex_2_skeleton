#pragma once

#include <cpp_course/Units.h>

#include <cstddef>
#include <filesystem>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace cpp_course {

enum class VoxelOccupancy {
    OutOfBounds = -2,
    Unmapped = -1,
    Empty = 0,
    Occupied = 1,
};

struct LidarConfigData {
    LidarConfigData() = delete; // default\empty not allowed ()

    LidarConfigData(PhysicalLength z_min_value,
                    PhysicalLength z_max_value,
                    PhysicalLength d_value,
                    std::size_t fov_circles_value)
        : z_min(z_min_value),
          z_max(z_max_value),
          d(d_value),
          fov_circles(fov_circles_value) {}

    PhysicalLength z_min;
    PhysicalLength z_max;
    PhysicalLength d;
    std::size_t fov_circles;
};

struct LidarHit {
    PhysicalLength distance{};
    Orientation angle{};
};

using LidarScanResult = std::vector<LidarHit>;


struct DroneConfigData {
    DroneConfigData() = delete;

    DroneConfigData(PhysicalLength dimensions_value,
                    HorizontalAngle max_rotate_value,
                    PhysicalLength max_advance_value,
                    PhysicalLength max_elevate_value)
        : dimensions(dimensions_value),
          max_rotate(max_rotate_value),
          max_advance(max_advance_value),
          max_elevate(max_elevate_value) {}

    PhysicalLength dimensions;
    HorizontalAngle max_rotate;
    PhysicalLength max_advance;
    PhysicalLength max_elevate;
};

struct MappingBounds {
    MappingBounds() = delete;

    MappingBounds(XLength min_x_value,
                  XLength max_x_value,
                  YLength min_y_value,
                  YLength max_y_value,
                  ZLength min_height_value,
                  ZLength max_height_value)
        : min_x(min_x_value),
          max_x(max_x_value),
          min_y(min_y_value),
          max_y(max_y_value),
          min_height(min_height_value),
          max_height(max_height_value) {}

    XLength min_x;
    XLength max_x;
    YLength min_y;
    YLength max_y;
    ZLength min_height;
    ZLength max_height;
};

struct MissionConfigData {
    MissionConfigData() = delete;

    MissionConfigData(std::size_t max_steps_value,
                      MappingBounds boundaries_value,
                      PhysicalLength gps_resolution_value,
                      int output_mapping_resolution_factor_value)
        : max_steps(max_steps_value),
          boundaries(boundaries_value),
          gps_resolution(gps_resolution_value),
          output_mapping_resolution_factor(output_mapping_resolution_factor_value) {}

    std::size_t max_steps;
    MappingBounds boundaries;
    PhysicalLength gps_resolution;
    int output_mapping_resolution_factor;
};

struct SimulationConfigData {
    SimulationConfigData() = delete;

    SimulationConfigData(std::filesystem::path map_filename_value,
                         PhysicalLength map_resolution_value,
                         Position3D initial_drone_position_value,
                         HorizontalAngle initial_angle_value)
        : map_filename(std::move(map_filename_value)),
          map_resolution(map_resolution_value),
          initial_drone_position(initial_drone_position_value),
          initial_angle(initial_angle_value) {}

    std::filesystem::path map_filename;
    PhysicalLength map_resolution;
    Position3D initial_drone_position;
    HorizontalAngle initial_angle;
};

struct SimulationCompositionData {
    SimulationCompositionData() = delete;

    SimulationCompositionData(std::filesystem::path composition_file_value,
                              std::vector<SimulationConfigData> simulations_value,
                              std::vector<MissionConfigData> missions_value,
                              std::vector<DroneConfigData> drones_value,
                              std::vector<LidarConfigData> lidars_value)
        : composition_file(std::move(composition_file_value)),
          simulations(std::move(simulations_value)),
          missions(std::move(missions_value)),
          drones(std::move(drones_value)),
          lidars(std::move(lidars_value)) {}

    std::filesystem::path composition_file;
    std::vector<SimulationConfigData> simulations;
    std::vector<MissionConfigData> missions;
    std::vector<DroneConfigData> drones;
    std::vector<LidarConfigData> lidars;
};

enum class RotationDirection {
    Left,
    Right,
};

enum class MovementCommandType {
    Hover,
    Rotate,
    Advance,
    Elevate,
};

struct MovementCommand {
    MovementCommandType type = MovementCommandType::Hover;
    RotationDirection rotation = RotationDirection::Left;
    HorizontalAngle angle = 0.0 * horizontal_angle[deg];
    PhysicalLength distance = 0.0 * cm;
};

struct MovementResult {
    bool success = true;
    std::string message{};

    [[nodiscard]] explicit operator bool() const noexcept {
        return success;
    }
};

struct DroneState {
    Position3D position{};
    Orientation heading{};
    std::size_t step_index = 0;
};

struct MappedVoxel {
    Position3D position{};
    VoxelOccupancy value = VoxelOccupancy::Unmapped;
};

enum class DroneStepStatus {
    Continue,
    Completed,
    Error,
};

struct DroneStepResult {
    DroneStepStatus status = DroneStepStatus::Continue;
    std::string message{};
};

enum class MissionRunStatus {
    Completed,
    MaxSteps,
    Error,
};

struct ErrorRef {
    std::string code{};
    std::string message{};
};

struct MissionRunResult {
    MissionRunStatus status = MissionRunStatus::Completed;
    std::size_t steps = 0;
    double score = 0.0;
    std::filesystem::path output_map_file{};
    std::optional<ErrorRef> error{};
};

enum class ResolutionRequestStatus {
    Accepted,
    Ignored,
    IgnoredTooSmall,
};

struct MissionScoreGroup {
    MissionScoreGroup() = delete;

    MissionScoreGroup(MissionConfigData mission_value,
                      PhysicalLength resolution_value,
                      ResolutionRequestStatus resolution_request_status_value,
                      std::vector<MissionRunResult> runs_value)
        : mission(mission_value),
          resolution(resolution_value),
          resolution_request_status(resolution_request_status_value),
          runs(std::move(runs_value)) {}

    MissionConfigData mission;
    PhysicalLength resolution;
    ResolutionRequestStatus resolution_request_status;
    std::vector<MissionRunResult> runs;
};

struct SimulationReport {
    std::filesystem::path composition_file{};
    std::string generated_at_utc{};
    std::vector<MissionScoreGroup> simulations{};
};

} // namespace cpp_course
