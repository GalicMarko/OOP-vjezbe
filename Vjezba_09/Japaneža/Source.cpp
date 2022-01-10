#include <iostream>
#include "Japaneža.h"
using namespace std;

int main()
{
	int match;

	cout << "Press 1 for PvP match or 2 for AI match: ";
	cin >> match;
	cout << endl;

	if (match == 1)
	{
		Player::HumanPlayer hp1, hp2;
		Game g;
		
		g.PvPMatch(hp1, hp2);
	}

	if (match == 2)
	{
		Player::HumanPlayer hp;
		Player::ComputerPlayer cp;
		Game g;

		g.AIMatch(hp, cp);
	}
}