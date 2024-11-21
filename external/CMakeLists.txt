## Establish External Library ##

function(library)
  message(STATUS "Downloading ${ARGV0}")
  
  FetchContent_Declare(${ARGV0}
    GIT_REPOSITORY ${ARGV1}
    GIT_TAG ${ARGV2}
  )
  FetchContent_MakeAvailable(${ARGV0})

endfunction()
  
include(FetchContent)

find_package(nlohmann_json 3.11.3 QUIET)
if( NOT nlohmann_json_FOUND)
  library( nlohmann_json https://github.com/nlohmann/json.git v3.11.3 )

  target_include_directories(${library_name} 
  PRIVATE
    ${nlohmann_json_SOURCE_DIR}/include
  )
else()
  message(STATUS "nlohmann_json is AVAILABLE")
endif()