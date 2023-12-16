#include <cstdio>
#include <argparser.h>
using namespace std;


int main(int argc, char* argv[]){
    ArgParser parser;

    parser.addArgument("debug",  "-d", "--debug",  "This is a flag argument",   false);
    parser.addArgument("int",    "-i", "--int",    "This is a int argument",    10);
    parser.addArgument("double", "-d", "--double", "This is a double argument", 0.0);
    parser.addArgument("string", "-s", "--string", "This is a string argument", "null");

    parser.parse(argc, argv);
    parser.print();
}