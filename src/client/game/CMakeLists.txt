set(INCROOT ${INCROOT}/game)
set(SRCROOT ${SRCROOT}/game)

set(SRC
    ${SRC}
    ${SRCROOT}/Timer.cpp
    ${INCROOT}/Timer.hpp
    ${SRCROOT}/EnemyWave.cpp
    ${INCROOT}/EnemyWave.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
