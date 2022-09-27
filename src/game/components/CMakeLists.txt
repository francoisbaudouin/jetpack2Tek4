set(INCROOT ${INCROOT}/components)
set(SRCROOT ${SRCROOT}/components)

set(SRC
    ${SRC}
    ${SRCROOT}/AComponent.cpp
    ${SRCROOT}/Controllable.cpp
    ${SRCROOT}/Position.cpp
    ${SRCROOT}/Drawable.cpp
    ${SRCROOT}/Velocity.cpp
    ${SRCROOT}/IComponent.cpp
    PARENT_SCOPE
)

SET(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
