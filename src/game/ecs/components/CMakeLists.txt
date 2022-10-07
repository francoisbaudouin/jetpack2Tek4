set(INCROOT ${INCROOT}/components)
set(SRCROOT ${SRCROOT}/components)

set(SRC
    ${SRC}
    ${SRCROOT}/AComponent.cpp
    ${SRCROOT}/AComponent.hpp
    ${SRCROOT}/Drawable.cpp
    ${SRCROOT}/Drawable.hpp
    ${SRCROOT}/IComponent.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
