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
vector <cTileClassParent> Map;

int main()
{
	//srand(static_cast<unsigned int> (time(0)));
	LoadSeed("seed.txt", seed);
	LoadMap("Monopoly.txt", Map);
	srand(seed);
	unique_ptr <cTileClassParent> prt = make_unique<cTileClassParent>();
	*prt = Map.front();
	int playerCount = 0;
	for (int i = 0; i < 20; i++)
	{
		int roll = Random();
		cout << "Player Rolls " << roll << endl;
		playerCount = playerCount + roll;
		Map.at(playerCount);
		cout << "Player Land On" << endl;//  << endl;
		system("pause");
	}
	system("pause");
}