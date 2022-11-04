set(INCROOT ${INCROOT}/scenes)
set(SRCROOT ${SRCROOT}/scenes)

set(SRC
    ${SRC}
    ${SRCROOT}/AScene.cpp
    ${INCROOT}/AScene.hpp
    ${INCROOT}/IScene.hpp
    ${INCROOT}/SceneSystem.cpp
    ${INCROOT}/SceneSystem.hpp
    ${INCROOT}/GameScene.cpp
    ${INCROOT}/GameScene.hpp
    ${INCROOT}/MainMenu.cpp
    ${INCROOT}/MainMenu.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
