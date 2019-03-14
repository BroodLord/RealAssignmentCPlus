#include "stdafx.h"
#include "cJailTile.h"



	/* setter function to set the values in the class */
	void cJailTile::mSetValues(int group, string name)
	{
		mTileGroup = group;
		mTileName = name;
	}
	void cJailTile::mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo) // polymorphic function used for the class
	{
		cout << playerName << " Land On" << mTileName << endl; // outputs to the screen where they have landed
		cout << playerName << " Just Visiting " << endl; // tells the user that they are just visiting jail.
	}
