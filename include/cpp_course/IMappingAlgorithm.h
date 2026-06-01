#pragma once

#include <cpp_course/Types.h>

#include <vector>

namespace cpp_course {

// **Do not change this interface.**
class IMappingAlgorithm {
public:
    virtual ~IMappingAlgorithm() = default;

    virtual void initialize(const MissionConfigData& mission) = 0;
    [[nodiscard]] virtual MovementCommand nextMove(const DroneState& state,
                                                   const LidarScanResult& latest_scan) = 0;
    virtual void applyVoxelUpdates(const std::vector<MappedVoxel>& voxels) = 0;
};

} // namespace cpp_course
