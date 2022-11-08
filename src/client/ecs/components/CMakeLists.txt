set(INCROOT ${INCROOT}/components)
set(SRCROOT ${SRCROOT}/components)

set(SRC
    ${SRC}
    ${SRCROOT}/AComponent.cpp
    ${SRCROOT}/AComponent.hpp
    ${SRCROOT}/Controllable.cpp
    ${SRCROOT}/Controllable.hpp
    ${SRCROOT}/HitBox.cpp
    ${SRCROOT}/HitBox.hpp
    ${SRCROOT}/DrawableServerSide.cpp
    ${SRCROOT}/DrawableServerSide.hpp
    ${SRCROOT}/DrawableClientSide.cpp
    ${SRCROOT}/DrawableClientSide.hpp
    ${SRCROOT}/IComponent.hpp
    ${SRCROOT}/Position.cpp
    ${SRCROOT}/Position.hpp
    ${SRCROOT}/Velocity.cpp
    ${SRCROOT}/Velocity.hpp
    ${SRCROOT}/Weapon.cpp
    ${SRCROOT}/Weapon.hpp
    ${SRCROOT}/Type.cpp
    ${SRCROOT}/Type.hpp
    ${SRCROOT}/Controllable.cpp
    ${SRCROOT}/Controllable.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
