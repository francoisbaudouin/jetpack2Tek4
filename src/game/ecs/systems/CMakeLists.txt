set(INCROOT ${INCROOT}/systems)
set(SRCROOT ${SRCROOT}/systems)

set(SRC
    ${SRC}
    ${SRCROOT}/ASystem.cpp
    ${SRCROOT}/ASystem.hpp
    ${SRCROOT}/Display.cpp
    ${SRCROOT}/Display.hpp
    ${SRCROOT}/ISystem.hpp

    # ${SRCROOT}/Move.cpp
    # ${SRCROOT}/Move.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
