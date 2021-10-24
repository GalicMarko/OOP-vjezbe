// Zadatak_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int min_num(int* array, int e)
{
    if (e == 1)
        return array[0];
    else
        return min(array[e - 1], min_num(array, e - 1));
}
int max_num(int* array, int e)
{
    if (e == 1)
        return array[0];
    return max(array[e - 1], max_num(array, e - 1));
}
void input_array(int* array, int e)
{
    int count;

    for (count = 0; count < e; count++)
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
    input_array(array, elements);

    cout << "Smallest element: " << min_num(array, elements) << endl;
    cout << "Biggest element: " << max_num(array, elements) << endl;
}
