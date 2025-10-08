
/**
 * @file argint.h
 * @brief Declaration of IntArgument class for integer arguments.
 * @author Pankaja Suganda
 * @date 2025-10-07
 */
#ifndef _ARGINT_H_
#define _ARGINT_H_

#include <argument.h>

/**
 * @class IntArgument
 * @brief Argument type for integer values.
 *
 * Handles parsing and storing integer command-line arguments.
 */
class IntArgument : public Argument{
    public:
        /**
         * @brief Construct an IntArgument.
         * @param _name Argument name
         * @param _shortcmd Short command (e.g. "-n")
         * @param _longcmd Long command (e.g. "--number")
         * @param _help Help string describing the argument
         * @param defaultval Default value for the argument
         */
        IntArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, int defaultval);
        /** @brief Destructor. */
        ~IntArgument() = default;

        /**
         * @brief Load value from command-line input.
         * @param arg Argument string
         * @param pos Position in argv
         * @return Status code
         */
        ArgStatus loadValue(const std::string& arg, int pos) override;

        /**
         * @brief Get argument type.
         * @return ARG_INT_TYPE
         */
        ArgType getType() const override;

        /**
         * @brief Get integer value.
         * @return Value of argument
         */
        int getValue() const;
        
    private:
        int defaultvalue; /**< Default value. */
        int value;        /**< Current value. */
};

#endif // !_ARGINT_H_
