/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: creates animal class object
Input: has the size, rate, need, and eaten as constructor
Output: has the eat function to eat plants and other functions
*/
#ifndef ANIMAL_H
#define ANIMAL_H

#include "organism.h"

class animal : public organism
{
public:
	animal(double = 1, double = 0, double = 0);
	void assignNeed(double);
	void eat(double);
	void simulateWeek();
	double stillNeed() const;
	double totalNeed() const;
	~animal();
private:
	double needThisWeek;
	double eatenThisWeek;
};

#endif // ANIMAL_H