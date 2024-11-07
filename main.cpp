/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: Running all of our simulation in main.cpp
Input: terminal based commands
Output: the output should be the result of each simulated week
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "herbivore.h"
#include "plant.h"
#include "organism.h"
#include "randNum.h"

using namespace std;

const int ROWS = 5;
const int COLS = 5;

void buildPondSimulator(ifstream&, organism***);
void simulateAWeek(organism***, randNum&);
void outputOrganism(organism*);
void clearSimulation(organism***);

int main(int argc, char** argv)
{
    organism *** pond = nullptr;
    ifstream infile;
    string filename;
    randNum rN("RandomNums.txt");
    int weeks;

    // TODO: Write your code here




    // make sure the user puts sufficient amount of arguments
    if (argc > 2) {

        // set the filename to filename
        string filename = argv[1];
        cout << "Reading data from " << filename << " file..." << endl;
        // set the argv[2] to weeks
        int weeks = stoi(argv[2]);
        cout << "Reading amount of weeks '" << weeks 
        << "' for the simulation..." << endl;

        // check to see if the file name is valid
        infile.open(filename);
        if (!infile.is_open()) {
            cout << "ERROR: Invalid filename try again.";
            return 0;
        };
        
        // initializing a new 2d array of organism class
        pond = new organism**[ROWS];
        for (int i = 0; i < ROWS; i++) {
            pond[i] = new organism*[COLS];

            // set each cell to be a nullptr
            for (int j = 0; j < COLS; j++) {
                pond[i][j] = nullptr;
            };
        };


        buildPondSimulator(infile, pond);

        for (int i = 0; i < weeks; i++) {
            cout << "WEEK " << i + 1 << " RESULTS" << endl;
            // we need to simulate 100 activities
                simulateAWeek(pond, rN);
            cout << endl << endl;

        }
    // error if there is not enough arguments passed through    
    } else {
        cout << "ERROR: Please provide filename and number of weeks" 
        << endl;
    };
    

    cout << "Ending simulation" << endl;



    //destroy the simulation
    // we have to make sure that the pond is initialzed before we can run
    if (pond != nullptr) {
        clearSimulation(pond);
    }

    return 0;
}

// TODO: Write the definition of each function here

/* 
    This function takes in an already opened filestream that reads from a
    CSV file and your empty 2D array of organism objects, your job will be
    to insert a  herbivore or plant object into pond[i][j].
*/
void buildPondSimulator(ifstream& file, organism*** pond) {
    string organismType = "";
    double size, growthRate;
    int x, y;
    string line = "";

    while(getline(file, line)) {
        // we use stringstream to parse each command line
        stringstream ss(line); 

        //read each value in and set it = to variable
        if (getline(ss, organismType, ',')) {
            // read in size and growth as a string first
            string sizeStr, growthStr;
            getline(ss, sizeStr, ',');
            getline(ss, growthStr, ',');

            // string to double on size and growth
            size = stod(sizeStr);
            growthRate = stod(growthStr);

            // read in x and y coordinate while ignoring comma between
            ss >> x;
            ss.ignore();
            ss >> y;

            // if the oganism is a fish create a herbivore with parameters
            if (organismType == "FISH") {
                pond[x][y] = new herbivore(size, growthRate, size * 0.1);
            // else if the organism is a plant create a plant with params
            } else if (organismType == "PLANT") {
                pond[x][y] = new plant(size, growthRate);
            } else {
                // error checking if something was read in wrong
                cout << "ERROR" << endl;
            };

            // NOTE: everything else should be a nullptr already
        };
    }
};

