cmake_minimum_required(VERSION 3.20)
project(Turbo)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(dependencies/glfw/)
add_subdirectory(dependencies/glad/)
add_subdirectory(dependencies/imgui/) 

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

add_library(Turbo SHARED ${SOURCES})

set_target_properties(Turbo PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_compile_definitions(Turbo PRIVATE TURBO_WINDOWS TURBO_EXPORT)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src FILES ${SOURCES})

target_include_directories(Turbo PUBLIC src/)

target_link_libraries(Turbo PUBLIC glfw glad imgui)
