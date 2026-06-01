#pragma once

#include <cpp_course/IDroneControl.h>
#include <cpp_course/IMap3D.h>
#include <cpp_course/IMissionControl.h>
#include <cpp_course/IMutableMap3D.h>

#include <filesystem>

namespace cpp_course {

class MissionControlImpl final : public IMissionControl {
public:
    MissionControlImpl(MissionConfigData mission,
                       DroneConfigData drone,
                       const IMap3D& hidden_map,
                       IMutableMap3D& output_map,
                       IDroneControl& drone_control,
                       std::filesystem::path output_map_file);

    [[nodiscard]] MissionRunResult runMission() override;

private:
    MissionConfigData mission_;
    DroneConfigData drone_;
    const IMap3D& hidden_map_;
    IMutableMap3D& output_map_;
    IDroneControl& drone_control_;
    std::filesystem::path output_map_file_;
};

} // namespace cpp_course
