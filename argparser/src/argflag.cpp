#include <argflag.h>
#include <typedef.h>


FlagArgument::FlagArgument(const string& _name, const string& _shortcmd,  const string& _longcmd, const string& _help, bool defaultval) 
    : Argument(_name, _shortcmd, _longcmd, _help, false), 
        defaultvalue(defaultval), value(defaultval){

}

ArgStatus FlagArgument::loadValue(const string& arg, int pos){
    UNUSED(arg);
    
    found();

    if(pos > 0 ){
        setArgPosition(pos);
        value = true;
        return PARSER_OK;
    }

    return PARSER_ERROR;
}

ArgType FlagArgument::getType() const{ 
    return ARG_FLAG_TYPE;
}

bool FlagArgument::getValue() const{
    return value;
}