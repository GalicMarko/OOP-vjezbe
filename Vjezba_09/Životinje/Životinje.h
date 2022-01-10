#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
using namespace std;

class Animal
{
	public:
		virtual int numberOfLegs() = 0;
		virtual string animalSpecies() = 0;
};

class Insect:public Animal
{
public:
	int legs;
	string species;
	int numberOfLegs(int legs)
	{
		return legs;
	}
};

class Spider:public Animal
{
	
};

class Bird:public Animal
{
	
};

class Fly:public Insect
{
	int legs = 6;
};

class Tarantula :public Spider
{
	int legs = 8;
};

class Chicken :public Bird
{
	int legs = 2;
};


#endif