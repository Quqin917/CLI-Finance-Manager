cmake_minimum_required(VERSION 3.20)

## Establish Project ##

project(financialManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

## Set Executable file to be in build root

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

## Check and Set Machine Operating System

if(WIN32)
  set(window TRUE)
  message(STATUS ">>> Window")
endif()

if(UNIX)
  set(linux TRUE)
  message(STATUS ">>> Linux")
endif()

## Establish print Function ##

function(print var)
  message("${var} = ${${var}}") 
endfunction()


## Establish function to fetch library ##

include(FetchContent)

function(fetchLibrary lib_name lib_link lib_version )
  FetchContent_Declare(${lib_name} 
    GIT_REPOSITORY ${lib_link}
    GIT_TAG ${lib_version}
  )
  FetchContent_MakeAvailable(${lib_name})
endfunction()

## Set Custom Variable

set(libraryIncludeFolder ${CMAKE_CURRENT_SOURCE_DIR}/library/inc)
set(library_name myLibrary)
set(main_executable finman)

## Set Library Subdirectory

add_subdirectory(library)

## Set Source Subdirectory

add_subdirectory(source)

## Set External Library Subdirectory

add_subdirectory(external)