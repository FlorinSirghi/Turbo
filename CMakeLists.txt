cmake_minimum_required(VERSION 3.20)
project(EngineProject)

add_subdirectory(Turbo/)

set(CMAKE_CXX_STANDARD 20)

add_executable(EngineProject EngineProject/src/EngineProject.cpp)

target_compile_definitions(EngineProject PRIVATE TURBO_WINDOWS)

target_include_directories(EngineProject PRIVATE Turbo/src/)

target_link_libraries(EngineProject PRIVATE Turbo)

# Create a custom target to copy the Turbo.dll
add_custom_target(CopyTurboDLL ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_BINARY_DIR}/Turbo/Debug/Turbo.dll"
        "${CMAKE_BINARY_DIR}/Debug/"
    DEPENDS Turbo
)

# Make EngineProject depend on CopyTurboDLL
add_dependencies(EngineProject CopyTurboDLL)