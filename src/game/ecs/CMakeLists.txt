set(INCROOT ${INCROOT}/ecs)
set(SRCROOT ${SRCROOT}/ecs)

set(SRC
    ${SRC}
    PARENT_SCOPE
)

add_subdirectory(components)
add_subdirectory(entity)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
