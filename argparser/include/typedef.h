
/**
 * @file typedef.h
 * @brief Common typedefs and enums for argument parser library.
 * @author Pankaja Suganda
 * @date 2025-10-07
 */
#ifndef _ARGPARSER_TYPEDEFS_H_
#define _ARGPARSER_TYPEDEFS_H_

/**
 * @def UNUSED(x)
 * @brief Macro to suppress unused variable warnings.
 */
#define UNUSED(x) static_cast<void>(arg)

/**
 * @enum ArgStatus
 * @brief Status codes for argument parsing and errors.
 */
typedef enum{
    PARSER_OK  = 0,                  /**< Success. */
    PARSE_DEFAULT_HELP_OK = 1,       /**< Help output triggered. */

    PARSER_ERROR = -1,               /**< General error. */
    PARSER_INPUT_VALID_ERROR = -2,   /**< Invalid input. */
    PARSER_ARG_VALUE_NOT_FOUND = -3, /**< Argument value missing. */
    PARSER_INVALID_ARGUMENT = -4,    /**< Invalid argument. */
    PARSER_OUT_OF_RANGE = -5,        /**< Value out of range. */
    PARSER_ADDING_FAILED = -6,       /**< Failed to add argument. */
    PARSER_ARG_UNKNOWN = -7,         /**< Unknown argument. */

    PARSER_ARG_FOUND     = PARSER_OK,    /**< Redefinition: found. */
    PARSER_ARG_NOT_FOUND = PARSER_ERROR  /**< Redefinition: not found. */
} ArgStatus;

/**
 * @enum ArgType
 * @brief Supported argument types.
 */
typedef enum{
    ARG_NONE_TYPE,    /**< No type. */
    ARG_FLAG_TYPE,    /**< Boolean flag. */
    ARG_INT_TYPE,     /**< Integer. */
    ARG_DOUBLE_TYPE,  /**< Double/float. */
    ARG_STRING_TYPE,  /**< String. */
    ARG_PATH_TYPE     /**< Path (not implemented). */
} ArgType;

#endif // !_ARGPARSER_TYPEDEFS_H_
