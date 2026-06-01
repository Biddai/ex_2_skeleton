#pragma once

#include <cpp_course/Types.h>

namespace cpp_course {

// **Do not change this interface.**
class IDroneControl {
public:
    virtual ~IDroneControl() = default;

    virtual void initialize(const DroneConfigData& drone, const MissionConfigData& mission) = 0;
    [[nodiscard]] virtual DroneStepResult step() = 0;
    [[nodiscard]] virtual DroneState state() const = 0;
};

} // namespace cpp_course
