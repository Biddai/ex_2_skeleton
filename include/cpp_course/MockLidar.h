#pragma once

#include <cpp_course/IGPS.h>
#include <cpp_course/ILidar.h>
#include <cpp_course/IMap3D.h>

namespace cpp_course {

class MockLidar final : public ILidar {
public:
    MockLidar(LidarConfigData config, const IMap3D& map, const IGPS& gps);

    [[nodiscard]] LidarScanResult scan(Orientation scan_orientation) const override;

private:
    [[nodiscard]] PhysicalLength traceBeam(const Orientation& beam) const;

    LidarConfigData config_;
    const IMap3D& map_;
    const IGPS& gps_;
};

} // namespace cpp_course
