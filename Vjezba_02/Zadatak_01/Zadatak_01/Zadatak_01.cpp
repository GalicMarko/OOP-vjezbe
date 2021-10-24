// Zadatak_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void references(int* array, int size, int& minimum, int& maximum)
{
    int min = array[0];
    int max = array[0];
    int i;
    
    for (i = 0; i < size; ++i)
    {
        if (array[i] <= min)
            minimum = array[i];
        else if (array[i] >= max)
            maximum = array[i];
    }
}

int main()
{
    int minimum, maximum;
    int array[] = { 12, 5, 15, 78, 3 };
    
    references(array, 5, minimum, maximum);

    cout << minimum << endl;
    cout << maximum << endl;
}

