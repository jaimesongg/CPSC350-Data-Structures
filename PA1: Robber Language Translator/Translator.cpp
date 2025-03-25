#include "Translator.h"
#include "Model.h"
using namespace std;

Translator::Translator() {
    // myModel now points to a newly created Model object
    // Meaning Translator can use methods of Model class
    myModel = new Model();
}

Translator::~Translator() {
    // Frees memory that was dynamically allocated to Model object during construction of Translator object
    delete myModel;
}

string Translator::translateEnglishWord(string word) {
    // Holds fully translated word
    string output;
    // Temporatily holds translation of each letter in the word before adding it to output
    string addition;

    // For loop iterates through every character in the input string "word"
    for (char letter : word) {
        // Checks if character is a vowel (isVowel function) 
        if (isVowel(letter)) {
            // If character is a vowel, translateSingleVowel() method called and returns vowel which becomes stored in "addition"
            addition = myModel->translateSingleVowel(letter);
            output.append(addition);
        }

        // If character is not a vowel, translateSingleConsonant() method called and translates consonant
        else {
            addition = myModel->translateSingleConsonant(letter);
            // takes string stores in addition and adds it to end of output string
            output.append(addition);
        }
    }
    return output;
}

string Translator::translateEnglishSentence(string sentence) {
    string output;
    string addition;

    for (char letter: sentence) {
        // Checks if letter is a space, number, or punctuation mark
        if (letter == ' ' || isNumber(letter) || isPunctuation(letter)) {
            addition = letter;
            output.append(addition);
        }
        else if (isVowel(letter)) {
            addition = myModel->translateSingleVowel(letter);
            output.append(addition);
        }

        else {
            addition = myModel->translateSingleConsonant(letter);
            output.append(addition);
        }
    }
    return output;
}

// Checks if character c is a vowel
bool Translator::isVowel(char c) {
    if (c == 'a' || c == 'A' ||
        c == 'e' || c == 'E' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'u' || c == 'U' ) {
            return true;
        }
            return false;
}

// Checks if character n is a number, which does not change in translation
bool Translator::isNumber(char n) {
    if (n == '0' || n == '1' || n == '2' || n == '3' || n == '4' ||
        n == '5' || n == '6' || n == '7' || n == '8' || n == '9') {
            return true;
    }
    return false;
}

// Checks if character p is a punctuation, which does not change in translation
bool Translator::isPunctuation(char p) {
    if (p == '.' || p == ',' || p == '!' || p == '$' || p == '&' ||
        p == '(' || p == ')' || p == '%' || p == '-' || p == '/' ||
        p == ';' || p == ':') {
            return true;
        }
            return false;
}