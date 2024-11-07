/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: initializes a plant class inside the simulation
Input: sets the plant's size and growthRate along with other functions
Output: changes the size of the plant if nibbledon 
*/
#include "plant.h"
#include <iostream>
using namespace std;

// TODO: Write the implementation here...

// constuctor that sets size and growthRate with the values passed in
plant::plant(double initSize, double initRate)
: organism(initSize, initRate) {
};

/*
  decreaes the size by amount, if the amount is larger than
  the size, then set the size to 0 (by decreasing the size
  such that the end result becomes 0)
*/
void plant::nibbledOn(double amount) {
  /*
  organism::alterSize(amount * -1);
  */
 // if the amount is larger than the size
  if (amount > organism::getSize()) {
    // set the size to 0 by incrementing it by itself but negative
    organism::alterSize(organism::getSize() * -1);
  } else {
    // subtract the amount from the plant's size
    organism::alterSize(amount * -1);
  }
};

// outputs that PLANT DIED
plant::~plant() {
  cout << "PLANT DIED" << endl;
};

