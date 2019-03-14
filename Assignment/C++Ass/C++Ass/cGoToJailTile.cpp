#include "stdafx.h"
#include "cGoToJailTile.h"


	/* setter to set the values in the class */
	void cGoToJailTile::mSetValues(int group, string name)
	{
		mTileGroup = group;
		mTileName = name;
	}
	void cGoToJailTile::mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo) // polymorphic function used for the class
	{
		if (playerName == "Dog")
		{
			cout << playerName << " Land On" << mTileName << endl;//  lets the user know where they have landed
			cout << playerName << " Goes To Jail " << endl; // tells the player they are being moved
			playerPos = 6; // moves the current player to the jail tile
			cout << playerName << " Pays " << POUND << "50" << endl; // tells the user they pay x amount to leave jail
			dogBalance -= 50; // takes away the fee from balance
			cout << playerName << " now has " << POUND << dogBalance << endl; // lets the player know how much money they have left
			cout << " " << endl; // new line
		}
		if (playerName == "Car")
		{
			cout << playerName << " Land On" << mTileName << endl;//  lets the user know where they have landed
			cout << playerName << " Goes To Jail " << endl; // tells the player they are being moved
			playerPos = 6; // moves the current player to the jail tile
			cout << playerName << " Pays " << POUND << "50" << endl; // tells the user they pay x amount to leave jail
			carBalance -= 50; // takes away the fee from balance
			cout << playerName << " now has " << POUND << carBalance << endl; // lets the player know how much money they have left
			cout << " " << endl; // new line
		}
	}

