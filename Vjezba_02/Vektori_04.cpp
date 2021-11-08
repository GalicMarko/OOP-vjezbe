// Vektori_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstddef>
#include <iostream>
using namespace std;


struct myVector
{
    int* arr;
    int size, capacity;

    // member functions
    void vector_new(int sz = 0);
    void vector_delete();
    void vector_push_back(int n);/* adds a new element at the end of the vector */
    void vector_pop_back();/* removes the last element in the vector */
    int& vector_front();/* returns a reference to the first element in the vector*/
    int& vector_back(); /* returns a reference to the last element in the vector */
    int vector_size(); /* returns the number of the elements in the vector */

    void print_vector();
};
void myVector::vector_new(int sz)
{
    arr = new int[sz];
    size = 0;
    capacity = sz;
}
void myVector::vector_delete()
{
    delete arr;
}
void myVector::vector_push_back(int n)
{
    if (size == capacity)
    {
        capacity *= 2;
        int* arrN = new int[capacity];
        for (int i = 0; i < (capacity - 1); i++)
        {
            arrN[i] = arr[i];
        }

        delete[] arr;

        arr = arrN;
    }

    arr[size] = n;
    size++;
}


void myVector::vector_pop_back()
{
    size -= 1;
}
int& myVector::vector_front()
{
    return arr[0];
}
int& myVector::vector_back()
{
    return arr[size - 1];
}
int myVector::vector_size()
{
    return size;
}
void myVector::print_vector()
{
    for (int i = 0; i < vector_size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    myVector mv;
    mv.vector_new(4);

    int m;
    cout << "Enter elements. For exit, enter 0;" << endl;
    cin >> m;
    while (m != 0)
    {
        mv.vector_push_back(m);
        cin >> m;
    }

    mv.print_vector();
    cout << "First element: " << mv.vector_front() << endl;
    cout << "Last element " << mv.vector_back() << endl;

    cout << "Size " << mv.vector_size() << endl;
    cout << "Capacity " << mv.capacity << endl;

    cout << "Last element removed: " << endl;
    mv.vector_pop_back();
    mv.print_vector();

    mv.vector_delete();
    mv.print_vector();
}

