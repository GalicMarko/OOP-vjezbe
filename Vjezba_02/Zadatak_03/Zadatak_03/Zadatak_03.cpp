// Zadatak_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Circle
{
    int Xc, Yc, R;
};

struct Rectangle
{
    int X1, Y1, X2, Y2;
};

int min(int first, int second)
{
    int minimum;

    if (first <= second)
        minimum = first;
    else
        minimum = second;

    return minimum;
}

int max(int first, int second)
{
    int maximum;

    if (first >= second)
        maximum = first;
    else
        maximum = second;

    return maximum;
}

int numberOfRectangles(Rectangle *arrayOfRectangles, Circle c, int num)
{
    int number = 0;
    int i;

    for (i = 0; i < num; ++i)
    {
        int Xn = max(arrayOfRectangles[i].X1, min(c.Xc, arrayOfRectangles[i].X2));
        int Yn = max(arrayOfRectangles[i].Y1, min(c.Yc, arrayOfRectangles[i].Y2));
        int Dx = Xn - c.Xc;
        int Dy = Yn - c.Yc;

        if ((Dx * Dx + Dy * Dy) <= c.R * c.R)
            number++;
    }
    
    return number;
}

int main()
{
    int num;
    Rectangle arrayOfRectangles[100];

    cout << "Number of rectangles: " << endl;
    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        Rectangle r;

        cout << "Input coordinates of first point: " << endl;
        cin >> r.X1;
        cin >> r.Y1;
        cout << "Input coordinates of second point: " << endl;
        cin >> r.X2;
        cin >> r.Y2;

        arrayOfRectangles[i] = r;
    }

    Circle c;

    cout << "Input coordinates of centre and radius of a circle: " << endl;
    cin >> c.Xc;
    cin >> c.Yc;
    cin >> c.R;

    cout << numberOfRectangles(arrayOfRectangles, c, num) << endl;
}

