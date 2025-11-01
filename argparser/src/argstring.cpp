#include <argstring.h>
#include <typedef.h>
#include <stdexcept>

StringArgument::StringArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, const std::string& defaultval) 
    : Argument(_name, _shortcmd, _longcmd, _help, true), 
        defaultvalue(defaultval), value(defaultval){

}

ArgStatus StringArgument::loadValue(const std::string& arg, int pos){

    found();

    if(pos > 0 ){
        setArgPosition(pos);

        if(!arg.empty()){
            try{
                value = arg;
                return PARSER_OK;
            }catch (const std::invalid_argument& e) {
                fprintf(stderr, "Error: Invalid string argument: %s (%s)\n", arg.c_str(), e.what());
                return PARSER_INVALID_ARGUMENT;
            }
            catch (const std::exception& e) {
                fprintf(stderr, "Unexpected error while parsing string: %s\n", e.what());
                return PARSER_ERROR;
            }
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