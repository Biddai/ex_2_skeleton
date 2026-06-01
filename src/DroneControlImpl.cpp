#include <cpp_course/DroneControlImpl.h>

namespace cpp_course {

DroneControlImpl::DroneControlImpl(ILidar& lidar,
                                   IGPS& gps,
                                   IDroneMovement& movement,
                                   IMutableMap3D& output_map,
                                   IMappingAlgorithm& mapping_algorithm)
    : lidar_(lidar),
      gps_(gps),
      movement_(movement),
      output_map_(output_map),
      mapping_algorithm_(mapping_algorithm) {}

void DroneControlImpl::initialize(const DroneConfigData& drone, const MissionConfigData& mission) {
    drone_ = drone;
    mission_ = mission;
    step_index_ = 0;
}

DroneStepResult DroneControlImpl::step() {
    if (!drone_ || !mission_) {
        return DroneStepResult{DroneStepStatus::Error, "DroneControlImpl was not initialized."};
    }

    (void)lidar_;
    (void)movement_;
    (void)output_map_;
    (void)mapping_algorithm_;
    return DroneStepResult{DroneStepStatus::Error, "DroneControlImpl::step is a stub."};
}

DroneState DroneControlImpl::state() const {
    return DroneState{gps_.position(), gps_.heading(), step_index_};
}

} // namespace cpp_course
