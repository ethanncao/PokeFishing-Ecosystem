/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: creates an organism object that has the basic info of the
object
Input: put in the organim's size and growthRate
Output: able to manip the size and rate
*/
#include "organism.h"

// TODO: Write the implementation here...

// Constructor that sets growrthRate and size with the values passed in
organism::organism(double initSize, double initRate) {
   size = initSize;
   growthRate = initRate;
};

// increments the size by growthRate
void organism::simulateWeek() {
  size += growthRate;
};

// Assigns growthRate with the value passed in
void organism::assignRate(double newRate) {
  growthRate = newRate;
};

// increases the size by amount
void organism::alterSize(double amount) {
  size += amount;
};

// sets growthRate and size to 0
void organism::death() {
  growthRate = 0;
  size = 0;
};

// returns size
double organism::getSize() const{
  return size;
};

// returns the growthRate
double organism::getRate() const{
  return growthRate;
};

// returns true if size is larger than 0 and returns false otherwise
bool organism::isAlive() const{
  // if size is greater than 0 then return true
  if (size > 0) {
    return true;
  } 

  // return false default
  return false;
};

// destructor sets growthRate and size to 0
organism::~organism() {
  growthRate = 0;
  size = 0;
};