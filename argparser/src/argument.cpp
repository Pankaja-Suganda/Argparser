#include <argument.h>


#define DEFAULT_ARG_NAME "default"
#define DEFAULT_ARG_HELP "default help"
#define DEFAULT_ARG_SCMD "-default"
#define DEFAULT_ARG_LCDM "--default"

#define DEFAULT_ARGPOS 0

Argument::Argument()
    :   name(DEFAULT_ARG_NAME), 
        shortcmd(DEFAULT_ARG_SCMD), 
        longcmd(DEFAULT_ARG_LCDM), 
        help(DEFAULT_ARG_HELP), 
        existing(false) {

}

Argument::Argument(const std::string& _name, const std::string& _shortcmd, const std::string& _longcmd, const std::string& _help, bool _hasvalue)
    :   name(_name), 
        shortcmd(_shortcmd), 
        longcmd(_longcmd), 
        help(_help), 
        existing(false),
        hasvalue(_hasvalue),
        argpos(DEFAULT_ARGPOS){

}

std::string Argument::getName() const {
    return name;
}

std::string Argument::getShortCmd() const {
    return shortcmd;
}

std::string Argument::getLongCmd() const {
    return longcmd;
}

std::string Argument::getHelp() const {
    return help;
}

void Argument::setArgPosition(int position){
    argpos = position;
}

bool Argument::status() const{
    return existing;
}

void Argument::found(){
    existing = true;
}

bool Argument::check(const std::string& arg) const{
    if (shortcmd == arg || longcmd == arg) {
        return true;
    }
    return false;
}

ArgStatus Argument::loadValue(const std::string& arg, int pos){
    return PARSER_OK;
}

bool Argument::getHasValue() const{
    return hasvalue;
}


