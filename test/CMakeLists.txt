
include(fetchContent)

fetchContent_Declare(
    googletest
    GIT_REPOSITORY   https://github.com/google/googletest.git
    GIT_TAG          release-1.11.0
)

fetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

include_directories(
    ${CMAKE_SOURCE_DIR}/argparser/include/
)

add_executable(argflag_test   test_argflag.cpp)
add_executable(argint_test    test_argint.cpp)
add_executable(argdouble_test test_argdouble.cpp)
add_executable(argstring_test test_argstring.cpp)
add_executable(argparser_test test_argparser.cpp)

target_link_libraries(argflag_test   GTest::GTest argparser)
target_link_libraries(argint_test    GTest::GTest argparser)
target_link_libraries(argdouble_test GTest::GTest argparser)
target_link_libraries(argstring_test GTest::GTest argparser)
target_link_libraries(argparser_test GTest::GTest argparser)

add_test(NAME argflag_test COMMAND argflag_test)
add_test(NAME argint_test COMMAND argint_test)
add_test(NAME argdouble_test COMMAND argdouble_test)
add_test(NAME argstring_test COMMAND argstring_test)
add_test(NAME argparser_test COMMAND argparser_test)