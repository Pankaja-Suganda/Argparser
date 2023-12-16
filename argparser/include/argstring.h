#ifndef _ARGSTRING_H_
#define _ARGSTRING_H_

#include <argument.h>

class StringArgument : public Argument{
    public:
        
        StringArgument(const string& _name, const string& _shortcmd,  const string& _longcmd, const string& _help, const string& defaultval);
        ~StringArgument() = default;

        ArgStatus loadValue(const string& arg, int pos) override;
        ArgType getType() const override;
        
        // int getValue() const override{
        //     return value;
        // }   
        
    private:
        string defaultvalue;
        string value;
};

#endif // !_ARGSTRING_H_

