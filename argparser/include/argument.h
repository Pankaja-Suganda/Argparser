#ifndef _ARGUMENT_H_
#define _ARGUMENT_H_

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <typedef.h>


class Argument{
    public:
        Argument();
        Argument(const std::string& _name, const std::string& _shortcmd, const std::string& _longcmd, const std::string& _help, bool _hasvalue);

        virtual ~Argument() = default;
        virtual ArgType getType() const = 0;
        virtual ArgStatus loadValue (const std::string& arg, int pos) ;
        
        bool status() const;
        bool check(const std::string& arg) const;
        void found();
        void print() {
            printf("cmd: %s\t%s\t%s\targpos: %d\thasvalue: %d\texisting: %d \t Help:%s\n", 
                name.c_str(), 
                shortcmd.c_str(), 
                longcmd.c_str(), 
                argpos, 
                hasvalue,
                existing,
                help.c_str()
                );
        }

        std::string getName() const;
        std::string getShortCmd() const;
        std::string getLongCmd() const;
        std::string getHelp() const;
        void setArgPosition(int position);
        bool getHasValue() const;
    
    private:
        std::string name;
        std::string help;
        std::string shortcmd;
        std::string longcmd;
        bool existing;
        int argpos;
        bool hasvalue;
};

#endif // !_ARGUMENT_H_