#include <cpp_course/MockMovement.h>

namespace cpp_course {

MockMovement::MockMovement(MockGPS& gps) : gps_(gps) {}

MovementResult MockMovement::rotate(RotationDirection direction, HorizontalAngle angle) {
    const Orientation current = gps_.heading();
    const HorizontalAngle signed_angle =
        (direction == RotationDirection::Left) ? angle : -angle;
    gps_.setHeading(Orientation{current.horizontal + signed_angle, current.altitude});
    return MovementResult{true, {}};
}

MovementResult MockMovement::advance(PhysicalLength distance) {
    (void)distance;
    return MovementResult{true, {}};
}

MovementResult MockMovement::elevate(PhysicalLength distance) {
    (void)distance;
    return MovementResult{true, {}};
}

} // namespace cpp_course
