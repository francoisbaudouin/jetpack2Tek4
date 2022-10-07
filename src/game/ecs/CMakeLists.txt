set(INCROOT ${INCROOT}/ecs)
set(SRCROOT ${SRCROOT}/ecs)

add_subdirectory(components)
add_subdirectory(entity)
add_subdirectory(systems)
add_subdirectory(exceptions)

set(SRC
  ${SRC}
  PARENT_SCOPE
)

set(INCDIRS
  ${INCDIRS}
  ${INCROOT}
  PARENT_SCOPE
)