/*
    this function simulates one week of the pond simulator, you will
    simulate 100 activities and each activity does the following
*/
void simulateAWeek(organism*** pond, randNum& numbers) {
    for (int i = 0; i < 100; i++) {
    // 1 get two random coordinates to investigate
    int x1, y1, x2, y2;
    x1 = numbers.getNextRand() % 5;
    y1 = numbers.getNextRand() % 5;
    x2 = numbers.getNextRand() % 5;
    y2 = numbers.getNextRand() % 5;

    // 2 create two pointers and set them with the content in the pond
    organism * o1, * o2;
    o1 = pond[x1][y1];
    o2 = pond[x2][y2];


    string organism1, organism2;

    // 3 check the contents in o1 and o2 for whether they are null
    // or if they are herbivore or plant

    // use dynamic cast to check if its plant/herbivore else its null (o1)
    if (dynamic_cast<plant*>(o1)) {
        organism1 = "plant";
    } else if (dynamic_cast<herbivore*>(o1)) {
        organism1 = "herbivore";
    } else {
        organism1 = "null";
    };

    // do the same for o2
    if (dynamic_cast<plant*>(o2)) {
        organism2 = "plant";
    } else if (dynamic_cast<herbivore*>(o2)) {
        organism2 = "herbivore";
    } else {
        organism2 = "null";
    };

    // ignore cases 4-6

    // case 7:
    // if one of the pointers is null and the other points to an herbivore
    if (organism1 == "herbivore" && organism2 == "null"){
        // swap places
        // moves the herbivore to the null position
        pond[x2][y2] = pond[x1][y1];
        // sets the old position to be nullptr
        pond[x1][y1] = nullptr;
    } else if ((organism1 == "null" && organism2 == "herbivore")){
        // swap places
        // moves the herbivore to the null position
        pond[x1][y1] = pond[x2][y2];
        // sets the old position to be nullptr
        pond[x2][y2] = nullptr;
    };

    // 8 if they both points to herbivore objects swap their positions
    if ((organism1 == "herbivore") && (organism1 == organism2)) {
        // swap place
        // make a copy of the herbivore we are going to swap
        organism* copy = pond[x1][y1];
        // o2  goes to where o1 was
        pond[x1][y1] = pond[x2][y2];
        // o1(copy) goes to where o2 was
        pond[x2][y2] = copy; 
    };

    // 9 if one is a herbivore and the other is a plant
    if ((organism1 == "herbivore" && organism2 == "plant") ||
    (organism1 == "plant" && organism2 == "herbivore")) {
        //call the herbivore's nibble function passing through the plant
        // if the first organism is the herbivore
        if (organism1 == "herbivore") {
            // create pointers and dynamic cast both the plant and fish
            herbivore* o1Ptr = dynamic_cast<herbivore*>(o1);
            plant* o2Ptr = dynamic_cast<plant*>(o2);
            // make sure that they are not nullptr
            if (o1Ptr != nullptr && o2Ptr != nullptr) {
                o1Ptr->nibble(*o2Ptr);
            }

            // now we need to swap their places
            organism* copy = pond[x1][y1];
            // o2 goes to where o1 was
            pond[x1][y1] = pond[x2][y2];
            // o1(copy goes to where o2 was)
            pond[x2][y2] = copy;
        };

        // if the second organism is the herbivore
        if (organism2 == "herbivore") {
           // create pointers and dynamic cast both the plant and fish
            herbivore* o2Ptr = dynamic_cast<herbivore*>(o2);
            plant* o1Ptr = dynamic_cast<plant*>(o1);
            if (o1Ptr != nullptr && o2Ptr != nullptr) {
                o2Ptr->nibble(*o1Ptr);
            }

            // now we need to swap their places
            organism* copy = pond[x1][y1];
            // o2 goes to where o1 was
            pond[x1][y1] = pond[x2][y2];
            // o1(copy goes to where o2 was)
            pond[x2][y2] = copy; 
        };
    }
};
// end of the 100 activities

    // call simulateWeek() function for each element
    // iterate through the whole pond
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // so if the element is not a nullptr
            if (pond[i][j] != nullptr) {
                // call simulateWeek()
                pond[i][j]->simulateWeek();
                // if it survives the day we just output it
                if (pond[i][j]->isAlive()) {
                    outputOrganism(pond[i][j]);
                }
                // check if the object is still alive
                if (!pond[i][j]->isAlive()) {
                     pond[i][j]->death();
                    // deallocate memory
                    delete pond[i][j];
                    // set the element to be a nullptr
                    pond[i][j] = nullptr;
                } else {
                    continue;
                };
            };
        };
    };
};

/*
    Outputs the string "Fish with weight"
    or "Plant with weight"
*/
void outputOrganism(organism * org) {
    // if its herbivore we output FISH
    if (dynamic_cast<herbivore*>(org)) {
        cout << "Fish With Weight " << org->getSize() << endl;
    } else if (dynamic_cast<plant*>(org)) {
         // if its plant we output PLANT
        cout << "Plant weight " << org->getSize() << endl;
    }
};

/*
    deallocates all the objects in each pond[r][c] position
    and then deallocates the pointers as well
*/
void clearSimulation(organism *** pond) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            delete pond[i][j]; // delete each element
        }
        delete[] pond[i]; // delete each row
    }
    delete[] pond; // delete the whole thang
}