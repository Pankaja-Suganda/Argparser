#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include <string>
#include <vector>
#include <map>
#include <typedef.h>
#include <argument.h>

class ArgParser {
public:
    using Callback = std::function<void()>;

    ArgParser();
    ArgParser(const std::string& _name, const std::string& _description);
    ~ArgParser();

    template <typename T>
    ArgStatus addArgument(const std::string& name, const std::string& shortcmd, const std::string& longcmd, const std::string& help, T defaultval);

    template <typename V>
    V get(const std::string& name);

    ArgStatus parse(int argc, char* argv[]);
    ArgStatus execute(); 

    Argument* find(const std::string &name);

    void print(){
        for (const auto& argument : args) {
            argument.second->print();
        }
    }

    bool argExists(const std::string &name) const;
    void setHelpCallback(const Callback& callback);
    void disableDefaultHelp();
    
private:

    bool precheck(const std::string& name, const std::string& shortcmd, const std::string& longcmd);
    void postcheck();
    void help();

    Callback help_callback;
    std::map<std::string, Argument*> args; // Use std::map, not just map

    std::string name;
    std::string description;

    bool defaultHelp = true;
};

#endif // !_ARGPARSER_H_