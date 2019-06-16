//
//  Platypus.cpp
//  Program2Platypus
//
//  Created by Nicholas Sullivan on 2/22/18.
//  Copyright © 2018 Nicholas Sullivan. All rights reserved.
//

#include "Platypus.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int rand();

//----- Default constructor definition (creates dead platypus) -----
Platypus::Platypus()
	: weight(), age(), name(), gender(), isAlive(false), isMutant()
{
}

//----- Explicit value constructor definition -----
Platypus::Platypus(float initWeight, short initAge, char initName, char initGender)
{
	// Check class invariants
	if ((initName) && (initWeight > 0 && initWeight <= 10) && (initAge >= 0) && (initGender == 'M' || initGender == 'F'))
	{
		weight = initWeight;
		age = initAge;
		name = initName;
		gender = initGender;
		isAlive = true;
		isMutant = false;
	}
	else
		cout << "*** Invalid initial values ***" << endl;
}

//----- Definitions for accessor functions -----

unsigned Platypus::getWeight() const
{
	return weight;
}

unsigned Platypus::getAge() const
{
	return age;
}

unsigned Platypus::getName()const
{
	return name;
}

unsigned Platypus::getGender()const
{
	return gender;
}

unsigned Platypus::getAlive()const
{
	return isAlive;
}

unsigned Platypus::getMutant()const
{
	return isMutant;
}

//----- Definitions for mutator functions -----

void Platypus::setWeight(int setWeight)
{
	// Check class invariant
	if (setWeight >= 0)
		weight = setWeight;
}
void Platypus::setAge(int setAge)
{
	// Check class invariant
	if (setAge >= 0)
		age = setAge;
}

void Platypus::setName(char setName)
{
	// Check class invariant
	if (setName)
	{
		name = setName;
	}
	else
		cerr << "*** Can't set name with this value ***" << endl;
}

void Platypus::setGender(char setGender)
{
	// Check class invariant
	if (setGender == 'M' || setGender == 'F')
	{
		gender = setGender;
	}
	else
		cerr << "*** Can't set gender with this value ***" << endl;
}

void Platypus::setAlive(bool setAlive)
{
	isAlive = setAlive;
}

void Platypus::setMutant(bool setMutant)
{
	isMutant = setMutant;
}

//----- Definition of print function -----
void Platypus::print(ostream & out) const
{
	// Prints out all of the member variables.
	out << "*** Platypus '" << name << "' ***" << endl;
	out << "Weight: " << weight << " lbs." << endl;
	out << "Age: " << age << " months." << endl;
	out << "Gender: " << (gender == 'M' ? "Male" : "Female") << endl;
	out << "Alive? " << (isAlive ? "Yes" : "No") << endl;
	out << "Mutant? " << (isMutant ? "Yes" : "No") << endl << endl;
}

//----- Definition of ageMe function -----
void Platypus::ageMe()
{
	// Only ages if alive.
	if (isAlive == true)
	{
		age += 1;

		float chanceMutant = 0,
			chanceDeath = 0;

		// Random numbers for chances of dying (based on weight) and becoming mutant (2% chance).
		chanceMutant = float(rand() % 100);
		chanceDeath = float(rand() % 100);

		// Decides if platypus becomes mutant.
		if (chanceMutant <= 1)
		{
			isMutant = true;
			cout << "Platypus '" << name << "' is now mutant!" << endl;
		}

		// Decides if platypus dies.
		if (chanceDeath < (weight * 10))
		{
			isAlive = false;
			cout << "Platypus '" << name << "' is now dead!" << endl;
		}
		else
			cout << "Platypus '" << name << "' is still alive. Its new age is: " << age << " months." << endl;
	}
	else {
		cout << "Platypus '" << name << "' is already dead." << endl;
	}
}

//----- Definition of fight function -----
void Platypus::fight(Platypus & p)
{
	cout << endl << "*** Platypus '" << name << "' is attacking Platypus '" << p.name << "'! ***" << endl;

	// Fight ratio
	srand((unsigned int)time(NULL));
	int chanceWinFight = 0,
		fightRatio = 0;
	fightRatio = (weight / p.weight) * 50;
	chanceWinFight = rand() % 100 + 1;

	if (chanceWinFight < fightRatio)
	{
		// Calling platypus survives, passed in platypus dies.
		cout << "Platypus '" << name << "' wins! Platypus '" << p.name << "' died." << endl;
		p.isAlive = false;
	}
	else
	{
		// Passed in platypus survives, calling platypus dies.
		cout << "Platypus '" << p.name << "' wins! Platypus '" << name << "' died." << endl;
		isAlive = false;
	}
}

//----- Definition of eat function -----
void Platypus::eat()
{
	if (isAlive == false)
	{
		cout << "Platypus '" << name << "' is dead. It cannot eat." << endl;
	}
	else
	{
		float percentWeight = 0.0,
			incWeight = 0.0;

		//cout << weight << endl;
		percentWeight = (float(rand() % 50 + 1)) / 1000;
		//cout << percentWeight << endl;
		incWeight = weight * percentWeight;
		//cout << incWeight << endl;

		weight += incWeight;
		//cout << weight << endl;

		cout << "Platypus '" << name << "' new weight is: " << weight << " lbs." << endl;
	}
}

//----- Definition of hatch function -----
void Platypus::hatch()
{
	int chanceGender = 0;
	char input = '\0';
	bool isValidName = false;
	srand((unsigned int)time(NULL));
	chanceGender = rand() % 2;

	cout << endl << "*** A platypus egg is hatching! ***" << endl;

	isAlive = true;
	isMutant = false;
	weight = float(rand() % 10 + 1) / 10;
	age = 0;

	// 50% chance m or f
	if (chanceGender == 1)
	{
		gender = 'M';
		cout << "It's a male. What character would you like to assign for his name?" << endl;
	}
	else
	{
		gender = 'F';
		cout << "It's a female. What character would you like to assign for her name?" << endl;
	}

	while (!isValidName)
	{
		cin >> input;
		if (input != 'A' && input != 'B' && input != 'C' && input != 'D')
		{
			name = input;
			isValidName = true;
		}
		else
		{
			cerr << endl << "*** Invalid input for name. Character already assigned. Enter again. ***\n";
			isValidName = false;
		}
	}
}

//----- Definition of operator<<() -----
ostream & operator<<(ostream & out, const Platypus & p)
{
	p.print(out);
	return out;
}
