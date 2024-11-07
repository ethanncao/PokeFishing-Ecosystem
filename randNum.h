/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: Running all of our simulation in main.cpp
Input: terminal based commands
Output: the output should be the result of each simulated week
*/
#ifndef RAND_NUM_H
#define RAND_NUM_H

#include <fstream>
using namespace std;

class randNum
{
public:
// function that takes in a string for random numbers
    randNum(string);
    // destructor that will close the file
    ~randNum();
    // function to get random number
    int getNextRand();
private:
// infile that we will read through
    ifstream infile;
};

#endif // RAND_NUM_H