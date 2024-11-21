## Establish Main Executable ##

set(mainSource
  main.cpp
)

add_executable(${main_executable} ${mainSource})

## Target Library ##

target_include_directories(${main_executable}
PUBLIC
  "${PROJECT_BINARY_DIR}"
  "${libraryIncludeFolder}"
)

target_link_libraries(${main_executable} 
PRIVATE
  ${library_name}
  nlohmann_json::nlohmann_json
)