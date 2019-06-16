//
//  Platypus.hpp
//  Program2Platypus
//
//  Created by Nicholas Sullivan on 2/22/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

#ifndef Platypus_h
#define Platypus_h

#include <stdio.h>
#include <iostream>
using namespace std;

class Platypus
{
public:
	// Default Constructor
	Platypus();
	// Explicit Value Constructor
	Platypus(float initWeight, short initAge, char initName, char initGender);

	// Accessors
	unsigned getWeight() const;
	unsigned getAge() const;
	unsigned getName() const;
	unsigned getGender() const;
	unsigned getAlive() const;
	unsigned getMutant() const;

	// Mutators
	void setWeight(int setWeight);
	void setAge(int setAge);
	void setName(char setName);
	void setGender(char setGender);
	void setAlive(bool setAlive);
	void setMutant(bool setMutant);

	// Input & output
	void print(ostream & out) const;

	// Other member functions
	void ageMe();
	void fight(Platypus & p);
	void eat();
	void hatch();

private:

	// Data members
	float weight;
	short age; // in months
	char name,
		gender;
	bool isAlive,
		isMutant;
};

//----- >> operator

ostream & operator<<(ostream & out, const Platypus & p);

#endif /* Platypus_hpp */
