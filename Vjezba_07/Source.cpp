#include <iostream>
#include "board.h"
using namespace std;

int main() 
{
	Point p1(1, 1), p2(11, 18);
	Point p3(9, 2), p4(6, 19);
	Board b(20, 20);

	b.draw_line(p1, p2, 'x');
	b.draw_line(p3, p4, 'x');

	b.display();
}