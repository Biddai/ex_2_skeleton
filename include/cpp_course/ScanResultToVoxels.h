#pragma once

#include <cpp_course/Types.h>

#include <vector>

namespace cpp_course {

class ScanResultToVoxels {
public:
    [[nodiscard]] static std::vector<MappedVoxel> convert(const Position3D& scan_origin,
                                                          const Orientation& drone_heading,
                                                          const LidarScanResult& scan);
};

} // namespace cpp_course
