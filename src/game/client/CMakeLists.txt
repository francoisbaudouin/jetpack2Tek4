set(INCROOT ${INCROOT}/client)
set(SRCROOT ${SRCROOT}/client)

set(SRC
    ${SRC}
    ${SRCROOT}/Client.cpp
    ${SRCROOT}/Client.hpp
    ${SRCROOT}/data.hpp
    ${SRCROOT}/SpritesMap.cpp
    ${SRCROOT}/SpritesMap.hpp
    ${SRCROOT}/TextureDatabase.cpp
    ${SRCROOT}/TextureDatabase.hpp
    PARENT_SCOPE
)

add_subdirectory(scenes)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)