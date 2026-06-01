#pragma once

#include <cpp_course/IMap3D.h>

#include <filesystem>

namespace cpp_course {

// **Do not change this interface.**
class IMutableMap3D : public IMap3D {
public:
    ~IMutableMap3D() override = default;

    virtual void set(const Position3D& pos, VoxelOccupancy value) = 0;
    virtual void save(const std::filesystem::path& path) const = 0;
};

} // namespace cpp_course
