// C++Ass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <ctime>
#include "defs.h"

using namespace std;

int seed;
typedef vector <cTileClassParent*> Map;
cPlayerOne* playerOne = new cPlayerOne();
cPlayerTwo* playerTwo = new cPlayerTwo();
ePlayerStates playerStates = dog;
bool goneGo = false;

int main()
{
	//srand(static_cast<unsigned int> (time(0)));
	static Map map;
	LoadSeed("seed.txt", seed);
	LoadMap("Monopoly.txt", map);
	auto dogBalance = 0;
	auto carBalance = 0;
	string playerName;
	playerOne->getBalance(dogBalance);
	playerTwo->getBalance(carBalance);
	srand(seed);
	int playerOnePos = 0;
	int playerTwoPos = 0;
	const int MAX = 26;
	cout << "Welcome to Monoloply" << endl;
	cout << " " << endl;
	for (auto i = 0; i < 20; i++)
	{
		switch (playerStates)
		{
		case dog:
		{
			playerName = "Dog";
			int roll = Random();
			playerOnePos = playerOnePos + roll;
			cout << playerName << " Rolls " << roll << endl;
			if (playerOnePos >= 26)
			{
				map[0]->stepOn(playerOnePos, dogBalance, playerName, goneGo);
				int result = playerOnePos - MAX;
				playerOnePos = result;
			}
			map[playerOnePos]->stepOn(playerOnePos, dogBalance, playerName, goneGo);
			cout << " " << endl;
			playerStates = car;
		}
			break;
		case car:
		{
			playerName = "Car";
			int roll = Random();
			playerTwoPos = playerTwoPos + roll;
			cout << playerName << " Rolls " << roll << endl;
			if (playerTwoPos >= 26)
			{
				map[0]->stepOn(playerTwoPos, carBalance, playerName, goneGo);
				int result = playerTwoPos - MAX;
				playerTwoPos = result;
			}
			map[playerTwoPos]->stepOn(playerTwoPos, carBalance, playerName, goneGo);
			cout << " " << endl;
			playerStates = dog;
		}
			break;
		}
	}
	if (dogBalance > carBalance)
	{
		cout << "Dog is the winner!" << endl;
	}
	else if (dogBalance < carBalance)
	{
		cout << "Car is the winner!" << endl;
	}
	system("pause");
}