#pragma once

#include <cpp_course/IMappingAlgorithm.h>

#include <optional>

namespace cpp_course {

class MappingAlgorithmImpl final : public IMappingAlgorithm {
public:
    void initialize(const MissionConfigData& mission) override;
    [[nodiscard]] MovementCommand nextMove(const DroneState& state,
                                           const LidarScanResult& latest_scan) override;
    void applyVoxelUpdates(const std::vector<MappedVoxel>& voxels) override;

private:
    std::optional<MissionConfigData> mission_;
};

} // namespace cpp_course
