set(INCROOT ${INCROOT}/components)
set(SRCROOT ${SRCROOT}/components)

set(SRC
    ${SRC}
    ${SRCROOT}/AComponent.cpp
    ${SRCROOT}/AComponent.hpp
    ${SRCROOT}/IComponent.hpp
    ${SRCROOT}/Position.cpp
    ${SRCROOT}/Position.hpp
    ${SRCROOT}/Velocity.cpp
    ${SRCROOT}/Velocity.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
