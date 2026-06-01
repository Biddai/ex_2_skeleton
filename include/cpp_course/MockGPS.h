#pragma once

#include <cpp_course/IGPS.h>

namespace cpp_course {

class MockGPS final : public IGPS {
public:
    MockGPS(Position3D position, Orientation heading);

    [[nodiscard]] Position3D position() const override;
    [[nodiscard]] Orientation heading() const override;

    void setPosition(Position3D position);
    void setHeading(Orientation heading);

private:
    Position3D position_{};
    Orientation heading_{};
};

} // namespace cpp_course
