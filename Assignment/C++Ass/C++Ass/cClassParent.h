#pragma once

#include <iostream>

const char POUND = 156; // Makes the £ sign useable
const int MAX = 26; // max value of tiles
const int MAX_TURNS = 20; // max number of turns
int Random(); // Function that returns a random number

enum eTileState
{
	Red = 0, Grey = 1, Brown = 2, Orange = 3, Yellow = 4, Green = 5, Blue = 6, Purple = 7,
	property = 1, go = 2, airport = 3, bonus = 4, penalty = 5, jail = 6, gotojail = 7, freeparking = 8
};

/* This is the parent class of all the tiles on the board */
class cTileClassParent
{
public:
	virtual ~cTileClassParent() {} // Virtual deconstructer for the parent class

	/* This is a polymorphic class, this is in all the tiles on the board and main part of this game gos through this function */
	virtual void mStepOn(int &playerPos, int &dogBalance, int &carBalance, std::string &playerName, bool &goneGo) = 0;
};

