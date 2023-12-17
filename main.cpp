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

    auto intValue = parser.get<int>("int");
    auto doubleValue = parser.get<double>("double");
    auto stringValue = parser.get<string>("string");

    printf("Int Value : %d\n", intValue);
    printf("Double Value : %f\n", doubleValue);
    printf("String Value : %s\n", stringValue.c_str());

    if(parser.argExists("debug")){
        printf("debug is there\n");
    }
    else{
        printf("debug is not there\n");
    }


}