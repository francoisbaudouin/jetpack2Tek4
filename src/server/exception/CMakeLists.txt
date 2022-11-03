set(INCROOT ${INCROOT}/exception)
set(SRCROOT ${SRCROOT}/exception)

set(SRC
    ${SRC}
    ${SRCROOT}/Exception.cpp
    ${SRCROOT}/Exception.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE)
