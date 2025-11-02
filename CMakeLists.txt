cmake_minimum_required(VERSION 3.16)
project(argparser LANGUAGES CXX)

# ---------------------------------------------------------------------------
# Options
# ---------------------------------------------------------------------------

option(ARGPARSER_BUILD_MAIN "Build example main executable" OFF)
option(ARGPARSER_BUILD_TESTS "Enable building Argparser tests" OFF)
option(ARGPARSER_BUILD_DOCS "Enable documentation generation with Doxygen" OFF)

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------

set(ARGPARSER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/argparser")
set(TEST_DIR      "${CMAKE_CURRENT_SOURCE_DIR}/test")

# ---------------------------------------------------------------------------
# Library
# ---------------------------------------------------------------------------

add_subdirectory(${ARGPARSER_DIR})

# Include public headers
target_include_directories(argparser PUBLIC
    ${ARGPARSER_DIR}/include
)

# ---------------------------------------------------------------------------
# Example executable (main.cpp)
# ---------------------------------------------------------------------------

if(ARGPARSER_BUILD_MAIN)
    message(STATUS "Building Argparser example: main.cpp")
    add_executable(argparser_main main.cpp)
    target_link_libraries(argparser_main PRIVATE argparser)
endif()

# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------

if(ARGPARSER_BUILD_TESTS)
    message(STATUS "Building Argparser tests")
    include(CTest)
    enable_testing()
    add_subdirectory(${TEST_DIR})
endif()

# ---------------------------------------------------------------------------
# Documentation (Doxygen + Doxybook2)
# ---------------------------------------------------------------------------

if(ARGPARSER_BUILD_DOCS)
    find_package(Doxygen)

    if(DOXYGEN_FOUND)
        message(STATUS "Doxygen found - enabling documentation generation.")

        set(DOXYGEN_OUTPUT_DIR "${CMAKE_BINARY_DIR}/docs")
        set(DOXYGEN_INPUT
            "${ARGPARSER_DIR}/include"
            "${ARGPARSER_DIR}/src"
            "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
        )

        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
                       ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

        add_custom_target(docs
            COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
        )

        # Optional: Convert Doxygen XML to Markdown using Doxybook2
        find_program(DOXYBOOK2_EXECUTABLE doxybook2
            PATHS "D:/Downloads/doxybook2-windows-win64-v1.5.0/bin"
            NO_DEFAULT_PATH
        )

        if(DOXYBOOK2_EXECUTABLE)
            message(STATUS "Found Doxybook2: ${DOXYBOOK2_EXECUTABLE}")
            set(DOXYBOOK2_TEMPLATE_PATH
                "D:/Downloads/doxybook2-windows-win64-v1.5.0/templates"
            )

            add_custom_target(docs_md
                COMMAND ${CMAKE_COMMAND} -E make_directory
                        "${CMAKE_CURRENT_SOURCE_DIR}/docs/api_markdown"
                COMMAND ${DOXYBOOK2_EXECUTABLE}
                    -i "${DOXYGEN_OUTPUT_DIR}/xml"
                    -o "${CMAKE_CURRENT_SOURCE_DIR}/docs/api_markdown"
                    --config "${CMAKE_CURRENT_SOURCE_DIR}/doxybook2.json"
                DEPENDS docs
                COMMENT "Converting Doxygen XML to Markdown with Doxybook2"
                VERBATIM
            )
        endif()
    else()
        message(WARNING "Doxygen not found - 'docs' target disabled.")
    endif()
endif()
