cmake_minimum_required(VERSION 3.20)

## Establish Project ##

project(financialManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set Executable file to be in build root
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

## Establish print Function ##

function(print var)
  message("${var} = ${${var}}") 
endfunction()

## Set Custom Variable ##

set(libraryIncludeFolder ${CMAKE_CURRENT_SOURCE_DIR}/library/inc)
set(library_name myLibrary)
set(main_executable finman)

## Set Library Subdirectory ##

add_subdirectory(library)
add_subdirectory(external)


## Set Source Subdirectory ##

add_subdirectory(source)

print(PROJECT_NAME)