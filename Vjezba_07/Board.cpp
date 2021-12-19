#include <iostream>
#include "Board.h";
using namespace std;

void Board::draw_char(Point p, char c)
{
	int roundedX = round(p.x);
	int roundedY = round(p.y);

	matrix[roundedX][roundedY] = c;
}

void Board::draw_up_line(Point p)
{
	for (int i = 1; i < horizontalSize - 1; ++i)
	{
		for (int j = 0; j < verticalSize; ++j)
		{
			if (i != p.y && j == p.x)
			{
				matrix[i][j] = 'x';
			}
		}
	}
}

void Board::draw_line(Point p1, Point p2)
{
	for (int i = 1; i < horizontalSize - 1; ++i)
	{
		for (int j = 1; j < verticalSize - 1; ++j)
		{
			if (((j == ((p2.y - p1.y) / (p2.x - p1.x)) * (i - p1.x) + p1.y)) && (i > p1.x && i < p2.x))
				matrix[i][j] = 'x';
		}
	}
}

void Board::display()
{
	for (int i = 0; i < horizontalSize; ++i)
	{
		for (int j = 0; j < verticalSize; ++j)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

