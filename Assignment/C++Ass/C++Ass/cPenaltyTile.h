#pragma once
#include "cClassParent.h"
#include <iostream>
#include <string>


using namespace std;

class cPenaltyTile : public cTileClassParent // This class infertence for the parent class
{
public:
	/* This is a setter to set the variable inside the class */
	void mSetValues(int group, string name);
	
	void mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo); // The infertened function class

private:
	/* Variables for the class */
	int mTileGroup;
	string mTileName;
};
