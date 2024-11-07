/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: Opens a file of randum numbers and gets a random number
Input: input the file and its name to open it
Output: gives us a random number from the list of numbers after 
modulus 5
*/
#include "randNum.h"
#include <string>
using namespace std;

// TODO: Write the implementation here...

// constructor that opens the filestream
randNum::randNum(string filename) {
  //open the file
  infile.open(filename);
};

// returns the next random number from the file
int randNum::getNextRand() {
  //make random to 0 at first
  int random = 0;
  //make the number as a string first
  string num = "";
  // get the number
  getline(infile, num);
  // store as int
  random = stoi(num);
  // return that random number
  return random;
};

randNum::~randNum() {
  //close the file when out of scope
  infile.close();
};