set(INCROOT ${INCROOT}/entity)
set(SRCROOT ${SRCROOT}/entity)

set(SRC
    ${SRC}
    ${SRCROOT}/Entity.cpp
    ${SRCROOT}/Entity.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
