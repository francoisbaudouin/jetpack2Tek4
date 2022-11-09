set(INCROOT ${INCROOT}/systems)
set(SRCROOT ${SRCROOT}/systems)

set(SRC
    ${SRC}
    ${SRCROOT}/ASystem.cpp
    ${SRCROOT}/ASystem.hpp
    ${SRCROOT}/Collider.cpp
    ${SRCROOT}/Collider.hpp
    ${SRCROOT}/Controll.cpp
    ${SRCROOT}/Controll.hpp
    ${SRCROOT}/Display.cpp
    ${SRCROOT}/Display.hpp
    ${SRCROOT}/Input.cpp
    ${SRCROOT}/Input.hpp
    ${SRCROOT}/Controll.cpp
    ${SRCROOT}/Controll.hpp
    ${SRCROOT}/Fire.cpp
    ${SRCROOT}/Fire.hpp
    ${SRCROOT}/ColliderReaction.cpp
    ${SRCROOT}/ColliderReaction.hpp
    ${SRCROOT}/WriteInBox.hpp
    ${SRCROOT}/WriteInBox.cpp
    ${SRCROOT}/ISystem.hpp
    ${SRCROOT}/Move.cpp
    ${SRCROOT}/Move.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
