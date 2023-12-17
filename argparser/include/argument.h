#ifndef _ARGUMENT_H_
#define _ARGUMENT_H_

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <typedef.h>

using namespace std;


class Argument{
    public:
        Argument();
        Argument(const string& _name, const string& _shortcmd, const string& _longcmd, const string& _help, bool _hasvalue);

        // virtual ~Argument() = default;
        virtual ArgType getType() const = 0;
        virtual ArgStatus loadValue (const string& arg, int pos) ;
        
        bool status();
        bool check(const string& arg) const;
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

        string getName() const;
        string getShortCmd() const;
        string getLongCmd() const;
        string getHelp() const;
        void setArgPosition(int position);
    
    private:
        string name;
        string help;
        string shortcmd;
        string longcmd;
        bool existing;
        int argpos;
        bool hasvalue;
};

#endif // !_ARGUMENT_H_