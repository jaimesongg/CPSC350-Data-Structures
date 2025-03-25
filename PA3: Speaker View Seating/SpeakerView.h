#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MonoStack.h"

class SpeakerView {
public:
    SpeakerView(const std::string& filename);
    ~SpeakerView();  
    // prcccess seating to determine who can see
    void processSeatingArrangement();

private:
    int N;  // num of rows
    int P;  // num of columns
    double** seating;  // 2D array to store heights
    std::vector<std::vector<double>> peopleThatCanSee; // vector to store heights of visible people
    // reads seating arrangement from file (input.txt)
    void readFile(const std::string& filename);
    // analyzes column to determine which people can see
    void analyzeView();
    void printResults(); 
};

// initializes seating to nullptr and reads seating arrangement from file
SpeakerView::SpeakerView(const std::string& filename) {
    seating = nullptr; 
    readFile(filename);
}

SpeakerView::~SpeakerView() {
    for (int i = 0; i < N; ++i) {
        delete[] seating[i];  // frees each row
    }
    delete[] seating;  // frees array of pointers
}

void SpeakerView::readFile(const std::string& filename) {
    std::ifstream infile(filename); // opens input file
    std::string line;
    bool isReading = false;
    int row = 0;

    // reads the num of rows and columns
    infile >> N >> P;
    seating = new double*[N];  // allocates memory for the rows

    while (std::getline(infile, line)) {
        if (line == "BEGIN") {
            isReading = true; // start reading seating data ater "BEGIN"
            continue;
        }
        if (line == "END") {
            isReading = false; // stop reading after "END"
            break;
        }

        if (isReading && row < N) {  // ensures row count is within bounds
            std::stringstream ss(line);
            seating[row] = new double[P];  // allocates mem for each row
            for (int col = 0; col < P; ++col) { // read each column in current row
                ss >> seating[row][col];  // stores height values
            }

            // Debugging output 
            // std::cout << "Row " << row << ": ";
            // for (int col = 0; col < P; ++col) {
            //    std::cout << seating[row][col] << " ";  
            // }
            // std::cout << std::endl;  

            ++row; // move to next row
        }
    }
}

void SpeakerView::analyzeView() {
    peopleThatCanSee.resize(P);  // resizes vector to hold results for each column

    for (int col = 0; col < P; ++col) {
        MonoStack<double> stack(N, 'd');  // monotonically decreasing stack
        std::vector<double> visibleHeights;

        double maxHeight = -1; // tracks tallest height seen so far

        for (int row = 0; row < N; ++row) {
            double height = seating[row][col];

            // if the current height is taller than the maxHeight, person can see
            if (height > maxHeight) {
                visibleHeights.push_back(height);  // person that can see speaker
                maxHeight = height;  // update maxHeight
            }
        }

        // store visible heights in the vector for this column
        peopleThatCanSee[col] = visibleHeights;
    }
}


void SpeakerView::printResults() {
    for (int col = 0; col < P; ++col) {
        if (!peopleThatCanSee[col].empty()) {
            std::cout << "In column " << col << " there are " << peopleThatCanSee[col].size() << " that can see. Their heights are: ";
            for (size_t i = 0; i < peopleThatCanSee[col].size(); ++i) {
                std::cout << peopleThatCanSee[col][i];  // print height
                if (i != peopleThatCanSee[col].size() - 1) {
                    std::cout << ", ";  // 
                }
            }
            std::cout << " inches." << std::endl;  // print "inches" at end of the column
        }
    }
}

void SpeakerView::processSeatingArrangement() {
    analyzeView();
    printResults(); // call to output the results after analyzing
}




