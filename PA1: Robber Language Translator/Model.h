// .h file intented to be #included from many different .cpp files that make up a single program
#include <iostream>
#include <string>

// """BEGIN CODE FROM CHAT GPT, PROMPT ASKED: if i defined a class in .h do i have to define the class in .cpp.? """
// print ("I did not write this"); 
// Checks if MODEL_H has not been defined yet, if not code in #indef block 
// will be processed, if defined complier skips rest of header file
#ifndef MODEL_H
// Defines the macro MODEL_H so that if this file is included again later file won't process again
#define MODEL_H
// """END OF CODE FROM CHAT GPT"""
using namespace std;

class Model {
    public:
        // Default constructor
        Model();

        // Default deconstructor
        ~Model();

        // Method to translate a single consonant
        string translateSingleConsonant(char consonant);

        // Method to translate a single vowel
        string translateSingleVowel(char vowel);
};

// Marks end of #indef block
#endif