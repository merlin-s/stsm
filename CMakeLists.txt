
cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0023 OLD) #qt & cmake fucks up
cmake_policy(SET CMP0043 OLD) #qt5core fucks up

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
message("${CMAKE_MODULE_PATH}")
message("${CMAKE_MODULE_PATH}/maiden.cmake")
include(maiden/maiden)

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

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})

install(TARGETS stsm DESTINATION bin)
LIST(APPEND res_types fonts tex)
foreach(res_type IN LISTS res_types)
  FILE(GLOB_RECURSE resources res/${res_type}/*)
  install(FILES ${resources} DESTINATION res/${res_type})
endforeach(res_type)



add_subdirectory(game)
add_subdirectory(gui)
add_subdirectory(util)
