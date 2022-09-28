set(INCROOT ${INCROOT}/components)
set(SRCROOT ${SRCROOT}/components)

set(SRC
    ${SRC}
    ${SRCROOT}/AComponent.cpp
    ${INCROOT}/AComponent.hpp
    ${SRCROOT}/Controllable.cpp
    ${INCROOT}/Controllable.hpp
    ${SRCROOT}/Position.cpp
    ${INCROOT}/Position.hpp
    ${SRCROOT}/Drawable.cpp
    ${INCROOT}/Drawable.hpp
    ${SRCROOT}/Velocity.cpp
    ${INCROOT}/Velocity.hpp
    ${SRCROOT}/IComponent.cpp
    ${INCROOT}/IComponent.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
