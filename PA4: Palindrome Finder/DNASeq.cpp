#include "DNASeq.h"
#include <iostream>

DNASeq::DNASeq() : dnaList() {}

// constructor that initializes DNA sequence from a str
DNASeq::DNASeq(const std::string& sequence) : size(0) {
    for (char nucleotide : sequence) {  // iterate over each char in input str
        dnaList.insertBack(nucleotide); // insert each char as a node in doubly linked list
        ++size;
    }
}

DNASeq::~DNASeq() {
    dnaList.clear();
}

// method to generate complement of current DNA sequence
DNASeq DNASeq::complement() const {
    DNASeq compSeq;  
    DblList<char>::Node* current = dnaList.getHead(); // start at head of current sequence

    while (current) { // loop until end of list is reached
        compSeq.dnaList.insertBack(getComplement(current->data)); 
        current = current->next;
    }
    
    return compSeq; 
}

char DNASeq::getComplement(char nucleotide) {
    switch (nucleotide) {
        case 'A': return 'T';  
        case 'T': return 'A';  
        case 'C': return 'G';  
        case 'G': return 'C';  
        default: return '\0';  // return null char for invalid input
    }
}

// method to return a substring as a new DNASeq object from start to end 
DNASeq DNASeq::substring(int start, int end) const {
    DNASeq subSeq;  
    DblList<char>::Node* current = dnaList.getHead(); 
    int index = 0; 

    // traverse to start 
    while (current && index < start) {
        current = current->next;
        ++index;
    }

    // add nodes to subSeq until reaching the end position
    while (current && index < end) {
        subSeq.dnaList.insertBack(current->data); // copy nucleotide to subSeq
        current = current->next;
        ++index;
    }

    return subSeq; 
}

// method to check if DNA seq is a genetic palindrome
bool DNASeq::isGeneticPalindrome() const {
    if (dnaList.getHead() == nullptr) return false;
    DNASeq compSeq = complement(); 
    DblList<char>::Node* originalNode = dnaList.getHead(); // start from head of original sequence
    DblList<char>::Node* complementNode = compSeq.dnaList.getTail(); // start from tail of complement

    // traverse original and complement sequences simultaneously
    while (originalNode && complementNode) {
        if (originalNode->data != complementNode->data) {
            return false; // if any nucleotide doesn't match = not a genetic palindrome
        }
        originalNode = originalNode->next;    
        complementNode = complementNode->prev; 
    }

    return true; // if all nucleotides matched = genetic palindrome
}

// method to check if DNA sequence only contains valid characters (A, C, T, G)
bool DNASeq::isValidSequence() const {
    DblList<char>::Node* current = dnaList.getHead(); 
    while (current) {
        char nucleotide = current->data;
        // check if nucleotide is one of valid chars
        if (nucleotide != 'A' && nucleotide != 'C' && nucleotide != 'T' && nucleotide != 'G') {
            return false; 
        }
        current = current->next; 
    }
    return true; 
}

int DNASeq::length() const {
    return size;
}

// method to display the DNA sequence
void DNASeq::display() const {
    DblList<char>::Node* current = dnaList.getHead(); 
    while (current) {
        std::cout << current->data;
        current = current->next;    
    }
}

