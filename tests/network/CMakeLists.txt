set(SRCROOT ${SRCROOT}/network)

set(SRC
    ${SRCROOT}/tests_networks.cpp
)

#add_subdirectory(world)

jetpack2tek4_test(
    NAME jp_test_ecs
    DISPLAY_NAME "JetPack2tek4-network-init"
    SOURCES ${SRC}
)
