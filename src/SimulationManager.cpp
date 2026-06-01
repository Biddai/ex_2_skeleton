#include <cpp_course/SimulationManager.h>

#include <stdexcept>
#include <utility>

namespace cpp_course {

SimulationManager::SimulationManager(std::unique_ptr<ISimulationRunFactory> run_factory)
    : run_factory_(std::move(run_factory)) {
    if (!run_factory_) {
        throw std::invalid_argument("SimulationManager requires a run factory.");
    }
}

SimulationReport SimulationManager::run(const SimulationCompositionData& composition,
                                        const std::filesystem::path& output_path) {
    std::vector<MissionScoreGroup> score_groups;

    for (const SimulationConfigData& simulation : composition.simulations) {
        for (const MissionConfigData& mission : composition.missions) {
            std::vector<MissionRunResult> results;

            for (const DroneConfigData& drone : composition.drones) {
                for (const LidarConfigData& lidar : composition.lidars) {
                    std::unique_ptr<ISimulationRun> run =
                        run_factory_->create(simulation, mission, drone, lidar, output_path);
                    results.push_back(run->run());
                }
            }

            score_groups.emplace_back(
                mission,
                simulation.map_resolution,
                ResolutionRequestStatus::Ignored,
                std::move(results));
        }
    }

    return SimulationReport{composition.composition_file, "stub", std::move(score_groups)};
}

} // namespace cpp_course
