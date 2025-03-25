#include "Model.h"
#include "FileProcessor.h"

FileProcessor::FileProcessor() {
    myTranslator = new Translator();
}

FileProcessor::~FileProcessor() {
    delete myTranslator;
}

// Method for processing input file, translating it, and writing to output HTML file
void FileProcessor::processFile(string inputFile, string outputFile) {
    // Creates an input file stream object (inFS) to read from input file 
    ifstream inFS;
    inFS.open(inputFile);

    if (!inFS.is_open()) {
        cout << "input file could not open" << endl;
        return;
    }

    // Creates an output file stream object (outFS) to write output file
    ofstream outFS;
    outFS.open(outputFile); 

    if (!outFS.is_open()) {
        cout << "output file could not open" << endl;
        return;
    }

    // Writes the beginning of HTML document to output file
    outFS << "<!DOCTYPE html>" << endl;
    outFS << "<html>" << endl;
    outFS << "<head>" << endl;
    outFS << "<title>English to Robber Translation</title>" << endl;
    outFS << "</head>" << endl;
    outFS << "<body>" << endl;

    string line;
    string translatedText;
    // Reads input file line by line
    while (getline(inFS, line)) {
        // Writes original line as bold text inside an HTML paragraph to output file
        outFS << "<p><b>" << line << "</b><br></p>" << endl;
        // If line contains spaces, treat as sentence and translates using translateEnglishSentence(line) method
        if (containsSpace(line)) {
            translatedText += "<p><i>" + myTranslator->translateEnglishSentence(line) + "</i><br></p>" + "\n";
        }
        // If line does not contain spaces, treat as single word and translate using translateEnglishWord(line) method
        else {
            translatedText += "<p><i>" + myTranslator->translateEnglishWord(line) + "</i><br></p>" + "\n";
        }
    }

    // Writes beginning part of HTML file to output file then closes
    outFS << "<p><b></b><br></p>" << endl;
    outFS << translatedText;
    outFS << "<p><i></i><br></p>" << endl;
    outFS << "</body>" << endl;
    outFS << "</html>" << endl;

    inFS.close();
    outFS.close();
}

bool FileProcessor::containsSpace(string check) {
    for (char c : check) {
        if (c == ' ') {
            return true;
        }
    }
    return false;
}