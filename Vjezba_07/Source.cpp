#include <iostream>
#include "Board.h"
using namespace std;

int main()
{
	int x, y;
	Point p1(3, 3), p2(8, 8);
	
	cout << "Horizontal size of matrix: ";
	cin >> x;
	cout << "Vertical size of matrix: ";
	cin >> y;
	cout << endl;
	
	Board b(x, y);

	b.draw_up_line(p1);
	b.draw_line(p1, p2);
	b.display();
}