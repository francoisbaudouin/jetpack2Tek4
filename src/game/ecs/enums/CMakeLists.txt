set(INCROOT ${INCROOT}/enums)
set(SRCROOT ${SRCROOT}/enums)

set(SRC
    ${SRC}
    ${SRCROOT}/event.hpp
    ${SRCROOT}/controlls.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
