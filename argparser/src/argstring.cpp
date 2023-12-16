#include <argstring.h>
#include <typedef.h>

StringArgument::StringArgument(const string& _name, const string& _shortcmd,  const string& _longcmd, const string& _help, const string& defaultval) 
    : Argument(_name, _shortcmd, _longcmd, _help, true), 
        defaultvalue(defaultval){

}

ArgStatus StringArgument::loadValue(const string& arg, int pos){

    found();

    if(pos > 0 ){
        setArgPosition(pos);

        if(!arg.empty()){
            value = arg;
            printf("String Value: %s\n", value.c_str());
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