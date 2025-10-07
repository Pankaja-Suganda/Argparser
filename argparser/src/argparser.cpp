#include "argparser.h"
#include <argflag.h>
#include <argint.h>
#include <argdouble.h>
#include <argstring.h>
#include <string.h>
// #define VALIDATE_STRING(x) \
//     do { \
//         if (x.empty()) { \
//             std::cerr << "Error: Empty std::string passed to " << #x << std::endl; \
//             return PARSER_INPUT_VALID_ERROR;\
//         } \
//     } while (0)

#define VALIDATE_STRING(x)
#define LONGCMD_STRING  "--"
#define SHORTCMD_STRING '-'
#define LONG_HELPCMD    "--help"
#define SHORT_HELPCMD   "-h"

#define DEFAULT_PARSER_NAME        "Default Project Name"
#define DEFAULT_PARSER_DESCRIPTION "Default Project Description"


ArgParser::ArgParser()
    : name(DEFAULT_PARSER_NAME), description(DEFAULT_PARSER_DESCRIPTION){

}

ArgParser::ArgParser(const std::string& _name, const std::string& _description)
    : name(_name), description(_description){

}

ArgParser::~ArgParser() {

}

bool ArgParser::precheck(
    const std::string& name, 
    const std::string& shortcmd, 
    const std::string& longcmd) {

    if(shortcmd[0] != SHORTCMD_STRING || shortcmd.length() != 2){
        return false;
    }

    if(longcmd.substr(0, 2) != LONGCMD_STRING){
        return false;
    }

    if(longcmd == LONG_HELPCMD || shortcmd == SHORT_HELPCMD){
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

void ArgParser::help(){

    if (help_callback) {
        help_callback();
    }

    printf("%s\n\n", name.c_str());
    printf("DESCRIPTION:\n\t%s\n", description.c_str());

    printf("USAGE:\n");
    for (const auto& argument : args) {
        printf("\t%s, %s \t: %s\n", 
            argument.second->getShortCmd().c_str(), 
            argument.second->getLongCmd().c_str(),
            argument.second->getHelp().c_str());
    }

    printf("\n");
}

void ArgParser::disableDefaultHelp(){
    defaultHelp = false;
}

void ArgParser::setHelpCallback(const Callback& callback){
    help_callback = callback;
}

template <>
ArgStatus ArgParser::addArgument<bool>(
    const std::string& name, 
    const std::string& shortcmd, 
    const std::string& longcmd, 
    const std::string& help, 
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
    const std::string& name, 
    const std::string& shortcmd, 
    const std::string& longcmd, 
    const std::string& help, 
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
    const std::string& name, 
    const std::string& shortcmd, 
    const std::string& longcmd, 
    const std::string& help, 
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
    const std::string& name, 
    const std::string& shortcmd, 
    const std::string& longcmd, 
    const std::string& help, 
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

Argument* ArgParser::find(const std::string &name){
    for (const auto& argument : args) {
        if(argument.second->check(name)){
            return argument.second;
        }
    }
    return nullptr;
}

ArgStatus ArgParser::parse(int argc, char* argv[]){
    Argument* temp = nullptr;
    Argument* prev = nullptr;
    ArgStatus ret = PARSER_OK;

    if(defaultHelp){
        if(strcmp(argv[1], LONG_HELPCMD) == PARSER_OK || strcmp(argv[1], SHORT_HELPCMD) == PARSER_OK){
            help();
            return PARSE_DEFAULT_HELP_OK;
        }       
    }


    for (int i = 1; i < argc; ++i) { 
        temp = find(argv[i]);
        if(temp != nullptr && !temp->status() && ret == PARSER_OK) {

            if(temp->getType() == ARG_FLAG_TYPE){
                ret = temp->loadValue(argv[i], i);
            }
            else{
                if(i + 1 < argc){
                    ret = temp->loadValue(argv[i+1], i + 1);
                }
                else{
                    fprintf(stderr, "Error: no argument for %s\n", argv[i]);
                    return PARSER_ARG_VALUE_NOT_FOUND;
                }
            }
        }
        else{
            if((prev != nullptr && !(prev->getHasValue())) || 
               (temp == nullptr && prev == nullptr)   || 
                i == 1){
                fprintf(stderr, "Error: Unknown argument %s\n", argv[i]);
                ret = PARSER_ARG_UNKNOWN;
            }
        }

        prev = temp;
    }

    return ret;
}

bool ArgParser::argExists(const std::string &name) const{
    auto temp =args.find(name);

    if(temp != args.end()) {
        return temp->second->status();
    }

    return false;
}

template <>
int ArgParser::get<int>(const std::string& name) {
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
bool ArgParser::get<bool>(const std::string& name) {
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
double ArgParser::get<double>(const std::string& name) {
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
std::string ArgParser::get<std::string>(const std::string& name) {
    auto temp =args.find(name);

    if(temp != args.end()) {
        if(temp->second->getType() != ARG_STRING_TYPE){
            fprintf(stderr, "Error: no std::string argument for %s\n", name.c_str());
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
// template class ArgParser::get<std::string>;