#ifndef _ARGFLAG_H_
#define _ARGFLAG_H_

#include <argument.h>

class FlagArgument : public Argument{
    public:
        FlagArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, bool defaultval);
        ~FlagArgument() = default;

        ArgStatus loadValue(const std::string& arg, int pos) override;
        ArgType getType() const override;

        bool getValue() const;

    private:
        bool defaultvalue;
        bool value;
};

#endif // !_ARGFLAG_H_

