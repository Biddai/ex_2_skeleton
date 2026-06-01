#pragma once

#include <cpp_course/ISimulationRunFactory.h>

namespace cpp_course {

class SimulationRunFactoryImpl final : public ISimulationRunFactory {
public:
    [[nodiscard]] std::unique_ptr<ISimulationRun>
    create(const SimulationConfigData& simulation,
           const MissionConfigData& mission,
           const DroneConfigData& drone,
           const LidarConfigData& lidar,
           const std::filesystem::path& output_path) override;
};

} // namespace cpp_course
