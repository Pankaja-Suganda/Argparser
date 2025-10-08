cmake_minimum_required(VERSION 3.16)
project(argparser)

# Set the path to the Argparser module
set(ARGPARSER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/argparser")
set(TEST_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/test")

set(TEST_ENABLE        OFF)
set(DOCS_CREATE_ENABLE ON)

if(TEST_ENABLE)
    # Add test-related configurations or dependencies here
    message(STATUS "Testing is enabled.")
    include(CTest)
    enable_testing()
    add_subdirectory(${TEST_DIR})
endif()

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


# -- Documentation target (Doxygen) --------------------------------------------------
if(DOCS_CREATE_ENABLE)
    find_package(Doxygen)
    
    if(DOXYGEN_FOUND)
        message(STATUS "Doxygen found - enabling documentation generation.")
        set(DOXYGEN_OUTPUT_DIR "${CMAKE_BINARY_DIR}/docs")
        # sources to document: library sources and public headers
        set(DOXYGEN_INPUT "${ARGPARSER_DIR}/include ${ARGPARSER_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

        add_custom_target(docs
            COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
        )

        # Check for doxybook2 before adding the Markdown conversion target
        find_program(DOXYBOOK2_EXECUTABLE doxybook2 PATHS "D:/Downloads/doxybook2-windows-win64-v1.5.0/bin" NO_DEFAULT_PATH)
        if(DOXYBOOK2_EXECUTABLE)
            message(STATUS "Found doxybook2: ${DOXYBOOK2_EXECUTABLE}")
            # Define the doxybook2 template path
            set(DOXYBOOK2_TEMPLATE_PATH "D:/Downloads/doxybook2-windows-win64-v1.5.0/templates")
            add_custom_target(docs_md
                COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_SOURCE_DIR}/docs/api_markdown"
                COMMAND ${DOXYBOOK2_EXECUTABLE} 
                    -i "${DOXYGEN_OUTPUT_DIR}/xml" 
                    -o "${CMAKE_CURRENT_SOURCE_DIR}/docs/api_markdown" 
                    --config "${CMAKE_CURRENT_SOURCE_DIR}/doxybook2.json"
                DEPENDS docs
                COMMENT "Converting Doxygen XML to Markdown with doxybook2"
                VERBATIM
            )
        endif()
    else()
        message(STATUS "Doxygen not found - 'docs' target will not be available.")
    endif()
endif()
