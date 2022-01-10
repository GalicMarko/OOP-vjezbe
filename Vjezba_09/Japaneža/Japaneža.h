#pragma once
#include <iostream>
using namespace std;

#ifndef JAPANEZA_H
#define JAPANEZA_H

class Player
{
	public:
		class HumanPlayer
		{
			public:
				int jedna, dvi, pet;
				int sum = 0;
				int points = 0;
		};
	public:
		class ComputerPlayer
		{
			public:
				int sum;
				int points = 0;
		};
};

class Game
{
	public:
		void PvPMatch(Player::HumanPlayer hp1, Player::HumanPlayer hp2);
		void AIMatch(Player::HumanPlayer hp, Player::ComputerPlayer cp);
};

#endif