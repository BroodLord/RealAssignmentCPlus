#include "stdafx.h"
#include "defs.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

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
			int propertyGroup = 10;
			file >> group;
			if (group == 1)
			{
				unique_ptr <cTileClassParent> tempRow(new cPropertyTiles);
				file >> name;
				string temp = name;
				file >> name;
				name = (temp + " " + name);
				file >> cost;
				file >> rent;
				file >> propertyGroup;
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			if (group == 2)
			{
				unique_ptr <cTileClassParent> tempRow(new cGoTile);
				file >> name;
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			if (group == 3)
			{
				unique_ptr <cTileClassParent> tempRow(new cAirportTile);
				file >> name;
				string temp = name;
				file >> name;
				name = (temp + " " + name);
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			if (group == 4)
			{
				unique_ptr <cTileClassParent> tempRow(new cBonus);
				file >> name;
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			if (group == 5)
			{
				unique_ptr <cTileClassParent> tempRow(new CPenaltyTile);
				file >> name;
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			if (group == 6)
			{
				unique_ptr <cTileClassParent> tempRow(new cJailTile);
				file >> name;
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			if (group == 7)
			{
				unique_ptr <cTileClassParent> tempRow(new cGoToJailTile);
				file >> name;
				string temp = name;
				file >> name;
				name = (temp + " " + name);
				file >> temp;
				name = (name + " " + temp);
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			if (group == 8)
			{
				unique_ptr <cTileClassParent> tempRow(new cFreeParkingTile);
				file >> name;
				string temp = name;
				file >> name;
				name = (temp + " " + name);
				tempRow->setValues(group, name, cost, rent, propertyGroup);
				Map.push_back(*tempRow);
			}
			
		}

	}
	return 0;
}