#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>
#include "Translator.h"

using namespace std;

class FileProcessor : public Translator {
    public:
        FileProcessor();

        ~FileProcessor();

        // Method declaration that processes a file taking the input/output file names as arguments
        // Void because it does not return anything, instead performs action
        void processFile(string inputFile, string outputFile);

        // Method checks if string "check" contains a space
        bool containsSpace(string check);

    // Private member variable that is a pointer to Translator object 
    private:
    Translator *myTranslator;
};

#endif