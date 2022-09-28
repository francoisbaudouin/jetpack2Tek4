# SETUP PROJECT PROPERTIES

cmake_minimum_required(VERSION 3.16.0)
project(r-type LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(DetectCompiler)

add_subdirectory(src/game)
add_subdirectory(src/network)