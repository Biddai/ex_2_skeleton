cmake_minimum_required(VERSION 3.20)
project(cpp_course LANGUAGES CXX)

find_package(mp-units CONFIG REQUIRED)
find_package(tinynpy CONFIG REQUIRED)

add_library(cpp_course
    src/DroneControlImpl.cpp
    src/MappingAlgorithmImpl.cpp
    src/MapsComparison.cpp
    src/MissionControlImpl.cpp
    src/Map3DImpl.cpp
    src/MockGPS.cpp
    src/MockLidar.cpp
    src/MockMovement.cpp
    src/ScanResultToVoxels.cpp
    src/SimulationManager.cpp
    src/SimulationRunFactoryImpl.cpp
    src/SimulationRunImpl.cpp
)

target_compile_features(cpp_course PUBLIC cxx_std_20)
target_compile_options(cpp_course
    PRIVATE
        -Wall
        -Wextra
        -Werror
        -pedantic
)

target_include_directories(cpp_course
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(cpp_course
    PUBLIC
        mp-units::mp-units
        TinyNPY::TinyNPY
)

add_executable(drone_mapper_simulation src/drone_mapper_simulation_main.cpp)
target_link_libraries(drone_mapper_simulation PRIVATE cpp_course)

add_executable(maps_comparison src/maps_comparison_main.cpp)
target_link_libraries(maps_comparison PRIVATE cpp_course)
