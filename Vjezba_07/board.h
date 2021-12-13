#pragma once

#include <iostream>
#ifndef BOARD_H
#define BOARD_H
#define min(a, b) ((a)>(b)? (b): (a))
#define max(a, b) ((a)>(b)? (a): (b))
using namespace std;

struct Point 
{
	double x, y;

	Point(int a, int b)
	{
		x = a;
		y = b;
	}
};

class Board
{
	public:
		char c;
		int X, Y;
		char** matrix;

		void emptyMatrix(char** matrix);

		Board() 
		{
			X = 10;
			Y = 10;
			c = 'o';

			matrix = new char*[X];

			for (int num = 0; num < X; num++)
			{
				matrix[num] = new char[Y];
			}

			emptyMatrix(matrix);

			for (int i = 0; i < X; i++)
			{
				draw_char(i, 0, c);
				draw_char(i, Y - 1, c);
			}

			for (int i = 0; i < Y; i++)
			{
				draw_char(0, i, c);
				draw_char(X - 1, i, c);
			}
		}

		Board(int x, int y) 
		{
			X = x;
			Y = y;
			c = 'o';
			
			matrix = new char*[X];

			for (int num = 0; num < X; num++)
			{
				matrix[num] = new char[Y];
			}

			emptyMatrix(matrix);

			for (int i = 0; i < X; i++) 
			{
				draw_char(i, 0, c);
				draw_char(i, Y - 1, c);
			}

			for (int i = 0; i < Y; i++) 
			{
				draw_char(0, i, c);
				draw_char(X - 1, i, c);
			}
		}
		
		~Board();

		void draw_char(int x, int y, char c);
		void draw_up_line(Point p);
		void draw_line(Point p1, Point p2, char ch);
		void display();
};

#endif
