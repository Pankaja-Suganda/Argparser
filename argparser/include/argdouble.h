/**
 * @file argdouble.h
 * @brief Argument class for double values
 * @author A software programmer
 * @date 2025-10-07
 */
#ifndef _ARGDOUBLE_H_
#define _ARGDOUBLE_H_

#include <argument.h>



/**
 * @class DoubleArgument
 * @brief Argument type for double values.
 *
 * Handles parsing and storing double-precision command-line arguments.
 */
class DoubleArgument : public Argument{
    public:
        /**
         * @brief Construct a DoubleArgument.
         * @param _name Argument name
         * @param _shortcmd Short command (e.g. "-d")
         * @param _longcmd Long command (e.g. "--depth")
         * @param _help Help string describing the argument
         * @param defaultval Default value for the argument
         */
        DoubleArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, double defaultval);
        /** @brief Destructor. */
        ~DoubleArgument() = default;

        /**
         * @brief Load value from command-line input.
         * @param arg Argument string
         * @param pos Position in argv
         * @return Status code
         */
        ArgStatus loadValue(const std::string& arg, int pos) override;

        /**
         * @brief Get argument type.
         * @return ARG_DOUBLE_TYPE
         */
        ArgType getType() const override;

        /**
         * @brief Get double value.
         * @return Value of argument
         */
        double getValue() const;
        
    private:
        double defaultvalue; /**< Default value. */
        double value;        /**< Current value. */
};

#endif // !_ARGDOUBLE_H_
