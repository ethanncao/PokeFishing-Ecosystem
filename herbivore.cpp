/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: creates an herbivore object aka fish
Input: puts the fish size, rate, need
Output: able to run nibble on plants
*/
#include "herbivore.h"
#include <iostream>
using namespace std;

// TODO: Write the implementation here...

// portion will be set to 0.5, this regules how big of a portion of the
// plant object it will consume
const double herbivore::PORTION = 0.5;

// MAX_FRACTION will be set to 0.1
// this regulaates how big of a portion the herbivore can consume
// in one feeding (when nibble is called)
const double herbivore::MAX_FRACTION = 0.1;

// constructor that sets size, growthRate, needThisWeek with the values
// passed in and sets eatenThisWeek to 0;
herbivore::herbivore(double initSize, double initRate, double initNeed)
  : animal(initSize, initRate, initNeed) {
};

/*
  a function that consumes a portion of a plant object, the amount
  can be computed in the following way

  1. amount is set to PORTION multiplied by size of the meal object
  2. if the amount is larger than MAX_FRACTION multiplied by needThisWeek 
  then set amount to MAX_FRACTION multiplied by needThisWeek
  3. if the amount is larger than the value returned by stillNeed(), then
  set amount to stillNeed()
  4. Call eat and the meal object’s nibbledOn functions and pass the same 
  amount into both functions
*/
void herbivore::nibble (plant& meal) {
  double amount = PORTION * meal.getSize();
  if (amount > MAX_FRACTION * totalNeed()) {
    amount = MAX_FRACTION * totalNeed();
  }

  if (amount > stillNeed()) {
    amount = stillNeed();
  };

  eat(amount);
  meal.nibbledOn(amount);
};

// outputs FISH DIED
herbivore::~herbivore() {
  cout << "FISH DIED" << endl;
};

