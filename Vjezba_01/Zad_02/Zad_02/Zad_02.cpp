﻿#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using std::cout;
using std::endl;

struct matrix
{
    int m;
    int n;
    int a;
    int b;
    int** two_dim_arr;
};


void input(matrix* arr, int z)
{
    cout << "Enter m and n:" << endl;
    cin >> arr[z].m;
    cin >> arr[z].n;
    cout << "Enter a and b:" << endl;
    cin >> arr[z].a;
    cin >> arr[z].b;
    cout << endl;
}

void generating(matrix* arr, int z)
{
    int member;
    if (z == 5 || z == 6) // 5 stands for transposed matrix
    {
        // Declare memory block of size m
        arr[z].two_dim_arr = new int* [arr[z - 5].n];

        for (int counter = 0; counter < arr[z - 5].n; counter++)
        {
            // Declare a memory block of size n
            arr[z].two_dim_arr[counter] = new int[arr[counter].m];
        }
    }
    if (z == 3) //3 stands for multiplication
    {
        // Declare memory block of size m
        arr[z].two_dim_arr = new int* [arr[0].m];

        for (int counter = 0; counter < arr[1].n; counter++)
        {
            // Declare a memory block of size n
            arr[z].two_dim_arr[counter] = new int[arr[counter].n];
        }
    }

    if (z == 2 || z == 4) //2 stands for addition, 4 stands for subtraction
    {
        // Declare memory block of size m
        arr[z].two_dim_arr = new int* [arr[0].m];

        for (int counter = 0; counter < arr[0].m; counter++)
        {
            // Declare a memory block of size n
            arr[z].two_dim_arr[counter] = new int[arr[counter].n];
        }
    }

    if (z < 2) //2 stands for 2 input matrixes
    {
        arr[z].two_dim_arr = new int* [arr[z].m];

        for (int counter = 0; counter < arr[z].m; counter++)
        {
            // Declare a memory block of size n
            arr[z].two_dim_arr[counter] = new int[arr[counter].n];
        }

        // Traverse the 2D array
        srand(time(NULL));

        for (int i = 0; i < arr[z].m; i++)
        {
            for (int j = 0; j < arr[z].n; j++)
            {
                // Assign values to the memory blocks created

                member = rand() % (arr[z].b - arr[z].a) + arr[z].a;
                arr[z].two_dim_arr[i][j] = member;
            }
        }

        // Traverse the 2D array
        for (int i = 0; i < arr[z].m; i++)
        {
            for (int j = 0; j < arr[z].n; j++)
            {
                // Print the values of
                // memory blocks created
                cout << arr[z].two_dim_arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void addition(matrix* arr)
{
    //arr[0].m su retci
    //arr[0].n su stupci
    if ((arr[0].m == arr[1].m) && (arr[0].n == arr[1].n))
    {
        for (int i = 0; i < arr[1].m; ++i)
            for (int j = 0; j < arr[1].n; ++j)
            {
                arr[2].two_dim_arr[i][j] = arr[0].two_dim_arr[i][j] + arr[1].two_dim_arr[i][j];
            }
    }
    else
        cout << "The matrixes are not compatable for addition" << endl << endl;
}

void subtraction(matrix* arr)
{
    //arr[0].m su retci
    //arr[0].n su stupci
    if ((arr[0].m == arr[1].m) && (arr[0].n == arr[1].n))
    {
        for (int i = 0; i < arr[1].m; ++i)
            for (int j = 0; j < arr[1].n; ++j)
            {
                arr[4].two_dim_arr[i][j] = arr[0].two_dim_arr[i][j] - arr[1].two_dim_arr[i][j];
            }
    }
    else
        cout << "The matrixes are not compatable for subtraction" << endl << endl;
}

void multiplication(matrix* arr)
{
    if (arr[0].n == arr[1].m)
    {
        // Initializing elements of matrix to 0.
        for (int i = 0; i < arr[0].m; ++i)
            for (int j = 0; j < arr[1].n; ++j)
            {
                arr[3].two_dim_arr[i][j] = 0;
            }

        // Multiplying matrixes and storing in third matrix.
        for (int i = 0; i < arr[0].m; ++i)
            for (int j = 0; j < arr[1].n; ++j)
            {
                for (int k = 0; k < arr[0].n; ++k)
                {
                    arr[3].two_dim_arr[i][j] += arr[0].two_dim_arr[i][k] * arr[1].two_dim_arr[k][j];
                }
            }
    }
    else
        cout << "The matrixes are not compatable for multiplication" << endl << endl;
}

void transponed_matrix(matrix* arr, int trans)
{
    // Computing transpose of the matrix
    for (int i = 0; i < arr[trans].m; ++i)
        for (int j = 0; j < arr[trans].n; ++j)
        {
            arr[5 + trans].two_dim_arr[j][i] = arr[trans].two_dim_arr[i][j];
        }
}

void output(matrix* arr)
{
    if ((arr[0].m == arr[1].m) && (arr[0].n == arr[1].n))
    {
        cout << endl << "Sum of two matrixes is: " << endl;
        for (int i = 0; i < arr[0].m; ++i)
            for (int j = 0; j < arr[0].n; ++j)
            {
                cout << arr[2].two_dim_arr[i][j] << "  ";
                if (j == arr[0].n - 1)
                    cout << endl;
            }
        cout << endl;

        cout << endl << "Difference of two matrixes is: " << endl;
        for (int i = 0; i < arr[0].m; ++i)
            for (int j = 0; j < arr[0].n; ++j)
            {
                cout << arr[4].two_dim_arr[i][j] << "  ";
                if (j == arr[0].n - 1)
                    cout << endl;
            }
        cout << endl;
    }
    if (arr[0].n == arr[1].m)
    {
        cout << "Product of two matrixes is:" << endl;
        for (int i = 0; i < arr[0].m; i++)
        {
            for (int j = 0; j < arr[1].n; j++)
            {
                cout << arr[3].two_dim_arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    for (int trans = 0; trans < 2; trans++)
    {
        // Printing the transpose
        cout << "Transpose of the " << trans + 1 << ". Matrix is:" << endl;
        for (int i = 0; i < arr[trans].n; ++i)
            for (int j = 0; j < arr[trans].m; ++j)
            {
                cout << " " << arr[5 + trans].two_dim_arr[i][j];
                if (j == arr[trans].m - 1)
                    cout << endl << endl;
            }
    }

}

int main()
{
    //Creating an array of 7 matrixes
    int number_or_matrixes = 7;
    matrix* arr = new matrix[7];

    for (int z = 0; z < number_or_matrixes; z++)
    {
        if (z < 2) //2 stands for two input matrixes
        {
            input(arr, z);
        }
        generating(arr, z);
    }
    addition(arr);
    subtraction(arr);
    multiplication(arr);

    for (int trans = 0; trans < 2; trans++) //2 stands for two input matrixes
        transponed_matrix(arr, trans);

    output(arr);
}
