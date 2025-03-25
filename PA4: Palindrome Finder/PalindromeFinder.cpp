#include "PalindromeFinder.h"
#include "DNASeq.h"
#include <fstream>
#include <iostream>

// sets the file name to be processed
PalindromeFinder::PalindromeFinder(const std::string& fileName) : fileName(fileName) {}

// main function to read and process the DNA sequences from the file
void PalindromeFinder::processFile() {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line == "END") break; // indicates end of input

        // initialize DNASeq object with the line read
        DNASeq dnaSeq(line);

        // validate sequence to ensure it contains only valid nucleotides
        if (!dnaSeq.isValidSequence()) {
            std::cout << line << " - INVALID" << std::endl;
            continue;
        }

        // display sequence and indicate if a genetic palindrome
        dnaSeq.display();
        if (dnaSeq.isGeneticPalindrome()) {
            std::cout << " - Genetic Palindrome" << std::endl;
        } else {
            std::cout << " - Not a Genetic Palindrome" << std::endl;
        }

        // find/display palindromic substrings if the sequence is valid
        findAndDisplayPalindromicSubstrings(dnaSeq);
    }

    inputFile.close();
}

void PalindromeFinder::findAndDisplayPalindromicSubstrings(const DNASeq& dnaSeq) {
    int sequenceLength = dnaSeq.length(); 

    // loop over all possible substring lengths (greater than 4 and less than sequence length)
    for (int len = 5; len < sequenceLength; ++len) {
        // for each substring length check all possible starting positions
        for (int start = 0; start <= sequenceLength - len; ++start) {
            DNASeq subSeq = dnaSeq.substring(start, start + len); // get substring
            
            // check if substring is genetic palindrome
            if (subSeq.isGeneticPalindrome()) {
                std::cout << "\tSubstring ";
                subSeq.display();
                std::cout << " - Genetic Palindrome" << std::endl;
            }
        }
    }
}



