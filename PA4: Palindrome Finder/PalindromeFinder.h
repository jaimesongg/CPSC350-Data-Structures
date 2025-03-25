#ifndef PALINDROME_FINDER_H
#define PALINDROME_FINDER_H

#include <string> 

class DNASeq; 

class PalindromeFinder {
public:
    explicit PalindromeFinder(const std::string& fileName);

    // process the file to find palindromic sequences
    void processFile();

private:
    std::string fileName;

    void findAndDisplayPalindromicSubstrings(const DNASeq& dnaSeq);
};

#endif 
