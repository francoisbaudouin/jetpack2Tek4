set(INCROOT ${INCROOT}/scenes)
set(SRCROOT ${SRCROOT}/scenes)

set(SRC
    ${SRC}
    ${SRCROOT}/AScene.cpp
    ${INCROOT}/AScene.hpp
    ${INCROOT}/IScene.hpp
    ${INCROOT}/SceneSystem.cpp
    ${INCROOT}/SceneSystem.hpp
    ${INCROOT}/SceneManager.cpp
    ${INCROOT}/SceneManager.hpp
    ${INCROOT}/GameScene.cpp
    ${INCROOT}/GameScene.hpp
    ${INCROOT}/MainMenu.cpp
    ${INCROOT}/MainMenu.hpp
    ${INCROOT}/Hub.cpp
    ${INCROOT}/Hub.hpp
    ${INCROOT}/Lobby.cpp
    ${INCROOT}/Lobby.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
