// Zadatak_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int& reference(int* array, int size, int num)
{
    int i; 

    for (i = 0; i < size; ++i)
    {
        if (num == i)
        {
            return array[i];
            break;
        }    
    }

    cout << "Invalid index input!";
}

int main()
{
    int array[] = { 15, 2, 88, 6, 1 };
    int num;

    cout << "Input desired index: " << endl;
    cin >> num;

    int& index = reference(array, 5, num);

    cout << index << endl;

    array[num] = index + 1;

    cout << array[num] << endl;
}
