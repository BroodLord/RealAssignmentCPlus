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

//void cGoTile::stepOn()
//{
//
//}
//void cAirportTile::stepOn()
//{
//
//}
//void cBonus::stepOn()
//{
//
//}
//void cPenaltyTile::stepOn()
//{
//
//}
//void cJailTile::stepOn()
//{
//
//}
//void cGoToJailTile::stepOn()
//{
//
//}
//void cFreeParkingTile::stepOn()
//{
//
//}
//void cPropertyTiles::stepOn()
//{
//
//}

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

int LoadMap(const char* mapDetails, std::vector <cTileClassParent> &Map)
{
	std::ifstream file;
	file.open(mapDetails);
	if (file.is_open())
	{
		for (int i = 0; i < 26; i++)
		{
			int group;
			string name;
			int cost = 0;
			int rent = 0;
			int propertyGroup = 0;
			file >> group;
			if (group == 1)
			{
				unique_ptr <cTileClassParent> tempRow (new cTileClassParent);
				int counter = 0;
				string temp;
				while (counter <= 2)
				{
					getline(file, name, ' ');
					counter++;
					if (counter == 3)
					{
						name = (temp + " " + name);
					}
					temp = name;
				}
				file >> cost;
				file >> rent;
				file >> propertyGroup;
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			else
			{
				unique_ptr <cTileClassParent> tempRow(new cTileClassParent);
				getline(file, name);
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
		}
	}
	return 0;
}