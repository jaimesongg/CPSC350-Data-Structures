#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main(int argc, char **argv) {
    // Instantiates a FileProcessor
    FileProcessor *fp = new FileProcessor();

    // Names of the input and output files
    string iFile = "original.txt";
    string oFile = "translation.html";
    
    // Calls the processFile method to process the file and
    // Output an new file with original and translated text
    fp->processFile(iFile, oFile);

    // Deallocates memory from FileProcessor object
    delete fp;

    // Ends program
    return 0;

}