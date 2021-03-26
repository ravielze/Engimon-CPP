
project(MANA_TELAT_KEBURU_SEMPAT)

set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

 
include_directories(src/include)
  
file(GLOB LIB_SOURCE "src/src/lib/*.cpp")
add_library(engimon_lib STATIC ${LIB_SOURCE} src/src/utils.cpp)

file(GLOB TEST_FILE "src/src/test/*.cpp")

foreach(testsourcefile ${TEST_FILE})
    string( REPLACE ".cpp" "" testname ${testsourcefile} )
    get_filename_component(exename ${testname} NAME)
    add_executable( ${exename} ${testsourcefile} )
    target_link_libraries(${exename} engimon_lib)
endforeach( testsourcefile ${TEST_FILE} )

add_executable(Engimon src/src/main.cpp)

target_link_libraries(Engimon engimon_lib)