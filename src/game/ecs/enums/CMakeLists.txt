set(INCROOT ${INCROOT}/enums)
set(SRCROOT ${SRCROOT}/enums)

set(SRC
    ${SRC}
    ${SRCROOT}/event.hpp
    ${SRCROOT}/controlls.hpp
    ${SRCROOT}/weapons.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
