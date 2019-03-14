#pragma once
#include "cClassParent.h"
#include <string>
#include <iostream>

using namespace std;

/*Property Data Member*/
class cPropertyTiles : public cTileClassParent
{
public:
	/* This is a setter to set all the variables to function parameters */
	void mSetValues(int group, string name, int cost, int rent, int propertyGroup, bool dogOwned, bool carOwned);

	void mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo); // Polymorhpic function used in the class

protected:
	/* Variables of the class */
	string mTileName;
	int mTileCost;
	int mTileRent;
	int mTileGroup;
	int mTilePropertyGroup;
	bool mDogIsOwner = false;
	bool mCarIsOwner = false;
	const int MAX_COUNTER = 3;
	const int MAX_COUNTER_ALT = 4;
	const int MAX_CHECK = 2;
	const int MAX_CHECK_ALT = 3;
};
