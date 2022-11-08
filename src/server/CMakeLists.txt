set(INCROOT ${PROJECT_SOURCE_DIR}/src/server)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/server)

set(SRC
  ${SRC}
  ${SRCROOT}/Test.cpp
  ${INCROOT}/Test.hpp
)

set_property(TARGET ${TARGET} PROPERTY MSVC_RUNTIME_LIBRARY "")
set(TARGET_NAME r-type_server)

# adding subb diirectory
# add_subdirectory(initialization)


include(CompilerFlags)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp ${SRC})

add_custom_command(TARGET ${TARGET_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
