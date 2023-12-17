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
    ArgParser parser;

    // Add arguments
    parser.addArgument("boolArg",   "-b", "--bool",   "Bool argument",   false);
    parser.addArgument("intArg",    "-i", "--int",    "Int argument",    12);
    parser.addArgument("doubleArg", "-d", "--double", "Double argument", 12.23);
    parser.addArgument("strArg",    "-s", "--string", "String argument", "default");

    // Parse command-line arguments
    parser.parse(argc, argv);

    // Retrieve values 
    bool boolValue          = parser.get<bool>("boolArg");
    int intValue            = parser.get<int>("intArg");
    double doubleValue      = parser.get<double>("doubleArg");
    std::string stringValue = parser.get<std::string>("strArg");

    // Use retrieved values in your program logic

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
