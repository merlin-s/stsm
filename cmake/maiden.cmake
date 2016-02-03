
cmake_minimum_required(VERSION 3.3)

# maiden_project
# maiden_executable
# maiden_library

function(maiden_project project version)
    if(NOT maidenv_toplevel)
        message("maiden top level project: " ${project})
        set(maidenv_toplevel ${project} PARENT_SCOPE)
    else()
        if(target STREQUAL maidenv_toplevel)
          message("maiden: called maiden_project twice for target: ${project}")
          return()
        endif()
        message("maiden sub level project: " ${project})
    endif()
    message("build type: " ${CMAKE_BUILD_TYPE})
    project(${project} VERSION ${version} LANGUAGES ${ARGVN})
endfunction()

function(maiden_target target)
  string(LENGTH "${CMAKE_BUILD_TYPE}" build_type_length)
  if( build_type_length GREATER 0)
    set_target_properties( ${target}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE}"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}"
    )
    target_include_directories(${target} PUBLIC "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/include")
  else()
    set_target_properties( ${target}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
  endif()
  target_include_directories(${target} PUBLIC "${CMAKE_BINARY_DIR}/include")
  aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}/src" sources)
  #add_dependencies(${target} ${sources})
endfunction()

function(maiden_executable target)
  aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}/src" sources)
  add_executable(${target} ${sources})
  maiden_target(${target})
endfunction()

function(maiden_library target type)
  aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}/src" sources)
  add_library(${target} ${sources})
  maiden_target(${target})
endfunction()

function(maiden_imported_library target type path)
  add_library(${target} IMPORTED GLOBAL)
endfunction()
