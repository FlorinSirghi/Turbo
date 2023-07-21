cmake_minimum_required(VERSION 3.20)
project(stbimage)

set(CMAKE_CXX_STANDARD 20)

add_library(stbimage stb_image.h stb_image.cpp)

target_include_directories(stbimage PUBLIC .)