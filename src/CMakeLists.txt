#
# Copyright (C) 2020-2021 QuasarApp.
# Distributed under the lgplv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.14)



set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(./QuasarAppLib/CMake/ProjectOut.cmake)
include(./QuasarAppLib/CMake/Version.cmake)
include(./QuasarAppLib/CMake/QtUtils.cmake)
include(./QuasarAppLib/CMake/crossplatform/crossplatform.cmake)

add_subdirectory(QuasarAppLib)
add_subdirectory(CFixer)
add_subdirectory(CopyrighFixer)

