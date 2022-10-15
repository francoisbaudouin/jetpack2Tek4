set(INCROOT ${PROJECT_SOURCE_DIR}/src/game)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/game)

# adding subb diirectory
# Exemple: add_subdirectory(connexion)
set(TARGET_NAME r-type_client)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
set(SRC ${SRC})

set(INCDIRS ${INCROOT})

add_subdirectory(client)
add_subdirectory(ecs)

include(CompilerFlags)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp ${SRC})

target_link_libraries(${TARGET_NAME} sfml-audio sfml-graphics sfml-network sfml-system)

add_custom_command(TARGET ${TARGET_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
