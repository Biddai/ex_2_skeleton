#pragma once

#include <cpp_course/IDroneControl.h>
#include <cpp_course/IDroneMovement.h>
#include <cpp_course/IGPS.h>
#include <cpp_course/ILidar.h>
#include <cpp_course/IMappingAlgorithm.h>
#include <cpp_course/IMutableMap3D.h>

#include <optional>

namespace cpp_course {

class DroneControlImpl final : public IDroneControl {
public:
    DroneControlImpl(ILidar& lidar,
                     IGPS& gps,
                     IDroneMovement& movement,
                     IMutableMap3D& output_map,
                     IMappingAlgorithm& mapping_algorithm);

    void initialize(const DroneConfigData& drone, const MissionConfigData& mission) override;
    [[nodiscard]] DroneStepResult step() override;
    [[nodiscard]] DroneState state() const override;

private:
    ILidar& lidar_;
    IGPS& gps_;
    IDroneMovement& movement_;
    IMutableMap3D& output_map_;
    IMappingAlgorithm& mapping_algorithm_;
    std::optional<DroneConfigData> drone_;
    std::optional<MissionConfigData> mission_;
    std::size_t step_index_ = 0;
};

} // namespace cpp_course
