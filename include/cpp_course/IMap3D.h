#pragma once

#include <cpp_course/Types.h>

namespace cpp_course {

// Read-only 3D occupancy map interface used by LiDAR implementations.
// **Do not change this interface.**
class IMap3D {
public:
    virtual ~IMap3D() = default;

    [[nodiscard]] virtual VoxelOccupancy get(const Position3D& pos) const = 0;

};

} // namespace cpp_course
