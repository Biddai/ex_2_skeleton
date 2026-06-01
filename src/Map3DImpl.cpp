#include <cpp_course/Map3DImpl.h>

#include <fstream>
#include <stdexcept>
#include <string>

namespace cpp_course {

Map3DImpl::Map3DImpl(const std::filesystem::path& path, PhysicalLength resolution)
    : resolution_(resolution) {
    const std::string path_string = path.string();
    const char* error = map_.LoadNPY(path_string.c_str());
    if (error != nullptr) {
        throw std::runtime_error(std::string("Failed to load NPY file: ") + error);
    }
}

Map3DImpl::Map3DImpl(const MappingBounds& bounds, PhysicalLength resolution)
    : resolution_(resolution) {
    (void)bounds;
}

VoxelOccupancy Map3DImpl::get(const Position3D& pos) const {
    (void)pos;
    return VoxelOccupancy::Unmapped;
}

void Map3DImpl::set(const Position3D& pos, VoxelOccupancy value) {
    (void)pos;
    (void)value;
}

void Map3DImpl::save(const std::filesystem::path& path) const {
    std::ofstream output{path};
    if (!output) {
        throw std::runtime_error("Failed to create output map file.");
    }
}

} // namespace cpp_course
