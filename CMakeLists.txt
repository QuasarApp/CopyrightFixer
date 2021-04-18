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

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)


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

endif()

if (NOT DEFINED COPYRIGHT_FIXER_TOOL)
    set(COPYRIGHT_FIXER_TOOL ON)
endif()


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(submodules/QuasarAppLib/CMake/ccache.cmake)
include(submodules/QuasarAppLib/CMake/QuasarAppCITargets.cmake)
include(submodules/QuasarAppLib/CMake/ProjectOut.cmake)
include(submodules/QuasarAppLib/CMake/Version.cmake)
include(submodules/QuasarAppLib/CMake/QtUtils.cmake)
include(submodules/QuasarAppLib/CMake/crossplatform/crossplatform.cmake)

add_subdirectory(submodules/QuasarAppLib)
add_subdirectory(src/CopyrighFixer)

if (COPYRIGHT_FIXER_TESTS)
    add_subdirectory(src/CFixer)
else()
    message("The CFixer tool is disabled.")
endif()

if (COPYRIGHT_FIXER_TESTS)
    add_subdirectory(tests)
else()
    message("The ${PROJECT_NAME} tests is disabled.")
endif()

initAll()

addDoc(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/doxygen.conf)
addDeployFromCustomFile("CopyrighFixer" "${CMAKE_CURRENT_SOURCE_DIR}/Deploy/CopyrighFixer.json")
