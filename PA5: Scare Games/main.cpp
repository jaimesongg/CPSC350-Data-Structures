#include "RunScareGame.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <format> <output_file>\n";
        return 1;
    }

    RunScareGame::runTournament(argv[1], argv[2], argv[3]);
    return 0;
}




