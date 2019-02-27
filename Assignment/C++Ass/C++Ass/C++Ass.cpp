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

int main()
{
	//srand(static_cast<unsigned int> (time(0)));
	LoadSeed("seed.txt", seed);
	LoadMap("Monopoly.txt", Map);
	srand(seed);
	int playerCount = 0;
	int max = 26;
	for (int i = 0; i < 20; i++)
	{
		int roll = Random();
		playerCount = playerCount + roll;
		if (playerCount >= 26)
		{
			cout << "Player Crosses over Go" << endl;
			cout << "Player collects £200" << endl;
			cout << " " << endl;
			
			int result = playerCount - max;
			playerCount = result;
		}
		Map[playerCount]->stepOn(playerOne, playerTwo);
		cout << "Player Rolls " << roll << endl;
		cout << " " << endl;
	}
	system("pause");
}