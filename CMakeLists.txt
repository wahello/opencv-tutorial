cmake_minimum_required (VERSION 3.20)

project(opencv_tutorial)

set(CMAKE_CXX_STANDARD 20)



# Included the conan build information
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()



add_subdirectory(01)
add_subdirectory(02)
add_subdirectory(03)
add_subdirectory(04)
add_subdirectory(05)
add_subdirectory(06)


