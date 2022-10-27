# SETUP PROJECT PROPERTIES

cmake_minimum_required(VERSION 3.16.0)
project(r-type LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(DetectCompiler)

find_package(SFML REQUIRED system window graphics network audio)

add_subdirectory(src/client)
add_subdirectory(src/server)
