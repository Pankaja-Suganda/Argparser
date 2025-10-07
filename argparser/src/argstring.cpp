#include <argstring.h>
#include <typedef.h>

StringArgument::StringArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, const std::string& defaultval) 
    : Argument(_name, _shortcmd, _longcmd, _help, true), 
        defaultvalue(defaultval), value(defaultval){

}

ArgStatus StringArgument::loadValue(const std::string& arg, int pos){

    found();

    if(pos > 0 ){
        setArgPosition(pos);

        if(!arg.empty()){
            value = arg;
        }
        else{
            return PARSER_INVALID_ARGUMENT;
        }
    }

    return PARSER_ERROR;
}

ArgType StringArgument::getType() const{ 
    return ARG_STRING_TYPE;
}

std::string StringArgument::getValue() const{
    return value;
}