set(INCROOT ${INCROOT}/client)
set(SRCROOT ${SRCROOT}/client)

set(SRC
    ${SRC}
    ${SRCROOT}/Client.cpp
    ${SRCROOT}/Client.hpp
    PARENT_SCOPE
)

set(INCDIRS
    ${INCDIRS}
    ${INCROOT}
    PARENT_SCOPE
)
