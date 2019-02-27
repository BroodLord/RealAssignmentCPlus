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
	virtual ~cTileClassParent() {}
	virtual void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo) = 0;
};

/* Special Tile derviement section */


class cGoTile : public cTileClassParent
{
public:
	void setValues(int group, string name)
	{
		tileGroup = group;
		tileName = name;
	}
	void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo)
	{
		cout << "Player" << "Land On Go" << endl;//  << endl;
		
	}

private:
	int tileGroup;
	string tileName;
};
class cAirportTile : public cTileClassParent
{
public:
	void setValues(int group, string name)
	{
		tileGroup = group;
		tileName = name;
	}
	void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo)
	{
		cout << "Airport" << endl;
	}

private:
	int tileGroup;
	string tileName;
};
class cBonus : public cTileClassParent
{
public:
	void setValues(int group, string name)
	{
		tileGroup = group;
		tileName = name;
	}
	void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo)
	{
		cout << "Bonus" << endl;
	}

private:
	int tileGroup;
	string tileName;
};
class cPenaltyTile : public cTileClassParent
{
public:
	void setValues(int group, string name)
	{
		tileGroup = group;
		tileName = name;
	}
	void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo)
	{
		cout << "Penalty" << endl;
	}

private:
	int tileGroup;
	string tileName;
};
class cJailTile : public cTileClassParent
{
public:
	void setValues(int group, string name)
	{
		tileGroup = group;
		tileName = name;
	}
	void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo)
	{
		cout << "Jail" << endl;
	}

private:
	int tileGroup;
	string tileName;
};
class cGoToJailTile : public cTileClassParent
{
public:
	void setValues(int group, string name)
	{
		tileGroup = group;
		tileName = name;
	}
	void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo)
	{
		cout << "Go to Jail" << endl;
	}

private:
	int tileGroup;
	string tileName;
};
class cFreeParkingTile : public cTileClassParent
{
public:
	void setValues(int group, string name)
	{
		tileGroup = group;
		tileName = name;
	}
	void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo)
	{
		cout << "Free Parking" << endl;
	}

private:
	int tileGroup;
	string tileName;

};
/*************************************/
/*Property Data Member*/
class cPropertyTiles : public cTileClassParent
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
	void stepOn(cPlayerOne* playerOne, cPlayerTwo* playerTwo)
	{
		cout << "Property" << endl;
	}

private:
	string tileName;
	int tileCost;
	int tileRent;
	int tileGroup;
	int tilePropertyGroup;
};
int LoadSeed(const char* inputSeed, int &seedValue);
int LoadMap(const char* mapDetails, vector <cTileClassParent*> &Map);
int Random();