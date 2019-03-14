#pragma once
#include "cClassParent.h"
#include <string>
#include <iostream>

using namespace std;

class cFreeParkingTile : public cTileClassParent // this class infertnce for the parent class
{
public:
	/* Setter to set the values in the class */
	void mSetValues(int group, string name);

	void mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo); // This is a polymorphic function which is used in the class

protected:
	/* variable names */
	int mTileGroup;
	string mTileName;

};

