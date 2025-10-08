/**
 * @file argflag.h
 * @brief Declaration of FlagArgument class for boolean flag arguments.
 * @author Pankaja Suganda
 * @date 2025-10-07
 */
#ifndef _ARGFLAG_H_
#define _ARGFLAG_H_

#include <argument.h>

/**
 * @class FlagArgument
 * @brief Argument type for boolean flags.
 *
 * Handles parsing and storing boolean command-line arguments.
 */
class FlagArgument : public Argument{
    public:
        /**
         * @brief Construct a FlagArgument.
         * @param _name Argument name
         * @param _shortcmd Short command (e.g. "-v")
         * @param _longcmd Long command (e.g. "--verbose")
         * @param _help Help string describing the argument
         * @param defaultval Default value for the argument
         */
        FlagArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, bool defaultval);
        /** @brief Destructor. */
        ~FlagArgument() = default;

        /**
         * @brief Load value from command-line input.
         * @param arg Argument string
         * @param pos Position in argv
         * @return Status code
         */
        ArgStatus loadValue(const std::string& arg, int pos) override;

        /**
         * @brief Get argument type.
         * @return ARG_FLAG_TYPE
         */
        ArgType getType() const override;

        /**
         * @brief Get flag value.
         * @return True if flag was set
         */
        bool getValue() const;

    private:
        bool defaultvalue; /**< Default value. */
        bool value;        /**< Current value. */
};

#endif // !_ARGFLAG_H_
