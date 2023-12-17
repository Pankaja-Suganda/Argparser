#include <gtest/gtest.h>
#include <argparser.h>
#include <argint.h>
#include <typedef.h>

TEST(IntArgParserTest, AddArgumentTest) {
    ArgParser parser;

    // short and long command testing
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("intArg", "i", "--int", "Int argument test", 32));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("intArg", "-ii", "--int", "Int argument test", 32));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("intArg", "-i", "-int", "Int argument test", 32));

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("intArg", "-i", "--int", "Int argument test", 43));

    // should failed because cant override the argument 
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("intArg",    "-i", "--int", "Int argument test", 32));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("intArgNew", "-i", "--int", "Int argument test", 32));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("intArgNew", "-a", "--int", "Int argument test", 32));

}


TEST(IntArgParserTest, IntArgumentSCMDTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"--other", (char*)"50"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("intArg", "-i", "--int", "Int argument test", 45));

    // get value should be default value
    ASSERT_EQ(parser.get<int>("intArg"), 45);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_EQ(parser.get<int>("intArg"), 45);
    ASSERT_NE(parser.get<int>("intArg"), 50);
}

TEST(IntArgParserTest, IntArgumentSCMDFalseTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"--int", (char*)"50"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("intArg", "-i", "--int", "Int argument test", 45));

    // get value should be default value
    ASSERT_EQ(parser.get<int>("intArg"), 45);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_NE(parser.get<int>("intArg"), 45);
    ASSERT_EQ(parser.get<int>("intArg"), 50);
}


