#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include <string>
#include <vector>
#include <map>
#include "typedef.h"
#include "argument.h"

using namespace std;


class ArgParser {
public:
    ArgParser();
    ~ArgParser();

    template <typename T>
    ArgStatus addArgument(const string& name, const string& shortcmd, const string& longcmd, const string& help, T defaultval);

    template <typename T>
    void argprintf(T a);
    ArgStatus parse(int argc, char* argv[]);
    ArgStatus execute();
    Argument* find(const string &name);
    void print(){
        for (const auto& argument : args) {
            argument.second->print();
        }
    }

    ArgStatus hasOption(const string& option) const;
    map<string, Argument*> args;
private:

    void precheck();
    void postcheck();

    
    map<string, vector<string>> options;
};

#endif // !_ARGPARSER_H_