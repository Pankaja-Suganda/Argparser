#include "argparser.h"
#include <argflag.h>
#include <argint.h>
#include <argdouble.h>
#include <argstring.h>
// #define VALIDATE_STRING(x) \
//     do { \
//         if (x.empty()) { \
//             std::cerr << "Error: Empty string passed to " << #x << std::endl; \
//             return PARSER_INPUT_VALID_ERROR;\
//         } \
//     } while (0)

#define VALIDATE_STRING(x)

ArgParser::ArgParser() {

}

ArgParser::~ArgParser() {

}

void ArgParser::precheck(){

}

void ArgParser::postcheck(){

}

template <>
ArgStatus ArgParser::addArgument<bool>(
    const string& name, 
    const string& shortcmd, 
    const string& longcmd, 
    const string& help, 
    bool defaultval){
    Argument *argument = nullptr;

    VALIDATE_STRING(name);
    VALIDATE_STRING(shortcmd);
    VALIDATE_STRING(longcmd);
    VALIDATE_STRING(help);

    argument = new FlagArgument(name, shortcmd, longcmd, help, defaultval);

    args[name] = argument;
}

template <>
ArgStatus ArgParser::addArgument<int>(
    const string& name, 
    const string& shortcmd, 
    const string& longcmd, 
    const string& help, 
    int defaultval){
    Argument *argument = nullptr;

    VALIDATE_STRING(name);
    VALIDATE_STRING(shortcmd);
    VALIDATE_STRING(longcmd);
    VALIDATE_STRING(help);

    argument = new IntArgument(name, shortcmd, longcmd, help, defaultval);

    args[name] = argument;
}

template <>
ArgStatus ArgParser::addArgument<double>(
    const string& name, 
    const string& shortcmd, 
    const string& longcmd, 
    const string& help, 
    double defaultval){
    Argument *argument = nullptr;

    VALIDATE_STRING(name);
    VALIDATE_STRING(shortcmd);
    VALIDATE_STRING(longcmd);
    VALIDATE_STRING(help);

    argument = new DoubleArgument(name, shortcmd, longcmd, help, defaultval);

    args[name] = argument;
}

template <>
ArgStatus ArgParser::addArgument<char const*>(
    const string& name, 
    const string& shortcmd, 
    const string& longcmd, 
    const string& help, 
    const char* defaultval){
    Argument *argument = nullptr;

    VALIDATE_STRING(name);
    VALIDATE_STRING(shortcmd);
    VALIDATE_STRING(longcmd);
    VALIDATE_STRING(help);

    argument = new StringArgument(name, shortcmd, longcmd, help, defaultval);

    args[name] = argument;
}

Argument* ArgParser::find(const string &name){
    for (const auto& argument : args) {
        if(argument.second->check(name)){
            return argument.second;
        }
    }
    return nullptr;
}

ArgStatus ArgParser::parse(int argc, char* argv[]){
    Argument* temp = nullptr;
    ArgStatus ret = PARSER_ERROR;

    for (int i = 0; i < argc; ++i) { 
        temp = find(argv[i]);
        if(temp != nullptr && !temp->status()) {
            if(temp->getType() == ARG_FLAG_TYPE){
                ret = temp->loadValue(argv[i], i);
            }
            else{
                if(i + 1 < argc){
                    ret = temp->loadValue(argv[i+1], i);
                }
                else{
                    fprintf(stderr, "Error: no argument for %s\n", argv[i]);
                    return PARSER_ARG_VALUE_NOT_FOUND;
                }
            }
        }
    }

    return PARSER_OK;
}


template <>
void ArgParser::argprintf<int>(int a){
    printf("here int\n");
}

template <>
void ArgParser::argprintf<double>(double a){
    printf("here doule\n");
}