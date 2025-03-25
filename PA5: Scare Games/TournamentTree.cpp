#include "TournamentTree.h"
#include <sstream>

TournamentTree::TournamentTree(const std::vector<Monster>& competitors)
    : competitors(competitors), root(nullptr) {}

std::string TournamentTree::runSingleElimination() {
    std::vector<Monster> competitorsCopy = competitors;  // make a copy of competitors
    root = buildSingleEliminationTree(competitorsCopy);  // build the tournament tree

    std::ostringstream oss;
    oss << "digraph TournamentTree {\n";
    oss << "}";
    return oss.str();  // return the DOT formatted string
}

std::string TournamentTree::runDoubleElimination() {
    std::ostringstream oss;
    oss << "digraph TournamentTree {\n";
    oss << "}";
    return oss.str();  // return the DOT formatted string
}

TournamentNode* TournamentTree::buildSingleEliminationTree(std::vector<Monster>& roundCompetitors) {
    if (roundCompetitors.size() == 1) {
        return new TournamentNode(&roundCompetitors[0]);  // return node with single winner
    }

    std::vector<Monster> nextRound;
    for (size_t i = 0; i < roundCompetitors.size(); i += 2) {
        Monster* winner = (roundCompetitors[i].getScreamPower() > roundCompetitors[i + 1].getScreamPower())
                          ? &roundCompetitors[i]
                          : &roundCompetitors[i + 1];
        nextRound.push_back(*winner);  // add winner to the next round
    }

    return buildSingleEliminationTree(nextRound);  // recursively build the tree
}

TournamentNode* TournamentTree::buildDoubleEliminationTree(std::vector<Monster>& winners, std::vector<Monster>& losers) {
    return nullptr;
}







