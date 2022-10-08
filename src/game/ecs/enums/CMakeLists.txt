set(INCROOT ${INCROOT}/enums)
set(SRCROOT ${SRCROOT}/enums)

set(SRC
    ${SRC}
    ${SRCROOT}/Event.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
