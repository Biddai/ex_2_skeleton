#pragma once

#include <cpp_course/IDroneMovement.h>
#include <cpp_course/MockGPS.h>

namespace cpp_course {
// Optional implementation for the 
class MockMovement final : public IDroneMovement {
public:
    explicit MockMovement(MockGPS& gps);

    MovementResult rotate(RotationDirection direction, HorizontalAngle angle) override;
    MovementResult advance(PhysicalLength distance) override;
    MovementResult elevate(PhysicalLength distance) override;

private:
    MockGPS& gps_;
};

} // namespace cpp_course
