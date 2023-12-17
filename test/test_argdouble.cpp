#include <gtest/gtest.h>
#include <argparser.h>
#include <argdouble.h>
#include <typedef.h>

TEST(DoubleArgParserTest, AddArgumentTest) {
    ArgParser parser;

    // short and long command testing
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("doubleArg", "d", "--double", "Double argument test", 1.32));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("doubleArg", "-dd", "--double", "Double argument test", 1.32));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("doubleArg", "-d", "-double", "Double argument test", 1.32));

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("doubleArg", "-d", "--double", "Double argument test", 12.32));

    // should failed because cant override the argument 
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("doubleArg",    "-d", "--double", "Double argument test", 1.32));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("doubleArgNew", "-d", "--double", "Double argument test", 1.32));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("doubleArgNew", "-a", "--double", "Double argument test", 1.32));
}


TEST(DoubleArgParserTest, DoubleArgumentSCMDTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"--other", (char*)"10.23"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("doubleArg", "-d", "--double", "Double argument test", 45.34));

    // get value should be default value
    ASSERT_EQ(parser.get<double>("doubleArg"), 45.34);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_EQ(parser.get<double>("doubleArg"), 45.34);
    ASSERT_NE(parser.get<double>("doubleArg"), 10.23);
}

TEST(DoubleArgParserTest, DoubleArgumentSCMDFalseTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"--double", (char*)"50.34"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("doubleArg", "-d", "--double", "Double argument test", 45.34));

    // get value should be default value
    ASSERT_EQ(parser.get<double>("doubleArg"), 45.34);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_NE(parser.get<double>("doubleArg"), 45.34);
    ASSERT_EQ(parser.get<double>("doubleArg"), 50.34);
}


