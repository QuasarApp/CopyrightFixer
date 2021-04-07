#
# Copyright (C) 2020-2021 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.14)
project(CopyrighFixer)
if(TARGET ${PROJECT_NAME})
  message("The ${PROJECT_NAME} arledy included in main Project")
  return()
endif()

set (QT_VERSION_MAJOR OFF)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Test QUIET)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Test QUIET)

include(./src/QuasarAppLib/CMake/ccache.cmake)
include(./src/QuasarAppLib/CMake/QuasarAppCITargets.cmake)

# Add sub directories
add_subdirectory(src)


if (NOT DEFINED COPYRIGHT_FIXER_TESTS)
    set(COPYRIGHT_FIXER_TESTS ON)

    if (DEFINED TARGET_PLATFORM_TOOLCHAIN)
        if (${TARGET_PLATFORM_TOOLCHAIN} STREQUAL "wasm32")
            set(COPYRIGHT_FIXER_TESTS OFF)
        endif()
    endif()

    if (ANDROID)
        set(COPYRIGHT_FIXER_TESTS OFF)
    endif()

    if (NOT QT_VERSION_MAJOR)
        set(COPYRIGHT_FIXER_TESTS OFF)
    endif()
endif()


if (COPYRIGHT_FIXER_TESTS)
    add_subdirectory(tests)
else()
    message("The ${PROJECT_NAME} tests is disabled.")
endif()

initAll()

addDoc(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)
addDeployFromCustomFile("CopyrighFixer" "${CMAKE_CURRENT_SOURCE_DIR}/Deploy/CopyrighFixer.json")
