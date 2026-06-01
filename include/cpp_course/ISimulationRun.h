#pragma once

#include <cpp_course/Types.h>

namespace cpp_course {

// **Do not change this interface.**
class ISimulationRun {
public:
    virtual ~ISimulationRun() = default;

    [[nodiscard]] virtual MissionRunResult run() = 0;
};

} // namespace cpp_course
