set(INCROOT ${INCROOT}/initialization)
set(SRCROOT ${SRCROOT}/initialization)

set(SRC
    ${SRC}
    ${SRCROOT}/Loadconfig.cpp
    ${SRCROOT}/Loadconfig.hpp
    ${SRCROOT}/configuration.cpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE)
