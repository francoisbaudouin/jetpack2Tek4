set(INCROOT ${PROJECT_SOURCE_DIR}/src/client)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/client)

# adding subb diirectory
# Exemple: add_subdirectory(connexion)
set(TARGET_NAME r-type_client)
find_package(Threads REQUIRED)

set(SRC
  ${SRC}
  ${SRCROOT}/Client.cpp
  ${INCROOT}/Client.hpp
)

set(INCDIRS ${INCROOT})
set_property(TARGET ${TARGET} PROPERTY MSVC_RUNTIME_LIBRARY "")

add_subdirectory(ecs)

include(CompilerFlags)

include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp ${SRC})

target_link_libraries(${TARGET_NAME} CONAN_PKG::sfml)

#target_link_libraries(${TARGET_NAME} sfml-audio sfml-graphics sfml-network sfml-system)
target_link_libraries(${TARGET_NAME} Threads::Threads)

add_custom_command(TARGET ${TARGET_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
