#include "Japaneža.h"
#include <iostream>
#include <time.h>
using namespace std;

void Game::PvPMatch(Player::HumanPlayer hp1, Player::HumanPlayer hp2)
{
	while (true)
	{
		cout << "1st Player chooses number of coins..." << endl << endl << "Number of 1kn coins: ";
		cin >> hp1.jedna;
		cout << "Number of 2kn coins: ";
		cin >> hp1.dvi;
		cout << "Number of 5kn coins: ";
		cin >> hp1.pet;
		cout << endl;

		hp1.sum += hp1.jedna + hp1.dvi * 2 + hp1.pet * 5;

		int guess;

		cout << "2nd Player makes a guess as what's total sum of coins in 1st Player's hand: ";
		cin >> guess;
		
		if (guess == hp1.sum)
			hp2.points++;

		cout << endl << hp1.points << " - " << hp2.points << endl << endl;

		if (hp2.points == 3)
		{
			cout << "2nd Player wins!" << endl;
			break;
		}

		cout << "2nd Player chooses number of coins..." << endl << endl << "Number of 1kn coins: ";
		cin >> hp2.jedna;
		cout << "Number of 2kn coins: ";
		cin >> hp2.dvi;
		cout << "Number of 5kn coins: ";
		cin >> hp2.pet;
		cout << endl;

		hp2.sum += hp2.jedna + hp2.dvi * 2 + hp2.pet * 5;

		cout << "1st Player makes a guess as what's total sum of coins in 2nd Player's hand: ";
		cin >> guess;

		if (guess == hp2.sum)
			hp1.points++;

		cout << endl << hp1.points << " - " << hp2.points << endl << endl;

		if (hp1.points == 3)
		{
			cout << "1st Player wins!" << endl;
			break;
		}

		hp1.sum = 0;
		hp2.sum = 0;
	}
}

void Game::AIMatch(Player::HumanPlayer hp, Player::ComputerPlayer cp)
{
	while (true)
	{
		cout << "Choose number of coins..." << endl << endl << "Number of 1kn coins: ";
		cin >> hp.jedna;
		cout << "Number of 2kn coins: ";
		cin >> hp.dvi;
		cout << "Number of 5kn coins: ";
		cin >> hp.pet;
		cout << endl;

		hp.sum += hp.jedna + hp.dvi * 2 + hp.pet * 5;

		cout << "Computer makes a guess as what's total sum of coins in your hand: ";
		
		srand(time(NULL));
		int possibleSums[] = { '0', '1', '2', '3', '5', '6', '7', '8' };
		int guessIndex = rand() % 8;
		int guess = possibleSums[guessIndex] - 48;

		cout << guess;

		if (guess == hp.sum)
			cp.points++;

		cout << endl << hp.points << " - " << cp.points << endl << endl;

		if (cp.points == 3)
		{
			cout << "Computer wins!" << endl;
			break;
		}

		cout << "Make a guess as what's total sum of coins in Computer's hand: ";
		cin >> guess;

		int cpSumIndex = rand() % 8;
		cp.sum = possibleSums[cpSumIndex] - 48;
		cout << cp.sum;

		if (guess == cp.sum)
			hp.points++;

		cout << endl << hp.points << " - " << cp.points << endl << endl;

		if (hp.points == 3)
		{
			cout << "You win!" << endl;
			break;
		}

		hp.sum = 0;
		cp.sum = 0;
	}
}