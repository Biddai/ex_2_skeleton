#include <cpp_course/SimulationManager.h>
#include <cpp_course/SimulationRunFactoryImpl.h>

#include <filesystem>
#include <iostream>
#include <memory>

int main(int argc, char** argv) {
    const std::filesystem::path composition_file =
        (argc >= 2) ? std::filesystem::path{argv[1]} : std::filesystem::path{"simulation.yaml"};
    const std::filesystem::path output_path =
        (argc >= 3) ? std::filesystem::path{argv[2]} : std::filesystem::current_path();

    auto run_factory = std::make_unique<cpp_course::SimulationRunFactoryImpl>();
    cpp_course::SimulationManager simulation{std::move(run_factory)};

    const cpp_course::MappingBounds bounds{
        -500.0 * cpp_course::x_extent[cpp_course::cm],
        500.0 * cpp_course::x_extent[cpp_course::cm],
        -500.0 * cpp_course::y_extent[cpp_course::cm],
        500.0 * cpp_course::y_extent[cpp_course::cm],
        0.0 * cpp_course::z_extent[cpp_course::cm],
        300.0 * cpp_course::z_extent[cpp_course::cm],
    };
    cpp_course::SimulationCompositionData composition{
        composition_file,
        {cpp_course::SimulationConfigData{
            "data_maps/single_voxel_x2_y4_z2.npy",
            10.0 * cpp_course::cm,
            cpp_course::Position3D{},
            0.0 * cpp_course::horizontal_angle[cpp_course::deg],
        }},
        {cpp_course::MissionConfigData{1, bounds, 10.0 * cpp_course::cm, 1}},
        {cpp_course::DroneConfigData{
            30.0 * cpp_course::cm,
            45.0 * cpp_course::horizontal_angle[cpp_course::deg],
            50.0 * cpp_course::cm,
            40.0 * cpp_course::cm,
        }},
        {cpp_course::LidarConfigData{
            20.0 * cpp_course::cm,
            120.0 * cpp_course::cm,
            2.5 * cpp_course::cm,
            5,
        }},
    };
    const cpp_course::SimulationReport report = simulation.run(composition, output_path);

    std::cout << "Assignment 2 simulator skeleton ran "
              << report.simulations.size()
              << " score group(s).\n";
    return 0;
}
