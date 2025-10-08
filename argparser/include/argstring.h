
/**
 * @file argstring.h
 * @brief Declaration of StringArgument class for string arguments.
 * @author Pankaja Suganda
 * @date 2025-10-07
 */
#ifndef _ARGSTRING_H_
#define _ARGSTRING_H_

#include <argument.h>

/**
 * @class StringArgument
 * @brief Argument type for string values.
 *
 * Handles parsing and storing string command-line arguments.
 */
class StringArgument : public Argument{
    public:
        /**
         * @brief Construct a StringArgument.
         * @param _name Argument name
         * @param _shortcmd Short command (e.g. "-s")
         * @param _longcmd Long command (e.g. "--string")
         * @param _help Help string describing the argument
         * @param defaultval Default value for the argument
         */
        StringArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, const std::string& defaultval);
        /** @brief Destructor. */
        ~StringArgument() = default;

        /**
         * @brief Load value from command-line input.
         * @param arg Argument string
         * @param pos Position in argv
         * @return Status code
         */
        ArgStatus loadValue(const std::string& arg, int pos) override;

        /**
         * @brief Get argument type.
         * @return ARG_STRING_TYPE
         */
        ArgType getType() const override;

        /**
         * @brief Get string value.
         * @return Value of argument
         */
        std::string getValue() const;

    private:
        std::string defaultvalue; /**< Default value. */
        std::string value;        /**< Current value. */
};

#endif // !_ARGSTRING_H_
