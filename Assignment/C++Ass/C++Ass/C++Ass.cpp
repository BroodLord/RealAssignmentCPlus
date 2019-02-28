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
vector <cTileClassParent*> Map;
cPlayerOne* playerOne = new cPlayerOne();
cPlayerTwo* playerTwo = new cPlayerTwo();
ePlayerStates playerStates = dog;

int main()
{
	//srand(static_cast<unsigned int> (time(0)));
	LoadSeed("seed.txt", seed);
	LoadMap("Monopoly.txt", Map);
	int dogBalance = 0;
	int carBalance = 0;
	string playerName;
	playerOne->getBalance(dogBalance);
	playerTwo->getBalance(carBalance);
	srand(seed);
	int playerOnePos = 0;
	int playerTwoPos = 0;
	int max = 26;
	cout << "Welcome to Monoloply" << endl;
	cout << " " << endl;
	for (int i = 0; i < 20; i++)
	{
		switch (playerStates)
		{
		case dog:
		{
			playerName = "Dog";
			int roll = Random();
			playerOnePos = playerOnePos + roll;
			if (playerOnePos >= 26)
			{
				Map[0]->stepOn(playerOne, playerTwo, playerOnePos, dogBalance, carBalance, playerName, playerOnePos);
				int result = playerOnePos - max;
				playerOnePos = result;
			}
			cout << playerName << " Rolls " << roll << endl;
			Map[playerOnePos]->stepOn(playerOne, playerTwo, playerOnePos, dogBalance, carBalance, playerName, playerOnePos);
			cout << " " << endl;
			playerStates = car;
		}
			break;
		case car:
		{
			playerName = "Car";
			int roll = Random();
			playerTwoPos = playerTwoPos + roll;
			if (playerTwoPos >= 26)
			{
				Map[0]->stepOn(playerOne, playerTwo, playerTwoPos, dogBalance, carBalance, playerName, playerTwoPos);
				int result = playerTwoPos - max;
				playerTwoPos = result;
			}
			cout << playerName << " Rolls " << roll << endl;
			Map[playerTwoPos]->stepOn(playerOne, playerTwo, playerTwoPos, dogBalance, carBalance, playerName, playerTwoPos);
			cout << " " << endl;
			playerStates = dog;
		}
			break;
		}
	}
	system("pause");
}