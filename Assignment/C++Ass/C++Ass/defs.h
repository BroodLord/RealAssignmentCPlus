#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class cPlayerOne
{
public:

private:
};
class cPlayerTwo
{
public:

private:
};

class cTileClassParent
{
public:
	void setValues(int group, string name, int cost, int rent, int propertyGroup)
	{
		tileGroup = group;
		tileName = name;
		tileCost = cost;
		tileRent = rent;
		tilePropertyGroup = propertyGroup;
	}
	
private:
	int tileGroup;
	string tileName;
	int tileCost;
	int tileRent;
	int tilePropertyGroup;
};

/* Special Tile derviement section */


class cGoTile : public cTileClassParent
{
public:

private:

};
class cAirportTile : public cTileClassParent
{
public:

private:

};
class cBonus : public cTileClassParent
{
public:

private:

};
class CPenaltyTile : public cTileClassParent
{
public:

private:

};
class cJailTile : public cTileClassParent
{
public:

private:

};
class cGoToJailTile : public cTileClassParent
{
public:

private:

};
class cFreeParkingTile : public cTileClassParent
{
public:

private:

};
/*************************************/
/*Property Data Member*/
class cPropertyTiles : public cTileClassParent
{
public:

private:

};
int LoadSeed(const char* inputSeed, int &seedValue);
int LoadMap(const char* mapDetails, std::vector <cTileClassParent> &Map);