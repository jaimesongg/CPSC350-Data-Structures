#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <string>
#include "Model.h"

// Inherits from Model class
#include "Model.h"
using namespace std;

// Declares Translator class which inherits from Model class
class Translator : public Model {

    // Publicly inherits all public members/methods of Model class
    // Ex: Can use public methods like translateSingleConsonant and translateSingleVowel
    public:

        Translator();

        ~Translator();

        // Method to translate word
        string translateEnglishWord(string word);

        // Method to translate sentance
        string translateEnglishSentence(string sentence);

        // Returns true if c is a vowel, otherwise false
        bool isVowel(char c);

        // Returns true if n is a numeric character, otherwise false
        bool isNumber(char n);

        // Returns true if p is a punctuation mark, otherwise false
        bool isPunctuation(char p);

        private:
            Model *myModel;
};

#endif