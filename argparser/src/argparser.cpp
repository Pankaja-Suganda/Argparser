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
#define LONGCMD_STRING  "--"
#define SHORTCMD_STRING '-'

ArgParser::ArgParser() {

}

ArgParser::~ArgParser() {

}

bool ArgParser::precheck(
    const string& name, 
    const string& shortcmd, 
    const string& longcmd) {

    if(shortcmd[0] != SHORTCMD_STRING || shortcmd.length() != 2){
        return false;
    }

    if(longcmd.substr(0, 2) != LONGCMD_STRING){
        return false;
    }

    for (const auto& argument : args) {
        if( argument.second->getName() == name || 
            argument.second->getLongCmd()  == longcmd || 
            argument.second->getShortCmd() == shortcmd) {
            return false;
        }
    }

    return true;
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

    if (!precheck(name, shortcmd, longcmd)){
        return PARSER_ADDING_FAILED;
    }

    argument = new FlagArgument(name, shortcmd, longcmd, help, defaultval);

    args[name] = argument;

    return PARSER_OK;
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

    if (!precheck(name, shortcmd, longcmd)){
        return PARSER_ADDING_FAILED;
    }

    argument = new IntArgument(name, shortcmd, longcmd, help, defaultval);

    args[name] = argument;

    return PARSER_OK;
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

    if (!precheck(name, shortcmd, longcmd)){
        return PARSER_ADDING_FAILED;
    }

    argument = new DoubleArgument(name, shortcmd, longcmd, help, defaultval);

    args[name] = argument;

    return PARSER_OK;
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

    if (!precheck(name, shortcmd, longcmd)){
        return PARSER_ADDING_FAILED;
    }

    argument = new StringArgument(name, shortcmd, longcmd, help, defaultval);

    args[name] = argument;

    return PARSER_OK;
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

bool ArgParser::argExists(const string &name) const{
    auto temp =args.find(name);

    if(temp != args.end()) {
        return temp->second->status();
    }
}

template <>
int ArgParser::get<int>(const string& name) {
    auto temp =args.find(name);

    if(temp != args.end()) {
        if(temp->second->getType() != ARG_INT_TYPE){
            fprintf(stderr, "Error: no int argument for %s\n", name.c_str());
        }
        else{
            return dynamic_cast<IntArgument*>(temp->second)->getValue();
        }
    }

    return PARSER_ERROR;
}

template <>
bool ArgParser::get<bool>(const string& name) {
    auto temp =args.find(name);

    if(temp != args.end()) {
        if(temp->second->getType() != ARG_FLAG_TYPE){
            fprintf(stderr, "Error: no bool argument for %s\n", name.c_str());
        }
        else{
            return dynamic_cast<FlagArgument*>(temp->second)->getValue();
        }
    }

    return PARSER_ERROR;
}

template <>
double ArgParser::get<double>(const string& name) {
    auto temp =args.find(name);

    if(temp != args.end()) {
        if(temp->second->getType() != ARG_DOUBLE_TYPE){
            fprintf(stderr, "Error: no double argument for %s\n", name.c_str());
        }
        else{
            return dynamic_cast<DoubleArgument*>(temp->second)->getValue();
        }
    }

    return PARSER_ERROR;
}

template <>
string ArgParser::get<string>(const string& name) {
    auto temp =args.find(name);

    if(temp != args.end()) {
        if(temp->second->getType() != ARG_STRING_TYPE){
            fprintf(stderr, "Error: no string argument for %s\n", name.c_str());
        }
        else{
            return dynamic_cast<StringArgument*>(temp->second)->getValue();
        }
    }

    return nullptr;
}

// template class ArgParser::get<int>;
// template class ArgParser::get<bool>;
// template class ArgParser::get<double>;
// template class ArgParser::get<string>;