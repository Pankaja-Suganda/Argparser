#ifndef _ARGINT_H_
#define _ARGINT_H_

#include <argument.h>

class IntArgument : public Argument{
    public:
        
        IntArgument(const string& _name, const string& _shortcmd,  const string& _longcmd, const string& _help, int defaultval);
        ~IntArgument() = default;

        ArgStatus loadValue(const string& arg, int pos) override;
        ArgType getType() const override;
        
        int getValue() const;
        
    private:
        int defaultvalue;
        int value;
};

#endif // !_ARGINT_H_

