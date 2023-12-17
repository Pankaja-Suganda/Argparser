#include <argdouble.h>
#include <typedef.h>
#include <stdexcept>

DoubleArgument::DoubleArgument(const string& _name, const string& _shortcmd,  const string& _longcmd, const string& _help, double defaultval) 
    : Argument(_name, _shortcmd, _longcmd, _help, true), 
        defaultvalue(defaultval), value(defaultval){

}

ArgStatus DoubleArgument::loadValue(const string& arg, int pos){

    found();

    if(pos > 0 ){
        setArgPosition(pos);

        try{
            value = stod(arg);
            printf("Float Value: %f\n", value);
            return PARSER_OK;
        } catch (const std::invalid_argument& e) {
            fprintf(stderr, "Error: %s is not a valid float.\n", arg.c_str());
            return PARSER_INVALID_ARGUMENT;
        } catch (const std::out_of_range& e) {
            fprintf(stderr, "Error: %s is out of the range of float.\n", arg.c_str());
            return PARSER_OUT_OF_RANGE;
        }
    }

    return PARSER_ERROR;
}

ArgType DoubleArgument::getType() const{ 
    return ARG_DOUBLE_TYPE;
}

double DoubleArgument::getValue() const{
    return value;
}