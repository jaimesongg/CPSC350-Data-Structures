#ifndef DNASEQ_H
#define DNASEQ_H

#include "DblList.h"
#include <string>

class DNASeq {
    public:
        DNASeq(); // default constructor
        DNASeq(const std::string& sequence); // contructor to initialize from string sequence
        ~DNASeq(); // deconstructor

        DNASeq complement() const; // generate/return complement
        DNASeq substring(int start, int end) const; // returns DNA sequence representing a substring
        bool isGeneticPalindrome() const;
        bool isValidSequence() const;
        int length() const;
        void display() const; // prints sequence to console

    private:
        DblList <char> dnaList;
        static char getComplement(char nucleotide);
        int size;
};

#endif