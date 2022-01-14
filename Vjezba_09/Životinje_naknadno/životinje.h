#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal
{
	public:
		virtual int numberOfLegs() = 0;
		virtual string animalSpecies() = 0;
};

class Insect : public Animal
{
	int legs;
	string species;

public:
	int numberOfLegs();
	string animalSpecies();
	void setLegs(int n);
	void setSpecies(string s);
};

class Spider : public Animal 
{
	int legs;
	string species;

	public:
		int numberOfLegs();
		string animalSpecies();
		void setLegs(int n);
		void setSpecies(string s);
};

class Fly : public Insect
{
	public:
		Fly();
};

class Ant : public Insect
{
	public:
		Ant();
};

class Tarantula : public Spider 
{
	public:
		Tarantula();
};

class BlackWidow : public Spider 
{
	public:
		BlackWidow();
};

class Bird : public Animal 
{
	int legs;
	string species;

	public:
		int numberOfLegs();
		string animalSpecies();
		void setLegs(int n);
		void setSpecies(string s);
};

class Pigeon : public Bird
{
	public:
		Pigeon();
};

class Chicken : public Bird
{
	public:
		Chicken();
};

class Counter 
{
	private:
		int legs = 0;
	public:
		void animalPrint(Animal* animal) 
		{
			cout << "Added: " << animal->animalSpecies() << endl;
			legs += animal->numberOfLegs();
		};

		void legsPrint() 
		{
			cout << legs << endl;
		};
};
