# SETUP PROJECT PROPERTIES

cmake_minimum_required(VERSION 3.16.0)
project(r-type LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/build)
include(DetectCompiler)

# find_package(SFML REQUIRED system window graphics network audio)

add_subdirectory(src/game)
add_subdirectory(src/network)

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGET)
