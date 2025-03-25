#include "Monster.h"
#include <fstream>
#include <sstream>
#include <iostream>

Monster::Monster(const std::string& name, int screamPower)
    : name(name), screamPower(screamPower) {}

int Monster::getScreamPower() const {
    return screamPower; // returns the monster's scream power
}

std::string Monster::getName() const {
    return name; // returns the monster's name
}

std::vector<Monster> Monster::readMonstersFromFile(const std::string& filename) {
    std::vector<Monster> monsters;  // stores monsters read from file
    std::ifstream file(filename);   // open the file for reading

    if (!file) {  // check if file opened successfully
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return monsters;  // return empty vector if file cannot be opened
    }

    std::string line;
    while (std::getline(file, line)) {  // read each line from the file
        std::istringstream iss(line);   // parse the line
        std::string name;
        int screamPower;
        if (iss >> name >> screamPower) {  // if both name and screamPower are found
            monsters.emplace_back(name, screamPower);  // add monster to the vector
        }
    }

    return monsters;  // return the list of monsters
}





