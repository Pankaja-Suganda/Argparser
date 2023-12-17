#ifndef _ARGPARSER_H_
#define _ARGPARSER_H_

#include <string>
#include <vector>
#include <map>
#include <typedef.h>
#include <argument.h>

using namespace std;


class ArgParser {
public:
    ArgParser();
    ~ArgParser();

    template <typename T>
    ArgStatus addArgument(const string& name, const string& shortcmd, const string& longcmd, const string& help, T defaultval);

    template <typename V>
    V get(const string& name);

    ArgStatus parse(int argc, char* argv[]);
    ArgStatus execute();

    Argument* find(const string &name);

    void print(){
        for (const auto& argument : args) {
            argument.second->print();
        }
    }

    bool argExists(const string &name) const;
    
private:

    bool precheck(const string& name, const string& shortcmd, const string& longcmd);
    void postcheck();

    map<string, Argument*> args;
};

#endif // !_ARGPARSER_H_