set(SRCROOT ${PROJECT_SOURCE_DIR}/src/network)
set(INCROOT ${PROJECT_SOURCE_DIR}/src/network)

set(TARGET_NAME r-type_server)

# adding sub directory
add_subdirectory(exception)
add_subdirectory(initialization)

include(CompilerFlags)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)
target_link_libraries(${TARGET_NAME} Threads::Threads)

add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
