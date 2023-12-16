#include <cstdio>
#include <memory>
#include <string>
#include <argparser.h>
using namespace std;


int main(int argc, char* argv[]){
    printf("Argparser Testing\n");
    ArgParser parser;

    parser.addArgument("debug", "-d", "--debug", "This is a debug flag", false);
    parser.addArgument("append", "-a", "--append", "This is a append flag", 10);
    parser.addArgument("float", "-f", "--float", "This is a float flag", 0.0);
    parser.addArgument("string", "-s", "--string", "This is a string flag", "null");

    parser.get("debug").setCallback(function);
    parser.get("debug").setValidation(function);

    parser.flag("debug")

    parser.parse(argc, argv);
    parser.print();
}