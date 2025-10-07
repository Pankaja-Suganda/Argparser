#ifndef _ARGSTRING_H_
#define _ARGSTRING_H_

#include <argument.h>

class StringArgument : public Argument{
    public:
        
        StringArgument(const std::string& _name, const std::string& _shortcmd,  const std::string& _longcmd, const std::string& _help, const std::string& defaultval);
        ~StringArgument() = default;

        ArgStatus loadValue(const std::string& arg, int pos) override;
        ArgType getType() const override;

        std::string getValue() const;

    private:
        std::string defaultvalue;
        std::string value;
};

#endif // !_ARGSTRING_H_

