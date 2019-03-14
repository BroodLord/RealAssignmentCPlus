#pragma once
#include "cClassParent.h"
#include <iostream>
#include <string>

using namespace std;

class cJailTile : public cTileClassParent // This class infertence for the parent class
{
public:
	/* setter function to set the values in the class */
	void mSetValues(int group, string name);

	void mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo); // polymorphic function used for the class

protected:
	/* variables for the class */
	int mTileGroup;
	string mTileName;
};
