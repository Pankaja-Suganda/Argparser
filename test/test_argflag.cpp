#include <gtest/gtest.h>
#include <argparser.h>
#include <argflag.h>
#include <typedef.h>

// Test case for adding arguments
TEST(FlagArgParserTest, AddArgumentTest) {
    ArgParser parser;

    // short and long command testing
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("boolArg", "b", "--bool", "Bool argument test", false));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("boolArg", "-bb", "--bool", "Bool argument test", false));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("boolArg", "-b", "-bool", "Bool argument test", false));

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("boolArg", "-b", "--bool", "Bool argument test", false));

    // should failed because cant override the argument 
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("boolArg",    "-b", "--bool", "Bool argument test", false));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("boolArgNew", "-b", "--bool", "Bool argument test", false));
    ASSERT_EQ(ArgStatus::PARSER_ADDING_FAILED, parser.addArgument("boolArgNew", "-a", "--bool", "Bool argument test", false));

}


TEST(FlagArgParserTest, FlagArgumentSCMDTrueTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"-b"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("boolArg", "-b", "--bool", "Bool argument test", false));

    // get value should be default value
    ASSERT_EQ(parser.get<bool>("boolArg"), false);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_EQ(parser.get<bool>("boolArg"), false);
}

TEST(FlagArgParserTest, FlagArgumentSCMDFalseTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"-b"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("boolArg", "-b", "--bool", "Bool argument test", false));

    // get value should be default value
    ASSERT_EQ(parser.get<bool>("boolArg"), false);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_EQ(parser.get<bool>("boolArg"), true);
}

TEST(FlagArgParserTest, FlagArgumentLCMDTrueTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"--append"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("boolArg", "-b", "--bool", "Bool argument test", false));

    // get value should be default value
    ASSERT_EQ(parser.get<bool>("boolArg"), false);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_EQ(parser.get<bool>("boolArg"), false);
}

TEST(FlagArgParserTest, FlagArgumentLCMDFalseTest) {
    ArgParser parser;

    // Valid command line arguments
    char* argv[] = { (char*)"program_name", (char*)"--bool"};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Add an argument with a default value
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.addArgument("boolArg", "-b", "--bool", "Bool argument test", false));

    // get value should be default value
    ASSERT_EQ(parser.get<bool>("boolArg"), false);

    // Parse the arguments
    ASSERT_EQ(ArgStatus::PARSER_OK, parser.parse(argc, argv));

    // get value should be default value
    ASSERT_EQ(parser.get<bool>("boolArg"), true);
}
