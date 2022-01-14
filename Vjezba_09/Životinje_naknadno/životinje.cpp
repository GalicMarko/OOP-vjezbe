#include "životinje.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Insect::numberOfLegs()
{
	return legs;
}

string Insect::animalSpecies()
{
	return species;
}

void Insect::setLegs(int n)
{
	legs = n;
}

void Insect::setSpecies(string s)
{
	species = s;
}

int Spider::numberOfLegs()
{
	return legs;
}

string Spider::animalSpecies()
{
	return species;
}

void Spider::setLegs(int n)
{
	legs = n;
}

void Spider::setSpecies(string s)
{
	species = s;
}

int Bird::numberOfLegs() 
{
	return legs;
}

string Bird::animalSpecies() 
{
	return species;
}

void Bird::setLegs(int n)
{
	legs = n;
}

void Bird::setSpecies(string s) 
{
	species = s;
}

Fly::Fly()
{
	setLegs(6);
	setSpecies("Fly");
}

Ant::Ant()
{
	setLegs(6);
	setSpecies("Ant");
}

Tarantula::Tarantula() 
{
	setLegs(8);
	setSpecies("Tarantula");
}

BlackWidow::BlackWidow()
{
	setLegs(8);
	setSpecies("Black widow");
}

Pigeon::Pigeon()
{
	setLegs(2);
	setSpecies("Pigeon");
}

Chicken::Chicken()
{
	setLegs(2);
	setSpecies("Chicken");
}
