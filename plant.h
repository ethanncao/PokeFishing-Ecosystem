/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: initializes a plant class inside the simulation
Input: sets the plant's size and growthRate along with other functions
Output: changes the size of the plant if nibbledon 
*/
#ifndef PLANT_H
#define PLANT_H

#include "organism.h"

class plant : public organism
{
public:
// default contructor for the plant
	plant(double = 0, double = 0);
	// function for when herbivore nibbles on plant
  	void nibbledOn(double);
		// destructor
	~plant();
};

#endif // PLANT_H