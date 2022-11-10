set(INCROOT ${INCROOT}/assetsManager)
set(SRCROOT ${SRCROOT}/assetsManager)

set(SRC
  ${SRC}
  ${SRCROOT}/TextureDatabase.cpp
  ${INCROOT}/TextureDatabase.hpp
  ${SRCROOT}/AnimationDatabase.cpp
  ${INCROOT}/AnimationDatabase.hpp
  PARENT_SCOPE
)

set(INCDIRS
  ${INCDIRS}
  ${INCROOT}
  PARENT_SCOPE
)
