cmake_minimum_required(VERSION 3.27.0)

set(CMAKE_SUPPRESS_REGENERATION true)

project(Turbo)

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB_RECURSE HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_library(Turbo ${SOURCES} ${HEADERS})

target_compile_definitions(Turbo PRIVATE 
    TURBO_WINDOWS 
    TURBO_EXPORT)
