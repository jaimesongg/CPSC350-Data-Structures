#include "Level.h"

Level::Level() {
    dimension = 1;
    percentCoin = 0;
    percentEmpty = 0;
    percentGoomba = 0;
    percentKoopa = 0;
    percentMushroom = 0;
    levelArray = nullptr; // no memory allocated yet for the level
    isLast = false; // indicates whether this is last level or not
    marioRow = 0; 
    marioCol = 0;

    // bounds for item placement based on percentages
    coinBound = 0;
    emptyBound = 0;
    goombaBound = 0;
    koopaBound = 0;
    mushroomBound = 0;
}

// deallocates memory from 2d array pointer, File Processor pointer, and Mario pointer
Level::~Level() {
    // frees each row in 2D array
    for (int i = 0; i < dimension; i++) {
        delete[] levelArray[i];
    }
    // frees array of pointers
    delete[] levelArray;
}

// takes in row and column dimensions, along with percentages of how often different items occupy a spot in the level
Level::Level(int N, bool last, int coinP, int emptyP, int goombaP, int koopaP, int mushroomP) {
    dimension = N; 
    isLast = last;
    percentCoin = coinP;
    percentEmpty = emptyP;
    percentGoomba = goombaP;
    percentKoopa = koopaP;
    percentMushroom = mushroomP;
    levelArray = nullptr;
    marioRow = 0;
    marioCol = 0;

    // sets up boundaries for determining which items are places at each spot
    coinBound = coinP - 1;
    emptyBound = coinP + emptyP - 1;
    goombaBound = coinP + emptyP + goombaP - 1;
    koopaBound = coinP + emptyP + goombaP + koopaP - 1;
    mushroomBound = coinP + emptyP + goombaP + koopaP + mushroomP - 1;

    // allocate memory for the level array
    levelArray = new char*[dimension];
    for (int i = 0; i < dimension; i++) {
        levelArray[i] = new char[dimension];
    }
}

// method to set up the level layout using the percentages from contructor
void Level::buildLevel() {
    levelArray = new char*[dimension];

    // to ensure the random numbers being generated aren't repeated in a constant order
    // variable used to decide what item will occupy a spot
    int randNum;

    for (int row = 0; row < dimension; row++) {
        levelArray[row] = new char[dimension]; // allocates memory for each row
        for (int col = 0; col < dimension; col++) {
            randNum = rand() % 99;

            // place a coin if random number is within coin percentage range
            if (randNum <= coinBound) {
                levelArray[row][col] = 'c';
            }

            // place an empty space
            else if (randNum <= emptyBound) {
                levelArray[row][col] = 'x';
            }

            // place a goomba
            else if (randNum <= goombaBound) {
                levelArray[row][col] = 'g';
            }

            // place a koopa
            else if (randNum <= koopaBound) {
                levelArray[row][col] = 'k';
            }

            // place a mushroom
            else if (randNum <= mushroomBound) {
                levelArray[row][col] = 'm';
            }
        }
    }


    // randomly assigns the level boss position
    int randRow = rand() % dimension;
    int randCol = rand() % dimension;
    if (isLast) {
        levelArray[randRow][randCol] = 'B'; // final boss for last level
    }
    else {
        levelArray[randRow][randCol] = 'b';
    }

    // if the current level isn't the last level, then a warp pipe will be generated. if Mario lands on this, he automatically transports to the next level
    if (!(isLast)) {
        randRow = rand() % dimension;
        randCol = rand() % dimension;
        levelArray[randRow][randCol] = 'w';
    }
}

// converts 2D level array into string 
string Level::convertToString() {
    string s;
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            s += levelArray[row][col];
            s += " ";
        }
        s += "\n";
    }
    return s;
}