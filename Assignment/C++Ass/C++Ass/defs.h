#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class cPlayerOne
{
public:

private:
	int playerBalance = 1500;
};
class cPlayerTwo
{
public:

private:
	int playerBalance = 1500;
};

class cTileClassParent
{
public:
	virtual void cTileClassParent::setValues(int group, string name, int cost, int rent, int propertyGroup)
	{
		tileGroup = group;
		tileName = name;
		tileCost = cost;
		tileRent = rent;
		tilePropertyGroup = propertyGroup;
	}
	//virtual ~cTileClassParent() {}
	//virtual void stepOn() = 0;
	
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
	//void stepOn();

private:

};
class cAirportTile : public cTileClassParent
{
public:
	//void stepOn();

private:

};
class cBonus : public cTileClassParent
{
public:
	//void stepOn();

private:

};
class cPenaltyTile : public cTileClassParent
{
public:
	//void stepOn();

private:

};
class cJailTile : public cTileClassParent
{
public:
	//void stepOn();

private:

};
class cGoToJailTile : public cTileClassParent
{
public:
	//void stepOn();

private:

};
class cFreeParkingTile : public cTileClassParent
{
public:
	//void stepOn();

private:

};
/*************************************/
/*Property Data Member*/
class cPropertyTiles : public cTileClassParent
{
public:
	//void stepOn();

private:
	string tileName;
	int tileCost;
	int tileRent;
	int tileGroup;
	int tilePropertyGroup;
};
int LoadSeed(const char* inputSeed, int &seedValue);
int LoadMap(const char* mapDetails, vector <cTileClassParent> &Map);
int Random();