
project(binary_tree)

set(HEDEAR_FILES Binary_Tree.h)
set(SOURCE_FILES Binary_Tree.cpp)

add_library(libbinary_tree STATIC ${SOURCE_FILES})
target_include_directories(libbinary_tree PUBLIC .)

add_executable(binary_tree ${SOURCE_FILES} main.cpp)

target_link_libraries(binary_tree libbinary_tree)

