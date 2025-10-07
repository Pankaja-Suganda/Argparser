#ifndef _ARGINT_H_
#define _ARGINT_H_

#include <argument.h>

class IntArgument : public Argument{
    public:
        
        IntArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, int defaultval);
        ~IntArgument() = default;

        ArgStatus loadValue(const std::string& arg, int pos) override;
        ArgType getType() const override;
        
        int getValue() const;
        
    private:
        int defaultvalue;
        int value;
};

#endif // !_ARGINT_H_

