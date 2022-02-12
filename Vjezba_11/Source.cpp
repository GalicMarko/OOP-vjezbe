#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <exception>
using namespace std;

void writeToVector(vector <int>* numbers)
{
	ifstream File;
	int number;

	File.open("numbers.txt");

	if (File.fail())
	{
		throw exception();
	}
	
	while (File >> number)
	{
		numbers->push_back(number);
	}

	File.close();
}

bool fiveHundredPlus(int n)
{
	return n > 500;
}

bool threeHundredLess(int n)
{
	return n < 300;
}


int main()
{
	vector <int> numbers;
	
	writeToVector(&numbers);

	int min = *min_element(numbers.begin(), numbers.end());
	int max = *max_element(numbers.begin(), numbers.end());

	cout << "Minimum element is " << min << endl;
	cout << "Maximum element is " << max << endl;
	
	int greaterThan500 = count_if(numbers.begin(), numbers.end(), fiveHundredPlus);
	/*funkcija count_if prima početak, kraj vektora i boolean funkciju koja vraća da li je element vektora zadovoljija određeni uvjet*/
	
	cout << "Numbers greater than 500: " << greaterThan500 << endl << endl;

	vector <int>::iterator lessThan300 = remove_if(numbers.begin(), numbers.end(), threeHundredLess);
	/*niz prethodno moramo konvertirat u iterator*/
	/*funkcija remove_if prima početak, kraj vektora i boolean funkciju koja vraća da li je element vektora zadovoljija određeni uvjet*/

	numbers.resize(std::distance(numbers.begin(), lessThan300));
	/*range prethodno moramo konvertirat u distance*/

	sort(numbers.begin(), numbers.end(), greater <int>());
	/*funkcija sort prima početak, kraj vektora i uvjet greater*/
}