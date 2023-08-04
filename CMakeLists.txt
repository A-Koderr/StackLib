cmake_minimum_required(VERSION 3.27)
project(stack VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_subdirectory(src)
add_subdirectory(tests)