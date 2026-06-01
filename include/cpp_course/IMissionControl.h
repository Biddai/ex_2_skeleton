#pragma once

#include <cpp_course/Types.h>

namespace cpp_course {

// **Do not change this interface.**
class IMissionControl {
public:
    virtual ~IMissionControl() = default;

    [[nodiscard]] virtual MissionRunResult runMission() = 0;
};

} // namespace cpp_course
