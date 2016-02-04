
cmake_minimum_required(VERSION 2.8)
include(cmake/maiden/maiden.cmake)
#cmake_policy(SET CMP0023 OLD)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
  message(STATUS "Defaulting to ${CMAKE_BUILD_TYPE} build")
endif()

maiden_project(stsm 1 CXX)
set(CMAKE_PREFIX_PATH /opt/qt/5.5/gcc_64)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(target ${PROJECT_NAME})
maiden_executable(${target} main.cpp)
#qt5_use_modules(${target} Core Widgets)
target_link_libraries(stsm PUBLIC stsm-gui stsm-game stsm-util)

add_subdirectory(game)
add_subdirectory(gui)
add_subdirectory(util)
