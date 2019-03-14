#include "stdafx.h"
#include "cBonus.h"


	// This is a setter so the variable are set in the class
	void cBonus::mSetValues(int group, string name)
	{
		mTileGroup = group;
		mTileName = name;
	}
	void cBonus::mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo) // This is the polymorphic function used in the base class
	{
		cout << playerName << " Land On" << mTileName << endl;//  lets the user know where they have landed
		int ranEvent = Random(); // This returns a random number and stores it in ranEvent

		/* This is used when the random event is triggered, This bassically gets the random number and checks if its equal to a certain number then it
		will do the certain action listed below, each if has its own output statment to the console and adds a certain number to the balance*/
		if (playerName == "Dog")
		{
			if (ranEvent == 1)
			{
				cout << playerName << " Find Some Money " << "Player Gains " << POUND << "20" << endl;//  << endl;
				dogBalance += 20;
			}
			if (ranEvent == 2)
			{
				cout << playerName << " Win Competition " << "Player Gains " << POUND << "50" << endl;
				dogBalance += 50;
			}
			if (ranEvent == 3)
			{
				cout << playerName << " Tax Rebeate " << "Player Gains " << POUND << "100" << endl;
				dogBalance += 100;
			}
			if (ranEvent == 4)
			{
				cout << playerName << " Win Lottery " << "Player Gains " << POUND << "150" << endl;
				dogBalance += 150;
			}
			if (ranEvent == 5)
			{
				cout << playerName << " Bequest " << "Player Gains " << POUND << "200" << endl;
				dogBalance += 200;
			}
			if (ranEvent == 6)
			{
				cout << playerName << " Birthday " << "Player Gains " << POUND << "300" << endl;
				dogBalance += 300;
			}
			cout << playerName << " now has " << POUND << dogBalance << endl; // ouputs the current amount of money player has
			cout << " " << endl; // new line gap
		}
		if (playerName == "Car")
		{
			if (ranEvent == 1)
			{
				cout << playerName << " Find Some Money " << "Player Gains " << POUND << "20" << endl;//  << endl;
				carBalance += 20;
			}
			if (ranEvent == 2)
			{
				cout << playerName << " Win Competition " << "Player Gains " << POUND << "50" << endl;
				carBalance += 50;
			}
			if (ranEvent == 3)
			{
				cout << playerName << " Tax Rebeate " << "Player Gains " << POUND << "100" << endl;
				carBalance += 100;
			}
			if (ranEvent == 4)
			{
				cout << playerName << " Win Lottery " << "Player Gains " << POUND << "150" << endl;
				carBalance += 150;
			}
			if (ranEvent == 5)
			{
				cout << playerName << " Bequest " << "Player Gains " << POUND << "200" << endl;
				carBalance += 200;
			}
			if (ranEvent == 6)
			{
				cout << playerName << " Birthday " << "Player Gains " << POUND << "300" << endl;
				carBalance += 300;
			}
			cout << playerName << " now has " << POUND << dogBalance << endl; // ouputs the current amount of money player has
			cout << " " << endl; // new line gap
		}
	}