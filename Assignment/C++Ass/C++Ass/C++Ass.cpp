// C++Ass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <ctime>
#include "defs.h"

using namespace std;

int Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

int seed;
vector <cTileClassParent> Map;

int main()
{
	//srand(static_cast<unsigned int> (time(0)));
	LoadSeed("seed.txt", seed);
	LoadMap("Monopoly.txt", Map);
	srand(seed);
	for (int i = 0; i < 20; i++)
	{
		cout << "Rolls " << ": " << Random() << endl;
		i + Random();
	}
	system("pause");
}