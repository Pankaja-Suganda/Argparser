
/**
 * @file argument.h
 * @brief Declaration of Argument base class for command-line arguments.
 * @author Pankaja Suganda
 * @date 2025-10-07
 */
#ifndef _ARGUMENT_H_
#define _ARGUMENT_H_

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <typedef.h>

/**
 * @class Argument
 * @brief Base class for command-line arguments.
 *
 * Provides common interface and storage for argument properties and parsing.
 */
class Argument{
    public:
        /**
         * @brief Default constructor.
         */
        Argument();

        /**
         * @brief Construct an Argument with details.
         * @param _name Argument name
         * @param _shortcmd Short command (e.g. "-n")
         * @param _longcmd Long command (e.g. "--name")
         * @param _help Help string describing the argument
         * @param _hasvalue True if argument expects a value
         */
        Argument(const std::string& _name, const std::string& _shortcmd, const std::string& _longcmd, const std::string& _help, bool _hasvalue);

        /** @brief Virtual destructor. */
        virtual ~Argument() = default;

        /**
         * @brief Get argument type.
         * @return Argument type enum
         */
        virtual ArgType getType() const = 0;

        /**
         * @brief Load value from command-line input.
         * @param arg Argument string
         * @param pos Position in argv
         * @return Status code
         */
        virtual ArgStatus loadValue (const std::string& arg, int pos) ;

        /**
         * @brief Get argument status (found/set).
         * @return True if argument was set
         */
        bool status() const;

        /**
         * @brief Check if input matches this argument.
         * @param arg Input string
         * @return True if matches
         */
        bool check(const std::string& arg) const;

        /**
         * @brief Mark argument as found/set.
         */
        void found();

        /**
         * @brief Print argument details (for debugging).
         */
        void print() {
            printf("cmd: %s\t%s\t%s\targpos: %d\thasvalue: %d\texisting: %d \t Help:%s\n", 
                name.c_str(), 
                shortcmd.c_str(), 
                longcmd.c_str(), 
                argpos, 
                hasvalue,
                existing,
                help.c_str()
                );
        }

        /** Get argument name. */
        std::string getName() const;
        /** Get short command string. */
        std::string getShortCmd() const;
        /** Get long command string. */
        std::string getLongCmd() const;
        /** Get help string. */
        std::string getHelp() const;
        /** Set argument position in argv. */
        void setArgPosition(int position);
        /** True if argument expects a value. */
        bool getHasValue() const;
    
    private:
        std::string name;      /**< Argument name. */
        std::string help;      /**< Help string. */
        std::string shortcmd;  /**< Short command. */
        std::string longcmd;   /**< Long command. */
        bool existing;         /**< True if argument was set. */
        int argpos;            /**< Position in argv. */
        bool hasvalue;         /**< True if argument expects a value. */
};

#endif // !_ARGUMENT_H_
