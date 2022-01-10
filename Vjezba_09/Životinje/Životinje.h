
#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;

class Animal
{
	public:
		int legs;
		string species;
		virtual int numberOfLegs() = 0;
		virtual string animalSpecies() = 0;
};

class Insect:public Animal
{
	public:
		int numberOfLegs()
		{
			return legs;
		};
		string animalSpecies()
		{
			return species;
		};
};

class Spider:public Animal
{
	
};

class Bird:public Animal
{
	
};

#endif