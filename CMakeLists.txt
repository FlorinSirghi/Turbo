cmake_minimum_required(VERSION 3.20)
project(EngineProject)

add_subdirectory(Turbo/)

set(CMAKE_CXX_STANDARD 20)

add_executable(EngineProject EngineProject/src/EngineProject.cpp)

target_compile_definitions(EngineProject PRIVATE TURBO_WINDOWS)

target_include_directories(EngineProject PRIVATE Turbo/src/)

target_link_libraries(EngineProject PRIVATE Turbo)

add_custom_command(TARGET EngineProject POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_BINARY_DIR}/Turbo/Debug/Turbo.dll" "${CMAKE_BINARY_DIR}"
)
