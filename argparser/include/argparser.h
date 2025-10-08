/**
 * @file argparser.h
 * @brief Declaration of ArgParser class for command-line argument parsing.
 * @author Pankaja Suganda
 * @date 2025-10-07
 */
#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include <string>
#include <vector>
#include <map>
#include <typedef.h>
#include <argument.h>

/**
 * @class ArgParser
 * @brief Command-line argument parser supporting multiple types and help output.
 *
 * Example usage:
 * @code
 * ArgParser parser("MyApp", "Description");
 * parser.addArgument("length", "-l", "--length", "Box length", 0.0);
 * parser.parse(argc, argv);
 * double len = parser.get<double>("length");
 * @endcode
 */
class ArgParser {
public:
    /** Callback type for custom help output. */
    using Callback = std::function<void()>;

    /**
     * @brief Default constructor.
     */
    ArgParser();

    /**
     * @brief Constructor with project name and description.
     * @param _name Project name
     * @param _description Project description
     */
    ArgParser(const std::string& _name, const std::string& _description);

    /**
     * @brief Destructor.
     */
    ~ArgParser();

    /**
     * @brief Add a command-line argument.
     * @tparam T Argument type (bool, int, double, std::string)
     * @param name Argument name
     * @param shortcmd Short command (e.g. "-l")
     * @param longcmd Long command (e.g. "--length")
     * @param help Help string
     * @param defaultval Default value
     * @return Status code
     */
    template <typename T>
    ArgStatus addArgument(const std::string& name, const std::string& shortcmd, const std::string& longcmd, const std::string& help, T defaultval);

    /**
     * @brief Get the value of an argument.
     * @tparam V Return type
     * @param name Argument name
     * @return Value of argument
     */
    template <typename V>
    V get(const std::string& name);

    /**
     * @brief Parse command-line arguments.
     * @param argc Argument count
     * @param argv Argument vector
     * @return Status code
     */
    ArgStatus parse(int argc, char* argv[]);

    /**
     * @brief Execute custom logic after parsing (optional).
     * @return Status code
     */
    ArgStatus execute();

    /**
     * @brief Find an argument by name or command string.
     * @param name Argument name or command
     * @return Pointer to Argument, or nullptr if not found
     */
    Argument* find(const std::string &name);

    /**
     * @brief Print all arguments and their status.
     */
    void print(){
        for (const auto& argument : args) {
            argument.second->print();
        }
    }

    /**
     * @brief Check if an argument exists and was set.
     * @param name Argument name
     * @return True if argument exists and was set
     */
    bool argExists(const std::string &name) const;

    /**
     * @brief Set a custom help callback.
     * @param callback Function to call for help output
     */
    void setHelpCallback(const Callback& callback);

    /**
     * @brief Disable default help output.
     */
    void disableDefaultHelp();

private:
    /**
     * @brief Check argument validity before adding.
     */
    bool precheck(const std::string& name, const std::string& shortcmd, const std::string& longcmd);

    /**
     * @brief Post-addition checks (internal).
     */
    void postcheck();

    /**
     * @brief Print help output.
     */
    void help();

    Callback help_callback; /**< Custom help callback. */
    std::map<std::string, Argument*> args; /**< Argument storage. */

    std::string name; /**< Project name. */
    std::string description; /**< Project description. */

    bool defaultHelp = true; /**< Enable default help output. */
};

#endif // !_ARGPARSER_H_
