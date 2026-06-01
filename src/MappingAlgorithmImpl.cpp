#include <cpp_course/MappingAlgorithmImpl.h>

namespace cpp_course {

void MappingAlgorithmImpl::initialize(const MissionConfigData& mission) {
    mission_ = mission;
}

MovementCommand MappingAlgorithmImpl::nextMove(const DroneState& state,
                                               const LidarScanResult& latest_scan) {
    (void)state;
    (void)latest_scan;
    return MovementCommand{};
}

void MappingAlgorithmImpl::applyVoxelUpdates(const std::vector<MappedVoxel>& voxels) {
    (void)voxels;
}

} // namespace cpp_course
