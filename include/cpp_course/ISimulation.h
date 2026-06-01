#pragma once

#include <cpp_course/Types.h>

#include <filesystem>

namespace cpp_course {

// **Do not change this interface.**
class ISimulation {
public:
    virtual ~ISimulation() = default;

    [[nodiscard]] virtual SimulationReport run(const SimulationCompositionData& composition,
                                               const std::filesystem::path& output_path) = 0;
};

} // namespace cpp_course
