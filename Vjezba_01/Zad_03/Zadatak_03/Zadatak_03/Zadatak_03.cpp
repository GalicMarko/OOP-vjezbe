// Zadatak_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int min(int* array, int size_array)
{
    int min_num = array[0];
    int count;

    for (count = 1; count < size_array; count++)
    {
        if (array[count] < min_num)
            min_num = array[count];
    }

    return min_num;
}

int max(int* array, int size_array)
{
    int max_num = array[0];
    int count;

    for (count = 1; count < size_array; count++)
    {
        if (array[count] > max_num)
            max_num = array[count];
    }

    return max_num;
}

void input_arr(int* array, int elements_in_array)
{
    int count;

    for (count = 0; count < elements_in_array; count++)
    {
        cin >> (array[count]);
    }
}

int main()
{
    int array[100];
    int elements;

    cout << "Number of elements: " << endl;
    cin >> elements;

    cout << "Elements: " << endl;
    input_arr(array, elements);

    cout << "Lowest element is: " << min(array, elements) << endl;
    cout << "Greatest element is: " << max(array, elements) << endl;
}

