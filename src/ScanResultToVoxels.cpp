#include <cpp_course/ScanResultToVoxels.h>

namespace cpp_course {

std::vector<MappedVoxel> ScanResultToVoxels::convert(const Position3D& scan_origin,
                                                     const Orientation& drone_heading,
                                                     const LidarScanResult& scan) {
    (void)scan_origin;
    (void)drone_heading;
    (void)scan;
    return {};
}

} // namespace cpp_course
