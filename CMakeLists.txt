cmake_minimum_required(VERSION 3.16)
project(argparser)

# Set the path to the Argparser module
set(ARGPARSER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/argparser")
set(TEST_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/test")

set(TEST_ENABLE   OFF)

if(TEST_ENABLE)
    # Add test-related configurations or dependencies here
    message(STATUS "Testing is enabled.")
    include(CTest)
    enable_testing()
    add_subdirectory(${TEST_DIR})
endif()


# Add the Argparser module as a subdirect ory
add_subdirectory(${ARGPARSER_DIR})

# Include directories for the current project
include_directories(
    ${ARGPARSER_DIR}/include
)

# Add the main.cpp file
add_executable(main main.cpp)

# Link the "argparser" library to the executable
target_link_libraries(main argparser)
