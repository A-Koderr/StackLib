cmake_minimum_required(VERSION 3.27)
project(
    StackLib
    VERSION 0.1.0 
    LANGUAGES C
    )

set(CMAKE_INSTALL_PREFIX "/home/ars/Source Code/StackLib_package")

add_subdirectory(src)

include(CTest)
enable_testing()
add_subdirectory(tests)

install(TARGETS Stack 
    EXPORT StackTargets
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
    )

install(EXPORT StackTargets
    FILE StackTargets.cmake
    DESTINATION lib/cmake/Stack
    )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "StackConfigVersion.cmake"
    COMPATIBILITY AnyNewerVersion)

install(FILES "StackConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/StackConfigVersion.cmake"
    DESTINATION lib/cmake/Stack)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include" DESTINATION .)