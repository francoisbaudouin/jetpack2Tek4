set(INCROOT ${INCROOT}/components)
set(SRCROOT ${SRCROOT}/components)

set(SRC
    ${SRC}
    ${SRCROOT}/AComponent.cpp
    ${INCROOT}/AComponent.hpp
    ${INCROOT}/IComponent.hpp
    ${SRCROOT}/Position.cpp
    ${INCROOT}/Position.hpp
    ${SRCROOT}/Velocity.cpp
    ${INCROOT}/Velocity.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
