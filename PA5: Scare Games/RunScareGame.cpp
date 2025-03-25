#include <fstream>
#include <iostream>
#include <vector>
#include "RunScareGame.h"
#include "TournamentTree.h"
#include "Monster.h"

void RunScareGame::runTournament(const std::string& inputFile, const std::string& mode, const std::string& outputFileName) {
    std::vector<Monster> competitors = Monster::readMonstersFromFile(inputFile);  // load monsters from file

    if (competitors.empty()) {
        std::cerr << "No valid monsters loaded from the file.\n";
        return;  // exit if no valid monsters are found
    }

    if (mode != "single" && mode != "double") {
        std::cerr << "Invalid mode. Please specify 'single' or 'double'.\n";
        return;  // exit if mode is invalid
    }

    TournamentTree tournamentTree(competitors);  // create tournament tree with competitors

    std::string dotData;
    if (mode == "single") {
        dotData = tournamentTree.runSingleElimination();  // run single elimination mode
    } else {
        dotData = tournamentTree.runDoubleElimination();  // run double elimination mode
    }

    std::ofstream outFile(outputFileName);  // open output file for writing
    if (!outFile) {
        std::cerr << "Error: Could not open file '" << outputFileName << "' for writing.\n";
        return;  // exit if the output file cannot be opened
    }

    outFile << dotData;  // write tournament data to file
    outFile.close();  // close output file

    std::cout << "Tournament tree data has been successfully written to '" << outputFileName << "'.\n";
}







