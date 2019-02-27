#include "stdafx.h"
#include "defs.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

int LoadSeed(const char* inputSeed, int &seedValue)
{
	std::ifstream file;
	file.open(inputSeed);
	if (file.is_open())
	{
		file >> seedValue;
	}

	return true;
}

int LoadMap(const char* mapDetails, std::vector <cTileClassParent*> &Map)
{
	std::ifstream file;
	file.open(mapDetails);
	if (file.is_open())
	{
		for (int i = 0; i < 26; i++)
		{
			int group;
			int cost = 0;
			int rent = 0;
			int propertyGroup = 0;
			string name;
			file >> group;
			if (group == 1)
			{
				cPropertyTiles* prt = new cPropertyTiles();
				string temp;
				for (int i = 0; i < 3; i++)
				{
					getline(file, temp, ' ');
					name = name + " " + temp;
				}
				file >> cost;
				file >> rent;
				file >> propertyGroup;
				prt->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(prt);

			}
			if (group == 2)
			{
				cGoTile* prt = new cGoTile();
				getline(file, name);
				prt->setValues(group, name);
				Map.push_back(prt);

			}
			if (group == 3)
			{
				cAirportTile* prt = new cAirportTile();
				getline(file, name);
				prt->setValues(group, name);
				Map.push_back(prt);
			}
			if (group == 4)
			{
				cBonus* prt = new cBonus();
				getline(file, name);
				prt->setValues(group, name);
				Map.push_back(prt);
			}
			if (group == 5)
			{
				cPenaltyTile* prt = new cPenaltyTile();
				getline(file, name);
				prt->setValues(group, name);
				Map.push_back(prt);
			}
			if (group == 6)
			{
				cJailTile* prt = new cJailTile();
				getline(file, name);
				prt->setValues(group, name);
				Map.push_back(prt);
			}
			if (group == 7)
			{
				cGoToJailTile* prt = new cGoToJailTile();
				getline(file, name);
				prt->setValues(group, name);
				Map.push_back(prt);
			}
			if (group == 8)
			{
				cFreeParkingTile* prt = new cFreeParkingTile();
				getline(file, name);
				prt->setValues(group, name);
				Map.push_back(prt);
			}
		}
	}
	return 0;
}