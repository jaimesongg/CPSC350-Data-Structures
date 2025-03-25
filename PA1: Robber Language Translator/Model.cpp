// .cpp file intended to be compiled once for any given build of the program
#include "Model.h" 
using namespace std;

    Model::Model() {} // Function that gets called when object of Model class is created

    Model::~Model() {} // Function that gets called when an object of Model class is destroyed

    // Method to translate a single consonant
    string Model::translateSingleConsonant(char consonant) {
        // Holds string output of translated consonant
        string output;
        // Adds input consonant to output string
        output += consonant;
        // Adds character "o" to output string
        output += "o";
        // Converts input consonant to lowercase and adds to output string
        output += tolower(consonant); 

        return output;
    }

    // Method to translate a single vowel
    // Vowels are not changed
    string Model::translateSingleVowel(char vowel) {
        string output;
        // Adds the vowel to output string
        output += vowel;

        return output;
    }

