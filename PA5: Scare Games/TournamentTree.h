#ifndef TOURNAMENTTREE_H
#define TOURNAMENTTREE_H

#include <vector>
#include <string>
#include "TournamentNode.h"
#include "Monster.h"

class TournamentTree {
public:
    TournamentTree(const std::vector<Monster>& competitors);  // constructor
    std::string runSingleElimination();  // run single elimination tournament
    std::string runDoubleElimination();  // run double elimination tournament

private:
    TournamentNode* buildSingleEliminationTree(std::vector<Monster>& roundCompetitors);  // build single elimination tree
    TournamentNode* buildDoubleEliminationTree(std::vector<Monster>& winners, std::vector<Monster>& losers);  // build double elimination tree

    std::vector<Monster> competitors;  // list of competitors
    TournamentNode* root;  // root of the tournament tree
};

#endif



