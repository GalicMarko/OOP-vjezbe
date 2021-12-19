#pragma once

#include <iostream>
#ifndef BOARD_H
#define BOARD_H
using namespace std;

struct Point
{
	double x, y;

	Point(double a, double b)
	{
		x = a;
		y = b;
	}
};

class Board
{
	public:
		int horizontalSize, verticalSize;
		char borderChar;
		char** matrix;

		void draw_char(Point p, char c);
		void draw_up_line(Point p);
		void draw_line(Point p1, Point p2);
		void display();

		//defaultni konstruktor//
		Board()
		{
			horizontalSize = 10;
			verticalSize = 10;
			borderChar = 'O';

			matrix = new char*[horizontalSize];

			for (int i = 0; i < horizontalSize; ++i)
			{
				matrix[i] = new char[verticalSize];
			}


			for (int i = 0; i < horizontalSize; ++i)
			{
				for (int j = 0; j < verticalSize; ++j)
				{
					if ((i >= 0 && i <= horizontalSize - 1 && j == 0) || (i == horizontalSize - 1 && j >= 1 && j <= verticalSize - 1) || (i >= 0 && i <= horizontalSize - 2 && j == verticalSize - 1) || (i == 0 && j >= 1 && j <= verticalSize - 2))
						matrix[i][j] = borderChar;
					else
						matrix[i][j] = ' ';
				}
			}
		}
		
		//konstruktor s argumentima//
		Board(int x, int y)
		{
			horizontalSize = x;
			verticalSize = y;
			borderChar = 'O';

			matrix = new char*[horizontalSize];

			for (int i = 0; i < horizontalSize; ++i)
			{
				matrix[i] = new char[verticalSize];
			}


			for (int i = 0; i < horizontalSize; ++i)
			{
				for (int j = 0; j < verticalSize; ++j)
				{
					if ((i >= 0 && i <= horizontalSize - 1 && j == 0) || (i == horizontalSize - 1 && j >= 1 && j <= verticalSize - 1) || (i >= 0 && i <= horizontalSize - 2 && j == verticalSize - 1) || (i == 0 && j >= 1 && j <= verticalSize - 2))
						matrix[i][j] = borderChar;
					else
						matrix[i][j] = ' ';
				}
			}
		}

		//copy konstruktor//
		Board(const Board &b)
		{
			int x = b.horizontalSize;
			int y = b.verticalSize;
			char ch = b.borderChar;
			char** m = b.matrix;
		}

		//move konstruktor//
		Board(Board&& board)
		{
			int rows = board.horizontalSize;
			int columns = board.verticalSize;
			matrix = board.matrix;

			board.matrix = nullptr;
			board.horizontalSize = 0;
			board.verticalSize = 0;
		}

		//destruktor//
		~Board()
		{
			for (int i = 0; i < horizontalSize; ++i)
			{
				delete[] matrix[i];
			}

			delete[] matrix;

			delete& horizontalSize;
			delete& verticalSize;
			delete& borderChar;
		}
};

#endif
