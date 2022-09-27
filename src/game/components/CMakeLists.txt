set(INCROOT ${INCROOT}/components)
set(SRCROOT ${SRCROOT}/components)

set(SRC
    ${SRC}
    ${SRCROOT}/Controllable.cpp
    ${SRCROOT}/Position.cpp
    ${SRCROOT}/Drawable.cpp
    ${SRCROOT}/Velocity.cpp
    ${SRCROOT}/IComponent.cpp
    ${SRCROOT}/AComponent.cpp
    PARENT_SCOPE
)
