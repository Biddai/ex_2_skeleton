#pragma once

#include <TinyNPY.h>

#include <cpp_course/IMutableMap3D.h>

#include <filesystem>

namespace cpp_course {

class Map3DImpl final : public IMutableMap3D {
public:
    Map3DImpl(const std::filesystem::path& path, PhysicalLength resolution);
    Map3DImpl(const MappingBounds& bounds, PhysicalLength resolution);

    [[nodiscard]] VoxelOccupancy get(const Position3D& pos) const override;
    void set(const Position3D& pos, VoxelOccupancy value) override;
    void save(const std::filesystem::path& path) const override;
    [[nodiscard]] PhysicalLength getRes() const;

private:
    NpyArray map_;
    PhysicalLength resolution_;
};

} // namespace cpp_course
