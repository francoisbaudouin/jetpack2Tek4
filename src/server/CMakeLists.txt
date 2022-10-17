set(INCROOT ${PROJECT_SOURCE_DIR}/src/server)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/server)

set(SRC ${SRC})

# adding subb diirectory
add_subdirectory(initialization)

set(TARGET_NAME r-type_server)

include(CompilerFlags)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp ${SRC})

add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
