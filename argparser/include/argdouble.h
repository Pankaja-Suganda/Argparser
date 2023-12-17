#ifndef _ARGDOUBLE_H_
#define _ARGDOUBLE_H_

#include <argument.h>

class DoubleArgument : public Argument{
    public:
        DoubleArgument(const string& _name, const string& _shortcmd,  const string& _longcmd, const string& _help, double defaultval);
        ~DoubleArgument() = default;

        ArgStatus loadValue(const string& arg, int pos) override;
        ArgType getType() const override;
        
        double getValue() const;
        
    private:
        double defaultvalue;
        double value;
};

#endif // !_ARGDOUBLE_H_

