/*
Name: Ethan_Cao, 5007944989, 1001, ASSIGNMENT_5
Description: creates an organism object that has the basic info of the
object
Input: put in the organim's size and growthRate
Output: able to manip the size and rate
*/
#ifndef ORGANISM_H
#define ORGANISM_H

class organism
{
public:
	// constuctor for the organism
	organism(double = 1, double = 0);
	// simulatWeek function
	virtual void simulateWeek();
	// assignRate will assign a new rate
	void assignRate(double);
	// alterse the size of the organism
	void alterSize(double);
	// sets size and growth to 0
	void death();
	// returns the size
	double getSize() const;
	// returns the growthRate
	double getRate() const;
	// check if the organism is alive
	bool isAlive() const;
	// destructor
	virtual ~organism();
protected:
	double growthRate;
private:
	double size;
};

#endif // ORGANISM_H
