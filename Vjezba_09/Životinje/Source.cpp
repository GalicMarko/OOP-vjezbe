#include <iostream>
#include <string>
#include "Životinje.h"
using namespace std;

int main()
{
	int n = 1;
	
	while (true)
	{
		int subSpeciesIndex;
		
		cout << "Type 1 for Insect, 2 for Spider or 3 for Bird: ";
		cin >> subSpeciesIndex;
		cout << endl << n << ". Animal is: ";

		if (subSpeciesIndex == 1)
		{
			Insect i;
		}
		
	}
}