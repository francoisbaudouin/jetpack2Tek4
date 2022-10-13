set(INCROOT ${INCROOT}/client)
set(SRCROOT ${SRCROOT}/client)

set(SRC
    ${SRC}
    ${SRCROOT}/TextureDatabase.cpp
    ${SRCROOT}/TextureDatabase.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)