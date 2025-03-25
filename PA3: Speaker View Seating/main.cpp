#include "SpeakerView.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    SpeakerView view(argv[1]);
    view.processSeatingArrangement();

    return 0;
}


