set(INCROOT ${INCROOT}/exceptions)
set(SRCROOT ${SRCROOT}/exceptions)

set(SRC
    ${SRC}
    ${SRCROOT}/Exception.cpp
    ${SRCROOT}/Exception.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
