set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(TARGET_NAME "TOBUORE")

project(${TARGET_NAME})

file(
    GLOB_RECURSE
    SOURCES
    "${PROJECT_ROOT_DIR}/source/*.cpp"
    "${PROJECT_ROOT_DIR}/source/*.c"
    "${PROJECT_ROOT_DIR}/source/*.hpp"
    "${PROJECT_ROOT_DIR}/source/*.h"
    )

include_directories(
    "${PROJECT_ROOT_DIR}/DxLib_VC"
    )

link_directories(
    "${PROJECT_ROOT_DIR}/DxLib_VC"
    )

if(MSVC)
    message(STATUS "Setting MSVC MT switches")
    set(
        CMAKE_CXX_FLAGS_DEBUG
        "-DDEBUG -D_DEBUG /MTd ${CMAKE_CXX_FLAGS_DEBUG}"
        CACHE STRING "MSVC MT flags " FORCE
        )

    set(
        CMAKE_CXX_FLAGS_RELEASE
        "-DNDEBUG /MT ${CMAKE_CXX_FLAGS_RELEASE}"
        CACHE STRING "MSVC MT flags " FORCE
        )
endif(MSVC)

add_executable(${TARGET_NAME} WIN32 ${SOURCES})
