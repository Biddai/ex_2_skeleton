# Assignment 2 Refactor Skeleton

This repository is a compilable skeleton for Assignment 2 in the 2026 Advanced
Topics in Programming course. It intentionally provides interfaces, data types,
dependency-injected component stubs, and a preserved mock LiDAR implementation.
It does not implement the full simulator or mapping solution.

## Included Components

- `Units.h` contains the shared physical units, positions, and orientations
  used by the public interfaces.
- `Types.h` contains YAML-facing configuration data, scan data, movement
  commands, run results, and report structs.
- Mandatory PDF-aligned interfaces are provided for simulation, mission control,
  drone control, mapping algorithm, LiDAR, GPS, and drone movement.
- Stub implementations are provided for `SimulationManager`,
  `SimulationRunFactoryImpl`, `SimulationRunImpl`, `MissionControlImpl`,
  `DroneControlImpl`, `MappingAlgorithmImpl`, `ScanResultToVoxels`, and
  `MapsComparison`.
- `MockLidar` is a real ray-marching mock LiDAR implementation preserved from
  the starter project and adapted to the new `ILidar`/`IGPS` interfaces.
- `Map3DImpl` is a placeholder for `.npy` occupancy maps, stores the TinyNPY
  array, and stores the map resolution supplied during construction.

## Project Structure

```text
include/cpp_course/      Public interfaces, data types, and skeleton classes
src/                     Stub implementations and executable entry points
data_maps/               Example NumPy voxel maps
.devcontainer/           Development container setup
CMakeLists.txt           CMake build configuration
vcpkg.json               Dependency list
```

## Building

```bash
cmake --preset default
cmake --build --preset default
```

The main build targets are:

```text
cpp_course
drone_mapper_simulation
maps_comparison
```

## Running

Simulator skeleton:

```bash
./build/drone_mapper_simulation [simulation.yaml] [output_path]
```

The skeleton wires explicit placeholder components and reports stub results.
Students should add YAML parsing, scenario composition, output writing, error
logging, and real simulator behavior.

Maps comparison skeleton:

```bash
./build/maps_comparison <map1> <map2> [resolution_ratio=<res1>/<res2>]
```

The provided `MapsComparison` implementation is only a placeholder. Students
should replace it with the required scoring behavior.

## Student Work

The API signatures were derived from the assignment PDF because the official
reference stub was not available here. Students should implement the behavior
behind these contracts: YAML configuration loading, simulation composition
expansion, mission execution, drone movement decisions, scan-to-voxel mapping,
map output, score reporting, immediate error logging, component tests, and
integration tests.
