## Establish Main Executable ##

## Set Custom Variable

set(mainSource
  main.cpp
)

## Establish library ##

add_executable(${main_executable} ${mainSource})

## Target Library and include folder

target_include_directories(${main_executable}
PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${libraryIncludeFolder}"
)

target_link_libraries(${main_executable} 
PUBLIC
  ${library_name}
  nlohmann_json::nlohmann_json
)
