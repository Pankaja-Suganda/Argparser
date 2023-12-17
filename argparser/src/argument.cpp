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

Argument::Argument(const string& _name, const string& _shortcmd, const string& _longcmd, const string& _help, bool _hasvalue)
    :   name(_name), 
        shortcmd(_shortcmd), 
        longcmd(_longcmd), 
        help(_help), 
        existing(false),
        hasvalue(_hasvalue),
        argpos(DEFAULT_ARGPOS){

}

string Argument::getName() const {
    return name;
}

string Argument::getShortCmd() const {
    return shortcmd;
}

string Argument::getLongCmd() const {
    return longcmd;
}

void Argument::setArgPosition(int position){
    argpos = position;
}

bool Argument::status(){
    return existing;
}

void Argument::found(){
    existing = true;
}

bool Argument::check(const string& arg) const{
    if (shortcmd == arg || longcmd == arg) {
        return true;
    }
    return false;
}

ArgStatus Argument::loadValue(const string& arg, int pos){
    return PARSER_OK;
}



