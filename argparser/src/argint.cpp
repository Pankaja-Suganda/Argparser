#include <argint.h>
#include <typedef.h>
#include <stdexcept>

IntArgument::IntArgument(const string& _name, const string& _shortcmd,  const string& _longcmd, const string& _help, int defaultval) 
    : Argument(_name, _shortcmd, _longcmd, _help, true), 
        defaultvalue(defaultval){

}

ArgStatus IntArgument::loadValue(const string& arg, int pos){

    found();

    if(pos > 0 ){
        setArgPosition(pos);

        try{
            value = stoi(arg);
            printf("Int Value: %d\n", value);
            return PARSER_OK;
        } catch (const std::invalid_argument& e) {
            fprintf(stderr, "Error: %s is not a valid integer.\n", arg.c_str());
            return PARSER_INVALID_ARGUMENT;
        } catch (const std::out_of_range& e) {
            fprintf(stderr, "Error: %s is out of the range of int.\n", arg.c_str());
            return PARSER_OUT_OF_RANGE;
        }
    }

    return PARSER_ERROR;
}

ArgType IntArgument::getType() const{ 
    return ARG_INT_TYPE;
}