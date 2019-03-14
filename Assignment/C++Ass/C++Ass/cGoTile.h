#pragma once
#include "cClassParent.h"
#include <iostream>

using namespace std;

class cGoTile : public cTileClassParent // This is the go tile, infertences for the parent class
{
public:
	/* This is a setter to set the varibles inside the class */
	void mSetValues(int group, string name);

	/* This is the function in which the polymorpihc class will go if the tile is go. */
	void mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo);

protected:
	int mTileGroup; // Used so see what group the tile belongs to
	string mTileName; // The name of the tile
	const int mGO_AMOUNT = 200; // The amount collected when go activates
};

