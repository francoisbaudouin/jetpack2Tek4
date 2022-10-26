set(INCROOT ${PROJECT_SOURCE_DIR}/src/network)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/network)

# adding subb diirectory
add_subdirectory(initialization)

set(TARGET_NAME r-type_server)

include(CompilerFlags)

set_property(TARGET ${TARGET} PROPERTY MSVC_RUNTIME_LIBRARY "")

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)

add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
