cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project("Maze Generator" CXX)

# Use C++14 for this project
set(CMAKE_CXX_STANDARD 14)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-deprecated -pedantic")
endif()

# glob all source files
file(GLOB_RECURSE source_files src/*.*pp)

# compile the main program
add_executable(main ${source_files})
target_link_libraries(
    main
    allegro allegro_main allegro_primitives
    )
