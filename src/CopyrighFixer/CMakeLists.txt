#
# Copyright (C) 2020-2021 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.14)

add_definitions(-DCopyrighFixer_LIBRARY)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

file(GLOB SOURCE_CPP
    "*.cpp" "*.qrc"
    "CopyrighFixer/*.cpp" "CopyrighFixer/*.qrc"
    "CopyrighFixer/Private/*.cpp" "CopyrighFixer/Private/*.qrc"
)

set(PUBLIC_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(PRIVATE_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Private")


add_library(${PROJECT_NAME} ${SOURCE_CPP})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(${PROJECT_NAME} PUBLIC QuasarApp)


target_include_directories(${PROJECT_NAME} PUBLIC ${PUBLIC_INCUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${PRIVATE_INCUDE_DIR})

set(LANGS ${CMAKE_CURRENT_SOURCE_DIR}/languages/en.ts)


prepareQM(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR} "${LANGS}")

setVersion(0 0 1)

set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE STRING "Qt Creator extra qml import paths")

