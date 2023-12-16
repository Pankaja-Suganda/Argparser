#ifndef _ARGFLAG_H_
#define _ARGFLAG_H_

#include <argument.h>

class FlagArgument : public Argument{
    public:
        FlagArgument(const string& _name, const string& _shortcmd,  const string& _longcmd, const string& _help, bool defaultval);
        ~FlagArgument() = default;

        ArgStatus loadValue(const string& arg, int pos) override;
        ArgType getType() const override;
        // int getValue() const override;


    private:
        bool defaultvalue;
        bool value;
};

#endif // !_ARGFLAG_H_

