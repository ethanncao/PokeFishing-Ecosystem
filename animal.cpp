/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: creates animal class object
Input: has the size, rate, need, and eaten as constructor
Output: has the eat function to eat plants and other functions
*/
#include "animal.h"

// TODO: Write the implementation here...

/* 
  constructor that sets size, growrthRate, and needThisWeek with the
  values assigned, and sets eatenThisWeek to 0
*/
animal::animal(double initSize, double initRate, double initNeed)
: organism(initSize, initRate) {
  needThisWeek = initNeed;
  eatenThisWeek = 0;
};

// reassigns needThisWeek to the value passed in
void animal::assignNeed(double newNeed) {
  needThisWeek = newNeed;
};

// increments eatenThisWeek by amount
void animal::eat(double amount) {
  eatenThisWeek += amount;
};

/*
  the function does the following:
    1. Changes the sign on growthRate based on whether the
       value returned by stillNeed(); sets the sign to negative
       if stillNeed() returns a positive number and sets the sign to
       positive if stillNeed() returns 0

    2. Then the function calls organism's simulateWeek() function, sets
        eatenThisWeek to 0, checks if stillAlive() if no longer alive then
        call death() function
*/
void animal::simulateWeek() {
  if (stillNeed() > 0) {
    if (growthRate > 0) {
      //set growthRate to be negative
    growthRate = growthRate * -1;
    }
  } 
  
  if (stillNeed() == 0) {
    if (growthRate < 0) {
      growthRate *= -1;
    }
  };

  organism::simulateWeek();
  eatenThisWeek = 0;
  if(!isAlive()) {
    death();
  };
};

// returns 0 if eatenThisWeek is greater than or equal to
// needThisWeek, and return the difference between needThisWeek
// and eatenThisWeek otherwise
double animal::stillNeed() const{
  if (eatenThisWeek >= needThisWeek) {
    double thing = 0;
    return thing;
  }
    double difference = needThisWeek - eatenThisWeek;
    return difference;
};

// returns needThisWeek
double animal::totalNeed() const{
  return needThisWeek;
};

// sets needThisWeek and eatenThisWeek to 0
animal::~animal() {
  needThisWeek = 0;
  eatenThisWeek = 0;
};
