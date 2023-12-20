# ArgParser

ArgParser is a simple C++ library for parsing command-line arguments with support for various data types.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

ArgParser is designed to provide an easy-to-use interface for parsing command-line arguments in C++ programs. It supports various data types such as bool, int, double, and string, allowing developers to quickly integrate command-line argument parsing into their applications.

## Installation

To use ArgParser in your C++ project, follow these steps:

1. Clone the ArgParser repository:

    ```bash
    git clone https://github.com/Pankaja-Suganda/Argparser.git
    ```

2. Include the `argparser` directory in your project.

3. Link your project with the ArgParser library.

## Usage

To use ArgParser in your C++ program, include the `argparser.h` header file and create an instance of the `ArgParser` class. Add arguments using the `addArgument` method, parse command-line arguments using the `parse` method, and retrieve values using the `get` method.

```cpp
#include <argparser.h>

int main(int argc, char* argv[]) {
    ArgParser parser(
        "Box Volume Calculator",                      // Project name
        "Calculate the volume of a rectangular box"   // Description
    );

    // Add arguments for the dimensions of the box and verbose mode
    parser.addArgument("length",   "-l", "--length",  "Length of the box",     0.0);
    parser.addArgument("width",    "-w", "--width",   "Int of the box",        0.0);
    parser.addArgument("depth",    "-d", "--depth",   "Depth of the box",      0.0);
    parser.addArgument("verbose",  "-v", "--verbose", "Enable verbose output", false);

    // Parse command-line arguments
    parser.parse(argc, argv);

    // checking whether the default help is triggered
    if(ret == PARSE_DEFAULT_HELP_OK){
        return 0;
    }

    if(ret < PARSER_OK){
        printf("Error: Error occured (%d)\n", ret);
        return 1; // Return non-zero to indicate an error
    }

    // Retrieve values 
    double length = parser.get<double>("length");
    double width  = parser.get<double>("width");
    double depth  = parser.get<double>("depth");
    bool verbose  = parser.get<bool>("verbose");

    if (parser.argExists("length") && parser.argExists("width") && parser.argExists("depth")) {
        if (verbose) {
            printf("Dimensions: %.2f X %.2f X %.2f\n", height, width, depth);
        } 

        // Use retrieved values in your program logic

        // Calculate the volume of the box!!
    }

    return 0;
}
```

## Help Command
To display help information, use the following commands:

```cmd
./<exe-name>.exe -h 
```
or
```cmd
./<exe-name>.exe --help
```

Upon execution, it will output:
```
Box Volume Calculator

DESCRIPTION:
        Calculate the volume of a rectangular box
USAGE:
        -d, --depth     : Depth of the box       
        -l, --length    : Length of the box
        -v, --verbose   : Enable verbose output
        -w, --width     : Width of the box
```
Replace `<exe-name>` with the actual name of your executable. This section provides a quick guide on how users can access `help` information along with an example output showcasing the available command-line arguments.

Other than that user can add own help command with built-in help command, then the user specified function will execute before `help` command. 

```cpp
// Example user-specified callback
void userSpecifiedCallback() {
    printf("Executing user-specified callback before the built-in help command.");
}

int main(int argc, char* argv[]) {
    ArgParser parser;

    // Set user-specified callback for help
    parser.setHelpCallback(userSpecifiedCallback);

    // Parse command-line arguments
    parser.parse(argc, argv);

    // ... rest of the program
    return 0;
}
```

## Examples

Here are some examples demonstrating the usage of ArgParser:

### Example 1: Basic Usage
```cpp
// Add a boolean argument with a default value of false
parser.addArgument("boolArg", "-b", "--bool", "Bool argument", false);

// Parse command-line arguments
parser.parse(argc, argv);

// Retrieve the boolean value
bool boolValue = parser.get<bool>("boolArg");
```

### Example 2: Parsing Integers
```cpp
// Add an integer argument with a default value of 42
parser.addArgument("intArg", "-i", "--int", "Int argument", 42);

// Parse command-line arguments
parser.parse(argc, argv);

// Retrieve the integer value
int intValue = parser.get<int>("intArg");
```

### Example 3: Parsing Doubles
```cpp
// Add a double argument with a default value of 3.14
parser.addArgument("doubleArg", "-d", "--double", "Double argument", 3.14);

// Parse command-line arguments
parser.parse(argc, argv);

// Retrieve the double value
double doubleValue = parser.get<double>("doubleArg");
```

### Example 4: Parsing Strings
```cpp
// Add a string argument with a default value of "default"
parser.addArgument("strArg", "-s", "--string", "String argument", "default");

// Parse command-line arguments
parser.parse(argc, argv);

// Retrieve the string value
std::string stringValue = parser.get<std::string>("strArg");
```
### Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

### License

This project is not licensed yet - see the [LICENSE.md](LICENSE) file for details.

