#include <iostream>
#include "PalindromeFinder.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No filename provided." << std::endl;
        return 1; // exit with an error code
    }

    std::string fileName = argv[1]; // get filename from command line args
    PalindromeFinder finder(fileName); // pass filename to the constructor

    finder.processFile(); // calls method to process the DNA sequences
    return 0; // exit successfully
}
