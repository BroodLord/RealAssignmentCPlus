#include "stdafx.h"
#include "cPenaltyTile.h"

using namespace std;

	/* This is a setter to set the variable inside the class */
	void cPenaltyTile::mSetValues(int group, string name)
	{
		mTileGroup = group;
		mTileName = name;
	}
	void cPenaltyTile::mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo) // The infertened function class
	{
		if (playerName == "Dog")
		{
			cout << playerName << " Land On" << mTileName << endl; // This outputs the current poisition
			int ranEvent = Random(); // This sets ranEvent to a random number
			/* This is used when the random event is triggered, This bassically gets the random number and checks if its equal to a certain number then it
			will do the certain action listed below, each if has its own output statment to the console and adds a certain number to the balance*/
			if (ranEvent == 1)
			{
				cout << playerName << " Pay Food Bill " << "Player Loses " << POUND << "20" << endl;//  << endl;
				dogBalance -= 20;
			}
			if (ranEvent == 2)
			{
				cout << playerName << " Pay Phone Bill " << "Player Loses " << POUND << "50" << endl;
				dogBalance -= 50;
			}
			if (ranEvent == 3)
			{
				cout << playerName << " Pay Heating Bill " << "Player Loses " << POUND << "100" << endl;
				dogBalance -= 100;
			}
			if (ranEvent == 4)
			{
				cout << playerName << " Pay Vehicle Bill" << "Player Loses " << POUND << "150" << endl;
				dogBalance -= 150;
			}
			if (ranEvent == 5)
			{
				cout << playerName << " Pay Fuel Bill " << "Player Loses " << POUND << "200" << endl;
				dogBalance += 200;
			}
			if (ranEvent == 6)
			{
				cout << playerName << " Pay Windfall Tax " << "Player Loses " << POUND << "300" << endl;
				dogBalance += 300;
			}
			cout << playerName << " now has " << POUND << dogBalance << endl; // lets the player know what money they have left
			cout << " " << endl; // new line gap
		}
		if (playerName == "Car")
		{
			cout << playerName << " Land On" << mTileName << endl; // This outputs the current poisition
			int ranEvent = Random(); // This sets ranEvent to a random number
			/* This is used when the random event is triggered, This bassically gets the random number and checks if its equal to a certain number then it
			will do the certain action listed below, each if has its own output statment to the console and adds a certain number to the balance*/
			if (ranEvent == 1)
			{
				cout << playerName << " Pay Food Bill " << "Player Loses " << POUND << "20" << endl;//  << endl;
				carBalance -= 20;
			}
			if (ranEvent == 2)
			{
				cout << playerName << " Pay Phone Bill " << "Player Loses " << POUND << "50" << endl;
				carBalance -= 50;
			}
			if (ranEvent == 3)
			{
				cout << playerName << " Pay Heating Bill " << "Player Loses " << POUND << "100" << endl;
				carBalance -= 100;
			}
			if (ranEvent == 4)
			{
				cout << playerName << " Pay Vehicle Bill" << "Player Loses " << POUND << "150" << endl;
				carBalance -= 150;
			}
			if (ranEvent == 5)
			{
				cout << playerName << " Pay Fuel Bill " << "Player Loses " << POUND << "200" << endl;
				carBalance += 200;
			}
			if (ranEvent == 6)
			{
				cout << playerName << " Pay Windfall Tax " << "Player Loses " << POUND << "300" << endl;
				carBalance += 300;
			}
			cout << playerName << " now has " << POUND << carBalance << endl; // lets the player know what money they have left
			cout << " " << endl; // new line gap
		}
	}

