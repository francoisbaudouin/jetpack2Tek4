set(INCROOT ${INCROOT}/systems)
set(SRCROOT ${SRCROOT}/systems)

set(SRC
    ${SRC}
    ${SRCROOT}/Display.cpp
    ${SRCROOT}/Display.hpp
    ${SRCROOT}/Move.cpp
    ${SRCROOT}/Move.hpp
    ${SRCROOT}/ASystem.cpp
    ${SRCROOT}/ASystem.hpp
    ${SRCROOT}/ISystem.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
