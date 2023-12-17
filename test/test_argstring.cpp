#include <gtest/gtest.h>
#include <argparser.h>
#include <argstring.h>
#include <typedef.h>

TEST(StringArgParserTest, AddArgumentTest) {
    ArgParser parser;

    // short and long command testing
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("stringArg", "s", "--string", "String argument test", "Hello World"));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("stringArg", "-ss", "--string", "String argument test", "Hello World"));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("stringArg", "-s", "-string", "String argument test", "Hello World"));

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("stringArg", "-s", "--string", "String argument test", "Hi there"));

    // should failed because cant override the argument 
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("stringArg",    "-s", "--string", "String argument test", "Hello World"));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("stringArgNew", "-s", "--string", "String argument test", "Hello World"));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("stringArgNew", "-a", "--string", "String argument test", "Hello World"));
}


TEST(StringArgParserTest, StringArgumentSCMDTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"--other", (char*)"Wrong argument"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("stringArg", "-s", "--string", "String argument test", "Default String"));

    // get value should be default value
    ASSERT_EQ(parser.get<string>("stringArg"), "Default String");

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_EQ(parser.get<string>("stringArg"), "Default String");
    ASSERT_NE(parser.get<string>("stringArg"), "Wrong argument");
}

TEST(StringArgParserTest, StringArgumentSCMDFalseTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"--string", (char*)"This is the correct string"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("stringArg", "-s", "--string", "String argument test", "Default String"));

    // get value should be default value
    ASSERT_EQ(parser.get<string>("stringArg"), "Default String");

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_NE(parser.get<string>("stringArg"), "Default String");
    ASSERT_EQ(parser.get<string>("stringArg"), "This is the correct string");
}

