## Establish Library ##

## Set Custom Variable

set(libraryFiles
  src/input_output.cpp
  src/commandOption.cpp
  src/hash.cpp
  src/user.cpp
)

## Establish library ##

add_library(${library_name} STATIC ${libraryFiles})

## Target include directory

target_include_directories(${library_name} 
PUBLIC
  ${libraryIncludeFolder}
)
