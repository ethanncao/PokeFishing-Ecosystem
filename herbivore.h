/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: creates an herbivore object aka fish
Input: puts the fish size, rate, need
Output: able to run nibble on plants
*/
#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "animal.h"
#include "plant.h"

class herbivore : public animal
{
public:
	static const double PORTION;  
	static const double MAX_FRACTION;
	herbivore(double = 1, double = 0, double = 0);
	void nibble(plant&);
	~herbivore();
};

#endif // HERBIVORE_H