set(SRCROOT ${SRCROOT}/config)
set(INCROOT ${INCROOT}/config)

set(SRC
    ${SRC}
    ${SRCROOT}/Loadconfig.cpp
    ${SRCROOT}/Loadconfig.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)