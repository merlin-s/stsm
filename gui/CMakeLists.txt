maiden_project(gui 1 CXX)


set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
include(FindSFML)
find_package(SFML 2 REQUIRED system window graphics) #network audio

set(target stsm-gui)
maiden_library(${target} src)
qt5_use_modules(${target} Core Widgets)
target_link_libraries(${target} PUBLIC stsm-util)
target_link_libraries(${target} PUBLIC ${SFML_LIBRARIES})
target_include_directories(${target} PUBLIC ${SFML_INCLUDE_DIR})
target_compile_features(${target} PUBLIC cxx_override)
