#ifndef _ARGDOUBLE_H_
#define _ARGDOUBLE_H_

#include <argument.h>

class DoubleArgument : public Argument{
    public:
        DoubleArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, double defaultval);
        ~DoubleArgument() = default;

        ArgStatus loadValue(const std::string& arg, int pos) override;
        ArgType getType() const override;
        
        double getValue() const;
        
    private:
        double defaultvalue;
        double value;
};

#endif // !_ARGDOUBLE_H_

