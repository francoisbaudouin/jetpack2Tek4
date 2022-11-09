set(INCROOT ${INCROOT}/entity)
set(SRCROOT ${SRCROOT}/entity)

set(SRC
    ${SRC}
    ${SRCROOT}/Entity.cpp
    ${SRCROOT}/Entity.hpp
    ${SRCROOT}/EntityManager.cpp
    ${SRCROOT}/EntityManager.hpp
    ${SRCROOT}/EntityGenerator.cpp
    ${SRCROOT}/EntityGenerator.hpp
    ${SRCROOT}/componentAdder.cpp
    ${SRCROOT}/componentAdder.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
