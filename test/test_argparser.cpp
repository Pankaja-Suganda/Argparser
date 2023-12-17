#include <gtest/gtest.h>
#include <argparser.h>
#include <typedef.h>


// Test case for adding arguments
TEST(ArgParserTest, MainTest) {
    ArgParser parser;

    // Add a bool argument
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("boolArg", "-b", "--bool", "Bool argument", false));

    // Add an int argument
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("intArg", "-i", "--int", "Int argument", 12));

    // Add a double argument
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("doubleArg", "-d", "--double", "Double argument", 12.23));

    // Add a string argument
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("strArg", "-s", "--string", "String argument", "This is a string argument"));


    // check defaults
    ASSERT_EQ(parser.get<bool>("boolArg"),     false);
    ASSERT_EQ(parser.get<int>("intArg"),       12);
    ASSERT_EQ(parser.get<double>("doubleArg"), 12.23);
    ASSERT_EQ(parser.get<string>("strArg"),    "This is a string argument");

    // parsing
    // Valid command line arguments
    char* argv[] = { (char*)"program_name", 
        (char*)"--int", (char*)"123",             // Int Argument
        (char*)"--string", (char*)"Hello World",  // String Argument
        (char*)"--bool",                          // Bool Argument
        (char*)"--double", (char*)"65.343"};      // Double Argument
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // Check if values are correctly parsed
    ASSERT_EQ(parser.get<bool>("boolArg"),     true);
    ASSERT_EQ(parser.get<int>("intArg"),       123);
    ASSERT_EQ(parser.get<double>("doubleArg"), 65.343);
    ASSERT_EQ(parser.get<string>("strArg"),    "Hello World");

    // Check if arguments exist
    ASSERT_TRUE(parser.argExists("boolArg"));
    ASSERT_TRUE(parser.argExists("intArg"));
    ASSERT_TRUE(parser.argExists("doubleArg"));
    ASSERT_TRUE(parser.argExists("strArg"));
    ASSERT_FALSE(parser.argExists("nonExistentArg"));
    ASSERT_FALSE(parser.argExists("AnotherNonExistentArg"));

}

// Test case for parsing command line arguments
// TEST(ArgParser, Parse) {
//     ArgParser parser;

//     // Define arguments
//     parser.addArgument("intArg", "-i", "--integer", "Integer argument", 42);
//     parser.addArgument("strArg", "-s", "--string", "String argument", "default");

//     // Check if values are correctly parsed
//     ASSERT_EQ(42, parser.get<int>("intArg"));
//     ASSERT_EQ("default", parser.get<string>("strArg"));

//     // Valid command line arguments
//     char* argv[] = { (char*)"program_name", (char*)"-i", (char*)"99", (char*)"-s", (char*)"custom_string" };
//     int argc = sizeof(argv) / sizeof(argv[0]);

//     // Parse the arguments
//     ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

//     // Check if values are correctly parsed
//     ASSERT_EQ(99, parser.get<int>("intArg"));
//     ASSERT_EQ("custom_string", parser.get<string>("strArg"));
// }

// // Test case for finding arguments
// TEST(ArgParser, FindArgument) {
//     ArgParser parser;

//     // Add arguments
//     parser.addArgument("intArg", "-i", "--integer", "Integer argument", 42);
//     parser.addArgument("strArg", "-s", "--string", "String argument", "default");

//     // Find existing arguments
//     ASSERT_TRUE(parser.find("intArg") != nullptr);
//     ASSERT_TRUE(parser.find("strArg") != nullptr);

//     // Find non-existing argument
//     ASSERT_TRUE(parser.find("nonExistentArg") == nullptr);
// }

// // Test case for checking if an argument exists
// TEST(ArgParser, ArgumentExists) {
//     ArgParser parser;

//     // Add arguments
//     parser.addArgument("intArg", "-i", "--integer", "Integer argument", 42);
//     parser.addArgument("strArg", "-s", "--string", "String argument", "default");

//     // Check if arguments exist
//     ASSERT_TRUE(parser.argExists("intArg"));
//     ASSERT_TRUE(parser.argExists("strArg"));
//     ASSERT_FALSE(parser.argExists("nonExistentArg"));
// }

// Additional test cases can be added to cover edge cases, error handling, and other scenarios.
