set(INCROOT ${PROJECT_SOURCE_DIR}/src/game)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/game)

# adding subb diirectory
# Exemple: add_subdirectory(connexion)
set(TARGET_NAME r-type_client)

set(SRC
  ${SRC}
  ${SRCROOT}/SparseArray.cpp
  ${SRCROOT}/SparseArray.hpp
  ${SRCROOT}/Registery.cpp
  ${SRCROOT}/Registery.hpp
)

set(INCDIRS ${INCROOT})

add_subdirectory(components)

include(CompilerFlags)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp
                              ${SRCROOT}/SparseArray.cpp
                              ${INCROOT}/SparseArray.hpp
                              ${SRCROOT}/Registery.cpp
                              ${INCROOT}/Registery.hpp)

add_custom_command(TARGET ${TARGET_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})
