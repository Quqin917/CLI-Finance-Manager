## Establish External Library ##

## find nlohmann_json and if not exist install library 

find_package(nlohmann_json 3.11.3 QUIET)
if( NOT nlohmann_json_FOUND )
  message(STATUS "Fetching nlohmann_json library ...")
  
  fetchLibrary( nlohmann_json https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent v3.11.2 )
  list(APPEND external_include "${nlohmann_json_SOURCE_DIR}/single_include")

else()
  message(STATUS "nlohmann_json is AVAILABLE")
endif()

## loop throught list then include folder into library

foreach(lib IN LISTS external_include)
  
  target_include_directories(${library_name}
  PRIVATE
    ${lib}
  )
endforeach()