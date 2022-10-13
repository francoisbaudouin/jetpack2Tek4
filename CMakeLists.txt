# SETUP PROJECT PROPERTIES

cmake_minimum_required(VERSION 3.16.0)
project(r-type LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

option(BUILD_TEST_SUITE OFF)
option(ENABLE_CODE_COVERAGE OFF)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(DetectCompiler)
include(GoogleTest)

add_subdirectory(src/game)
add_subdirectory(src/network)

# Unit testing
# if(BUILD_TEST_SUITE)
# Check for GoogleTest
find_package(googletest REQUIRED)

# Disable error on Linux release builds
if(COMPILER_TYPE MATCHES "gcc")
    target_compile_options(gtest PRIVATE "-Wno-error=restrict")
    target_compile_options(gmock PRIVATE "-Wno-error=restrict")
endif()

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_subdirectory(tests)

# endif()
