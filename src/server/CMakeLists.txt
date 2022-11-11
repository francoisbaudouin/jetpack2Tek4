set(INCROOT ${PROJECT_SOURCE_DIR}/src/server)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/server)

set(SRC
    ${SRC}
    ${ecs_dir}
    ${SRCROOT}/Communicator.cpp
    ${INCROOT}/Communicator.hpp
    ${SRCROOT}/Server.cpp
    ${INCROOT}/Server.hpp
    ${SRCROOT}/Test.cpp # à retirer avant de merge
    ${INCROOT}/Test.hpp # à retirer avant de merge
)

set_property(TARGET ${TARGET} PROPERTY MSVC_RUNTIME_LIBRARY "")
set(TARGET_NAME r-type_server)

# adding subb diirectory
# add_subdirectory(initialization)
find_package(Threads REQUIRED)
find_package(Boost REQUIRED)
include(CompilerFlags)

add_subdirectory(ecs)
add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp ${SRC})

target_link_libraries(${TARGET_NAME} PUBLIC CONAN_PKG::sfml)
target_link_libraries(${TARGET_NAME} PUBLIC Threads::Threads)
target_link_libraries(${TARGET_NAME} PUBLIC CONAN_PKG::asio)
target_link_libraries(${TARGET_NAME} PUBLIC CONAN_PKG::boost)

target_include_directories(${TARGET_NAME} PUBLIC
    ${CONAN_INCLUDE_DIRS_SFML}
    ${CONAN_INCLUDE_DIRS_BOOST}
    ${CONAN_INCLUDE_DIRS_ASIO}
)

add_custom_command(TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR})

include(${PROJECT_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)