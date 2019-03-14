#include "stdafx.h"
#include "defs.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "cBonus.h"
#include "cAirportTile.h"
#include "cFreeParking.h"
#include "cGoTile.h"
#include "cJailTile.h"
#include "cGoToJailTile.h"
#include "cPropertyTile.h"
#include "cPenaltyTile.h"

using namespace std;

/* This will return a random number which will be used in, bonus, pentaly and srand */
int Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

/* This will open the file and load the number in the file and put it into seedvalue */
int LoadSeed(const char* inputSeed, int &seedValue)
{
	std::ifstream file;
	file.open(inputSeed); // opens file
	if (file.is_open())
	{
		file >> seedValue; // puts the value into seedvalue
		return true;
	}
	else
	{
		return false;
	}

}

/* This function reads in the file and will put into the vector and store the data in the class its set to */
int LoadMap(const char* mapDetails, std::vector <cTileClassParent*> &Map)
{
	std::ifstream file;
	file.open(mapDetails); // opens the file
	if (file.is_open())
	{
		for (auto i = 0; i < MAX; i++)
		{
			/* Variables used in the class to be set */
			int group;
			int cost = 0;
			int rent = 0;
			int propertyGroup = 0;
			bool dogOwned = false;
			bool carOwned = false;
			string name;
			/****************************************/
			file >> group; // reads in the file
			if (group == property) // check to see if the number is equal to property
			{
				cPropertyTiles* pPropertyPtr = new cPropertyTiles(); // Pointer to the property class
				string temp; // used to temperally hold a string
				getline(file, name, ' ');
				getline(file, name, ' ');
				getline(file, temp, ' ');
				name = name + " " + temp; // adds the name and temp togther to get a name.
				/* Reads in the data to the variables */
				file >> cost;
				file >> rent;
				file >> propertyGroup;
				dogOwned = false;
				carOwned = false;
				/****************************************/
				pPropertyPtr->mSetValues(group, name, cost, rent, propertyGroup, dogOwned, carOwned); // Sets the values in the class
				Map.push_back(pPropertyPtr); //pushes back the prt in the vector

			}
			if (group == go) // check to see if the number is equal to go.
			{
				/* This create a pointer and read in the file data, then set the values and push the ptr onto the vector */
				cGoTile* prt = new cGoTile();
				getline(file, name);
				prt->mSetValues(group, name);
				Map.push_back(prt);

			}
			if (group == airport) // checks to see if the number is equal to airport
			{
				/* This create a pointer and read in the file data, then set the values and push the ptr onto the vector */
				cAirportTile* prt = new cAirportTile();
				getline(file, name);
				dogOwned = false;
				carOwned = false;
				prt->mSetValues(group, name, dogOwned, carOwned);
				Map.push_back(prt);
			}
			if (group == bonus) // This checks to see if the number is equal to bonus
			{
				/* This create a pointer and read in the file data, then set the values and push the ptr onto the vector */
				cBonus* prt = new cBonus();
				getline(file, name);
				prt->mSetValues(group, name);
				Map.push_back(prt);
			}
			if (group == penalty) // checks to see if the number is equal to penalty
			{
				/* This create a pointer and read in the file data, then set the values and push the ptr onto the vector */
				cPenaltyTile* prt = new cPenaltyTile();
				getline(file, name);
				prt->mSetValues(group, name);
				Map.push_back(prt);
			}
			if (group == jail) // checks to see if the number is equal to jail
			{
				/* This create a pointer and read in the file data, then set the values and push the ptr onto the vector */
				cJailTile* prt = new cJailTile();
				getline(file, name);
				prt->mSetValues(group, name);
				Map.push_back(prt);
			}
			if (group == gotojail) // check to see if the number is equal to go to jail
			{
				/* This create a pointer and read in the file data, then set the values and push the ptr onto the vector */
				cGoToJailTile* prt = new cGoToJailTile();
				getline(file, name);
				prt->mSetValues(group, name);
				Map.push_back(prt);
			}
			if (group == freeparking) // This checks to see if the number is equal to free parking
			{
				/* This create a pointer and read in the file data, then set the values and push the ptr onto the vector */
				cFreeParkingTile* prt = new cFreeParkingTile();
				getline(file, name);
				prt->mSetValues(group, name);
				Map.push_back(prt);
			}
		}
	}
	return 0;
}