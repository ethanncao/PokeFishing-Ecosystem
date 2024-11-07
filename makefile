# Make file for operator overloading assignment
OBJS            = main.o organism.o animal.o plant.o herbivore.o randNum.o
MAIN1_OBJS 		= main.o organism.o animal.o plant.o herbivore.o randNum.o
CC 				= g++
CCFLAGS 		= -Wall -Wextra -pedantic -std=c++11 -g
MAIN1_DEPS 		= organism.h plant.h herbivore.h randNum.h
ANIMAL_DEPS 	= organism.h
HERBIVORE_DEPS	= animal.h plant.h
PLANT_DEPS 		= organism.h

all: main

main: $(OBJS)
	@echo "Linking Objects..."
	$(CC) $(CCFLAGS) -o main_test $(MAIN1_OBJS)
	@echo "Finished building main test program"

main1.o: main.cpp $(MAIN1_DEPS)
	@echo "Compiling main..."
	$(CC) $(CCFLAGS) -c main.cpp
organism.o: organism.cpp
	@echo "Compiling organism class..."
	$(CC) $(CCFLAGS) -c organism.cpp
animal.o: animal.cpp $(ANIMAL_DEPS)
	@echo "Compiling animal class..."
	$(CC) $(CCFLAGS) -c animal.cpp
plant.o: plant.cpp $(PLANT_DEPS)
	@echo "Compiling plant class..."
	$(CC) $(CCFLAGS) -c plant.cpp
herbivore.o: herbivore.cpp $(HERBIVORE_DEPS)
	@echo "Compiling herbivore class..."
	$(CC) $(CCFLAGS) -c herbivore.cpp
randNum.o: randNum.cpp
	@echo "Compiling randNum class..."
	$(CC) $(CCFLAGS) -c randNum.cpp


# -----
# clean by removing object files.

clean:
	rm $(OBJS) main_test
