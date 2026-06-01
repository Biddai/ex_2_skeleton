#pragma once

#include <cpp_course/Types.h>

namespace cpp_course {

// **Do not change this interface.**
class ILidar {
public:
    virtual ~ILidar() = default;

    [[nodiscard]] virtual LidarScanResult scan(Orientation scan_orientation) const = 0;
};

} // namespace cpp_course
