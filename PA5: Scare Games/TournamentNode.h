#ifndef TOURNAMENTNODE_H
#define TOURNAMENTNODE_H

#include "Monster.h"

class TournamentNode {
private:
    Monster* winner; // pointer to the winner monster
    TournamentNode* left; // pointer to left child node
    TournamentNode* right; // pointer to right child node

public:
    TournamentNode(Monster* winner = nullptr, TournamentNode* left = nullptr, TournamentNode* right = nullptr);  // constructor
    Monster* getWinner() const;  // returns the winner
    void setWinner(Monster* winner);  // sets the winner
    TournamentNode* getLeft() const;  // returns the left child node
    void setLeft(TournamentNode* left);  // sets the left child node
    TournamentNode* getRight() const;  // returns the right child node
    void setRight(TournamentNode* right);  // sets the right child node
    std::string getWinnerName() const;  // returns the winner's name
    int getWinnerScreamPower() const;  // returns the winner's scream power
    ~TournamentNode();  // destructor
};

#endif

