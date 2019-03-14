#pragma once
#include "cClassParent.h"
#include <iostream>
#include <string>

using namespace std;

class cAirportTile : public cTileClassParent // The airport tile which inferntence for the parent class
{
public:
	/* This is a setter that will set all the variables in the class */
	void mSetValues(int group, string name, bool dogOwner, bool &carOwner);
	
	/* This is the polymorphic function which will be used though the polymorphic class */
	void mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo);
	

protected:
	int mTileGroup; // grouping of the tile
	string mTileName; // tile name
	int mTileCost = 200; // tile cost
	int mTileFee = 10; // tile fee
	bool mDogIsOwner = false; // used to check if dog is owner
	bool mCarIsOwner = false; // used to check if car is owner
};

