#include <iostream>
#include <cmath>
#include <argparser.h>

// Function to calculate the volume of a rectangular box given its dimensions
double calculateBoxVolume(double length, double width, double depth) {
    return length * width * depth;
}

int main(int argc, char* argv[]) {
    ArgStatus ret = PARSER_ERROR;
    ArgParser parser(
        "Box Volume Calculator",                       // Project name
        "Calculate the volume of a rectangular box"    // Description
    );

    // Add arguments for the dimensions of the box and verbose mode
    parser.addArgument("length",  "-l", "--length",  "Height of the box",     0.0);
    parser.addArgument("width",   "-w", "--width",   "Width of the box",      0.0);
    parser.addArgument("depth",   "-d", "--depth",   "Depth of the box",      0.0);
    parser.addArgument("verbose", "-v", "--verbose", "Enable verbose output", false);

    // Parse command-line arguments
    ret = parser.parse(argc, argv);

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

    // Check if the provided dimensions are valid
    if (parser.argExists("length") && parser.argExists("width") && parser.argExists("depth")) {
        // Calculate the volume of the box
        double volume = calculateBoxVolume(length, width, depth);

        // Display the result based on verbose mode 
        if (verbose) {
            printf("Dimensions: %.2f X %.2f X %.2f\n", length, width, depth);
        } 

        printf("Volume of the box: %.2f" , volume);
    } else {
        printf("Error: Invalid dimensions. All dimensions must be included.");
        return 1; // Return non-zero to indicate an error
    }

    return 0;
}
