#include "board.h"

Board::~Board()
{
	delete& X;
	delete& Y;
	delete matrix;
}


void Board::draw_char(int x, int y, char c)
{
	matrix[x][y] = c;
}

void Board::draw_up_line(Point p) 
{

}

void Board::draw_line(Point p1, Point p2, char c)
{
	int numberOfChars = max(abs(p1.x - p2.x), abs(p1.y - p2.y));
	double hypothenuse = sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
	double nthPartOfHypothenuse = hypothenuse / numberOfChars;
	double i = 0;

	cout << "p1: (" << p1.x << ", " << p1.y << ")" << endl;
	cout << "p2: (" << p2.x << ", " << p2.y << ")" << endl;
	
	//If X > Y
	
	if (abs(p1.x - p2.x) > abs(p1.y - p2.y))
	{
		if (p1.x <= p2.x && p1.y <= p2.y) 
		{
			for (int start = p1.x; start <= p1.x + numberOfChars; start++)
			{
				draw_char(start, round(p1.y + i), c);
				i += sqrt(pow(nthPartOfHypothenuse, 2) - 1);
			}
		}
		
		else if (p1.x <= p2.x && p1.y >= p2.y)
		{
			for (int start = p1.x; start <= p1.x + numberOfChars; start++)
			{
				draw_char(start, round(p1.y - i), c);
				i += sqrt(pow(nthPartOfHypothenuse, 2) - 1);
			}
		}

		else if (p1.x >= p2.x && p1.y <= p2.y)
		{
			for (int start = p1.x; start >= p1.x - numberOfChars; start--)
			{
				draw_char(start, round(p1.y + i), c);
				i += sqrt(pow(nthPartOfHypothenuse, 2) - 1);
			}
		}

		else 
		{
			for (int start = p2.x; start <= p2.x + numberOfChars; start++)
			{
				draw_char(start, round(p1.y + i), c);
				i += sqrt(pow(nthPartOfHypothenuse, 2) - 1);
			}
		}
	}

	else 
	{
		if (p1.x <= p2.x && p1.y <= p2.y)
		{
			for (int start = p1.y; start <= p1.y + numberOfChars; start++)
			{
				draw_char(round(p1.x + i), start, c);
				i += sqrt(pow(nthPartOfHypothenuse, 2) - 1);
			}
		}

		else if (p1.x <= p2.x && p1.y >= p2.y)
		{
			for (int start = p1.y; start >= p2.y - numberOfChars; start--)
			{
				draw_char(round(p1.x + i), start, c);
				i += sqrt(pow(nthPartOfHypothenuse, 2) - 1);
			}
		}

		else if (p1.x >= p2.x && p1.y <= p2.y)
		{
			for (int start = p1.y; start <= p1.y + numberOfChars; start++)
			{
				draw_char(round(p1.x - i), start, c);
				i += sqrt(pow(nthPartOfHypothenuse, 2) - 1);
			}
		}

		else 
		{
			for (int start = p2.y; start <= p2.y + numberOfChars; start++)
			{
				draw_char(round(p1.x + i), start, c);
				i += sqrt(pow(nthPartOfHypothenuse, 2) - 1);
			}
		}
	}
}

void Board::display()
{
	for (int j = 0; j < Y; j++) 
	{
		for (int i = 0; i < X; i++) 
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}

void Board::emptyMatrix(char** matrix)
{
	for (int i = 0; i < X; i++) 
	{
		for (int j = 0; j < Y; j++) 
		{
			matrix[i][j] = ' ';
		}
	}
}