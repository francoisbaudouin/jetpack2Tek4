# SETUP PROJECT PROPERTIES

cmake_minimum_required(VERSION 3.18.0)
project(r-type LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
#list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/build)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(DetectCompiler)

set_property(TARGET ${TARGET} PROPERTY MSVC_RUNTIME_LIBRARY "")

add_subdirectory(src/client)
add_subdirectory(src/server)

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)