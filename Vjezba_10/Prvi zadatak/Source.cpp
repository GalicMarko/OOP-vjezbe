#include <iostream>
#include <algorithm>
using namespace std;

template <class Object>
void arraySort(Object *array, Object size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				Object temp;
				
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void arraySort(char charArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (charArray[i] > charArray[j])
			{
				char temp;

				temp = charArray[i];
				charArray[i] = charArray[j];
				charArray[j] = temp;
			}
		}
	}
}

int main()
{
	int array[10];
	char charArray[10];
	int n, temp, m, chartemp;

	cout << "Enter total number of elements to read: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". element: ";
		cin >> array[i];
		cout << endl;
	}

	arraySort(array, n);

	cout << "Sorted (Ascending Order) Array elements:" << endl;
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";

	cout << endl;

	cout << "Enter total number of elements to read: ";
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cout << i + 1 << ". element: ";
		cin >> charArray[i];
		cout << endl;
	}

	arraySort(charArray, m);

	cout << "Sorted (Ascending Order) Array elements:" << endl;
	for (int i = 0; i < m; i++)
		cout << charArray[i] << " ";
}