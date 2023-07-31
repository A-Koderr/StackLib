include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(test01 test01.c)
target_link_libraries(test01 stack)