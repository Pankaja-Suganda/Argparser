cmake_minimum_required(VERSION 3.12)
project(argument)

# Set the path to the Argparser module
set(ARGPARSER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/argparser")

# Add the Argparser module as a subdirectory
add_subdirectory(${ARGPARSER_DIR})

# Include directories for the current project
include_directories(
    ${ARGPARSER_DIR}/include
)

# Add the main.cpp file
add_executable(main main.cpp)

# Link the "argparser" library to the executable
target_link_libraries(main argparser)
