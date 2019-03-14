#include "stdafx.h"
#include "cFreeParking.h"


	/* Setter to set the values in the class */
	void cFreeParkingTile::mSetValues(int group, string name)
	{
		mTileGroup = group;
		mTileName = name;
	}
	void cFreeParkingTile::mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo) // This is a polymorphic function which is used in the class
	{
		cout << playerName << " Land On" << mTileName << endl;// tells the user where they have landed
		cout << playerName << " Is Resting " << endl; // genertic output messeage.
	}

