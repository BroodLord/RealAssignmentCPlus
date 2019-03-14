#pragma once
#include "cClassParent.h"
#include <iostream>
#include <string>

using namespace std;

class cBonus : public cTileClassParent // This class inferntence for the base class
{
public:
	// This is a setter so the variable are set in the class
	void mSetValues(int group, string name);

	void mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo); // This is the polymorphic function used in the base class
	
protected:
	/* Variables for the class */
	int mTileGroup;
	string mTileName;
};

