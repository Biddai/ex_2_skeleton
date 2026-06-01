#pragma once

#include <cpp_course/ISimulationRun.h>
#include <cpp_course/Types.h>

#include <filesystem>
#include <memory>

namespace cpp_course {

// **Do not change this interface.**
class ISimulationRunFactory {
public:
    virtual ~ISimulationRunFactory() = default;

    [[nodiscard]] virtual std::unique_ptr<ISimulationRun>
    create(const SimulationConfigData& simulation,
           const MissionConfigData& mission,
           const DroneConfigData& drone,
           const LidarConfigData& lidar,
           const std::filesystem::path& output_path) = 0;
};

} // namespace cpp_course
