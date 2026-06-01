#pragma once

#include <cpp_course/Types.h>

namespace cpp_course {

// **Do not change this interface.**
class IDroneMovement {
public:
    virtual ~IDroneMovement() = default;

    virtual MovementResult rotate(RotationDirection direction, HorizontalAngle angle) = 0;
    virtual MovementResult advance(PhysicalLength distance) = 0;
    virtual MovementResult elevate(PhysicalLength distance) = 0; // Can be negative!
};

} // namespace cpp_course
