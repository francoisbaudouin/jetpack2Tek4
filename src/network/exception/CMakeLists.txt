set(INCROOT ${INCROOT}/network/exception)
set(SRCROOT ${SRCROOT}/network/exception)

set(SRC
    ${SRC}
    ${SRCROOT}/Exception.cpp
    ${SRCROOT}/Exception.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE)
