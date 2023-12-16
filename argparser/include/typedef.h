#ifndef _ARGPARSER_TYPEDEFS_H_
#define _ARGPARSER_TYPEDEFS_H_

#define UNUSED(x) static_cast<void>(arg)

typedef enum{
    /* success status*/
    PARSER_OK  = 0,

    /* error status*/
    PARSER_ERROR = -1,
    PARSER_INPUT_VALID_ERROR = -2,
    PARSER_ARG_VALUE_NOT_FOUND = -3,
    PARSER_INVALID_ARGUMENT = -4,
    PARSER_OUT_OF_RANGE = -5,

    /* redefinitions */
    PARSER_ARG_FOUND     = PARSER_OK,
    PARSER_ARG_NOT_FOUND = PARSER_ERROR,
} ArgStatus;

typedef enum{
    ARG_NONE_TYPE,
    ARG_FLAG_TYPE,
    ARG_INT_TYPE,
    ARG_DOUBLE_TYPE,
    ARG_STRING_TYPE,
    ARG_PATH_TYPE
} ArgType;

#endif // !_ARGPARSER_TYPEDEFS_H_