set(INCROOT ${INCROOT}/assetsManager)
set(SRCROOT ${SRCROOT}/assetsManager)

set(SRC
  ${SRC}
  ${SRCROOT}/TextureDatabase.cpp
  ${INCROOT}/TextureDatabase.hpp
  PARENT_SCOPE
)

set(INCDIRS
  ${INCDIRS}
  ${INCROOT}
  PARENT_SCOPE
)
