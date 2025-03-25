#include "TournamentNode.h"
#include <iostream>

// constructor
TournamentNode::TournamentNode(Monster* winner, TournamentNode* left, TournamentNode* right) 
    : winner(winner), left(left), right(right) {
    if (!winner) {
        std::cerr << "Warning: Winner is null during TournamentNode creation.\n";
    }
}

// getter for the winner
Monster* TournamentNode::getWinner() const {
    return winner;
}

// setter for the winner
void TournamentNode::setWinner(Monster* winner) {
    this->winner = winner;
}

// getter for the left child
TournamentNode* TournamentNode::getLeft() const {
    return left;
}

// setter for the left child
void TournamentNode::setLeft(TournamentNode* left) {
    this->left = left;
}

// getter for the right child
TournamentNode* TournamentNode::getRight() const {
    return right;
}

// setter for the right child
void TournamentNode::setRight(TournamentNode* right) {
    this->right = right;
}

// destructor
TournamentNode::~TournamentNode() {
    delete left;
    delete right;
}




