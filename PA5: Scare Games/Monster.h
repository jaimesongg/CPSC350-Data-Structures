#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>

class Monster {
public:
    Monster(const std::string& name, int screamPower);  // constructor to initialize name and scream power
    int getScreamPower() const;  // getter for scream power
    std::string getName() const;  // getter for name

    static std::vector<Monster> readMonstersFromFile(const std::string& filename);  // static function to read monsters from a file

private:
    std::string name;  // monster's name
    int screamPower;  // monster's scream power
};

#endif


