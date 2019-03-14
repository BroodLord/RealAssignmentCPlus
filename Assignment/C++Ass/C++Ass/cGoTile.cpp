#include "stdafx.h"
#include "cGoTile.h"
#include <iostream>
#include <string>

using namespace std;

void cGoTile::mSetValues(int group, string name)
{
	mTileGroup = group;
	mTileName = name;
}

void cGoTile::mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo)
{
	if (playerName == "Dog")
	{
		if (playerPos == 0) // Checks to see if the current position is the go tile
		{
			if (goneGo == false)
			{
				cout << playerName << " Lands On " << mTileName << endl; // Output what tile they land on
				cout << playerName << " Collects " << POUND << mGO_AMOUNT << endl; // Output what the player collects
				dogBalance += mGO_AMOUNT; // adds the amount to the dogBalance
				cout << playerName << " Now Has " << POUND << dogBalance << endl; // output whats the player now has
				cout << " " << endl; // New Line gap
				goneGo = false; // Used so when the player gos over go or lands on go so it doesn't repeat adding to balance
			}
			else
			{
				cout << playerName << " Lands on " << mTileName << endl; // outputs what tile they  have landed on;
				cout << playerName << " Has " << POUND << dogBalance << endl; // output whats the player now has
				goneGo = false; // same as above use
			}
		}
		if (playerPos > 25) // checks to see if the player has gone over the end of the board
		{
			cout << playerName << " Passes Over " << mTileName << endl; // Output what tile they land on
			cout << playerName << " Collects " << POUND << mGO_AMOUNT << endl; // Output what the player collects
			dogBalance += mGO_AMOUNT; // adds the amount to the dogBalance
			cout << playerName << " Now Has " << POUND << dogBalance << endl; // output whats the player now has
			cout << " " << endl; // New Line Gap
			goneGo = true; // Makes it so that if the player lands on go they won't collect money again

		}
	}
	if (playerName == "Car")
	{
		if (playerPos == 0) // Checks to see if the current position is the go tile
		{
			if (goneGo == false)
			{
				cout << playerName << " Lands On " << mTileName << endl; // Output what tile they land on
				cout << playerName << " Collects " << POUND << mGO_AMOUNT << endl; // Output what the player collects
				carBalance += mGO_AMOUNT; // adds the amount to the dogBalance
				cout << playerName << " Now Has " << POUND << carBalance << endl; // output whats the player now has
				cout << " " << endl; // New Line gap
				goneGo = false; // Used so when the player gos over go or lands on go so it doesn't repeat adding to balance
			}
			else
			{
				cout << playerName << " Lands on " << mTileName << endl; // outputs what tile they  have landed on;
				cout << playerName << " Has " << POUND << carBalance << endl; // output whats the player now has
				goneGo = false; // same as above use
			}
		}
		if (playerPos > 25) // checks to see if the player has gone over the end of the board
		{
			cout << playerName << " Passes Over " << mTileName << endl; // Output what tile they land on
			cout << playerName << " Collects " << POUND << mGO_AMOUNT << endl; // Output what the player collects
			carBalance += mGO_AMOUNT; // adds the amount to the dogBalance
			cout << playerName << " Now Has " << POUND << carBalance << endl; // output whats the player now has
			cout << " " << endl; // New Line Gap
			goneGo = true; // Makes it so that if the player lands on go they won't collect money again

		}
	}
}


