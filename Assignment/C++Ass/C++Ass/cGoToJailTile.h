#pragma once
#include "cClassParent.h"
#include <string>
#include <iostream>

using namespace std;

class cGoToJailTile : public cTileClassParent // This class infertence from the parent class
{
public:
	/* setter to set the values in the class */
	void mSetValues(int group, string name);

	void mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo); // polymorphic function used for the class

private:
	/* variables of the class */
	int mTileGroup;
	string mTileName;
};

