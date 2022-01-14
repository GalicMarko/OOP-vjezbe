#include "životinje.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
	Insect fly;
	Pigeon pigeon;
	Tarantula tarantula;

	Animal* animals[3];
	int length = sizeof(animals) / sizeof(Animal);

	animals[0] = new Fly;
	animals[1] = new Pigeon;
	animals[2] = new Tarantula;

	Counter counter;

	for (int i = 0; i < length; i++) 
	{
		counter.animalPrint(animals[i]);
	}

	counter.legsPrint();
}
