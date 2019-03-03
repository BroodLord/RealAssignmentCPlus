#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

const char POUND = 156;
int Random();

enum ePlayerStates
{
	dog,
    car
};

class cPlayerOne
{
public:
	void getBalance(int &balance)
	{
		balance = playerBalance;
	}
private:
	int playerBalance = 1500;
};
class cPlayerTwo
{
public:
	void getBalance(int &balance)
	{
		balance = playerBalance;
	}
private:
	int playerBalance = 1500;
};

class cTileClassParent
{
public:
	virtual ~cTileClassParent() {}
	virtual void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo) = 0;
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
	void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo)
	{
			if (playerPos == 0)
			{
				if (goneGo == false)
				{
					cout << playerName << " Land On" << tileName << endl;//  << endl;
					cout << playerName << " collects " << POUND << "200" << endl;
					dogBalance += 200;
					cout << playerName << " now has " << POUND << dogBalance << endl;
					cout << " " << endl;
					goneGo = false;
				}
				else
				{
					cout << playerName << " Land On" << tileName << endl;//  << endl;
					goneGo = false;
				}
			}
			if (playerPos > 25)
			{
				cout << playerName << " Passes over" << tileName << endl;
				cout << playerName << " collects " << POUND << "200" << endl;
				dogBalance += 200;
				cout << playerName << " now has " << POUND << dogBalance << endl;
				cout << " " << endl;
				goneGo = true;

			}
	}

private:
	int tileGroup;
	string tileName;
};
class cAirportTile : public cTileClassParent
{
public:
	void setValues(int group, string name, bool dogOwner, bool &carOwner)
	{
		tileGroup = group;
		tileName = name;
		dogIsOwner = dogOwner;
		carIsOwner = carOwner;
	}
	void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo)
	{
		cout << playerName << " Land On" << tileName << endl;//  << endl;
		if (playerName == "Dog")
		{
			if (dogIsOwner == false && carIsOwner == false)
			{
				if (dogBalance >= 0)
				{
					cout << playerName << " Buys " << tileName << " For " << POUND << tileCost << endl;
					dogBalance -= tileCost;
					cout << playerName << " now has " << POUND << dogBalance << endl;
					cout << " " << endl;
					dogIsOwner = true;
				}
			}
			if (carIsOwner == true)
			{
				cout << playerName << " Pays" << POUND << tileCost << "For Goods " << endl;
				dogBalance -= tileFee;
				cout << playerName << " now has " << POUND << dogBalance << endl;
				cout << " " << endl;
			}
		}
		if (playerName == "Car")
		{
			if (dogIsOwner == false && carIsOwner == false)
			{
				if (dogBalance >= 0)
				{
					cout << playerName << " Buys " << tileName << " For " << POUND << tileCost << endl;
					dogBalance -= tileCost;
					cout << playerName << " now has " << POUND << dogBalance << endl;
					cout << " " << endl;
					carIsOwner = true;
				}
			}
			if (dogIsOwner == true)
			{
				cout << playerName << " Pays " << POUND << tileCost << "For Goods " << endl;
				dogBalance -= tileFee;
				cout << playerName << " now has " << POUND << dogBalance << endl;
				cout << " " << endl;
			}
		}
	}

private:
	int tileGroup;
	int tileCost = 200;
	int tileFee = 10;
	bool dogIsOwner = false;
	bool carIsOwner = false;
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
	void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo)
	{
		cout << playerName << " Land On" << tileName << endl;//  << endl;
		int ranEvent = Random();
			if (ranEvent == 1)
			{
				cout << playerName << " Find Some Money " << "Player Gains " << POUND << "20" << endl;//  << endl;
				dogBalance += 20;
			}
			if (ranEvent == 2)
			{
				cout << playerName << " Win Competition " << "Player Gains " << POUND << "50" << endl;
				dogBalance += 50;
			}
			if (ranEvent == 3)
			{
				cout << playerName << " Tax Rebeate " << "Player Gains " << POUND << "100" << endl;
				dogBalance += 100;
			}
			if (ranEvent == 4)
			{
				cout << playerName << " Win Lottery " << "Player Gains " << POUND << "150" << endl;
				dogBalance += 150;
			}
			if (ranEvent == 5)
			{
				cout << playerName << " Bequest " << "Player Gains " << POUND << "200" << endl;
				dogBalance += 200;
			}
			if (ranEvent == 6)
			{
				cout << playerName << " Birthday " << "Player Gains " << POUND << "300" << endl;
				dogBalance += 300;
			}
			cout << playerName << " now has " << POUND << dogBalance << endl;
			cout << " " << endl;
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
	void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo)
	{
		cout << playerName << " Land On" << tileName << endl;//  << endl;
		int ranEvent = Random();
			if (ranEvent == 1)
			{
				cout << playerName << " Find Some Money " << "Player Gains " << POUND << "20" << endl;//  << endl;
				dogBalance += 20;
			}
			if (ranEvent == 2)
			{
				cout << playerName << " Win Competition " << "Player Gains " << POUND << "50" << endl;
				dogBalance += 50;
			}
			if (ranEvent == 3)
			{
				cout << playerName << " Tax Rebeate " << "Player Gains " << POUND << "100" << endl;
				dogBalance += 100;
			}
			if (ranEvent == 4)
			{
				cout << playerName << " Win Lottery " << "Player Loses " << POUND << "150" << endl;
				dogBalance += 150;
			}
			if (ranEvent == 5)
			{
				cout << playerName << " Bequest " << "Player Gains " << POUND << "200" << endl;
				dogBalance += 200;
			}
			if (ranEvent == 6)
			{
				cout << playerName << " Birthday " << "Player Gains " << POUND << "300" << endl;
				dogBalance += 300;
			}
			cout << playerName << " now has " << POUND << dogBalance << endl;
			cout << " " << endl;
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
	void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo)
	{
		cout << playerName << " Land On" << tileName << endl;//  << endl;
		cout << playerName << " Just Visiting " << endl;
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
	void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo)
	{
			cout << playerName << " Land On" << tileName << endl;//  << endl;
			cout << playerName << " Goes To Jail " << endl;
			playerPos = 6;
			cout << playerName << " Pays " << POUND << "50" << endl;
			dogBalance -= 50;
			cout << playerName << " now has " << POUND << dogBalance << endl;
			cout << " " << endl;
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
	void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo)
	{
		cout << playerName << " Land On" << tileName << endl;//  << endl;
		cout << playerName << " Is Resting " << endl;
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
    void setValues(int group, string name, int cost, int rent, int propertyGroup, bool dogOwned, bool carOwned)
	{
		tileGroup = group;
		tileName = name;
		tileCost = cost;
		tileRent = rent;
		tilePropertyGroup = propertyGroup;
		dogIsOwner = dogOwned;
		carIsOwner = carOwned;
	}
	void stepOn(int &playerPos, int &dogBalance, string &playerName, bool &goneGo)
	{
		cout << playerName << " Land On " << tileName << endl;//  << endl;
		if (playerName == "Dog")
		{
			if (dogIsOwner == false && carIsOwner == false)
			{
				if (dogBalance >= 0)
				{
					cout << playerName << " Buys " << tileName << " For " << POUND << tileCost << endl;
					dogBalance -= tileCost;
					cout << playerName << " now has " << POUND << dogBalance << endl;
					cout << " " << endl;
					dogIsOwner = true;
				}
			}
			if (carIsOwner == true)
			{
				cout << playerName << " Pays Rent " << POUND << tileCost << endl;
				dogBalance -= tileRent;
				cout << playerName << " now has " << POUND << dogBalance << endl;
				cout << " " << endl;
			}
		}
		if (playerName == "Car")
		{
			if (dogIsOwner == false && carIsOwner == false)
			{
				if (dogBalance >= 0)
				{
					cout << playerName << " Buys " << tileName << " For " << POUND << tileCost << endl;
					dogBalance -= tileCost;
					cout << playerName << " now has " << POUND << dogBalance << endl;
					cout << " " << endl;
					carIsOwner = true;
				}
			}
			if (dogIsOwner == true)
			{
				cout << playerName << " Pays Rent For " << POUND << tileCost << endl;
				dogBalance -= tileRent;
				cout << playerName << " now has " << POUND << dogBalance << endl;
				cout << " " << endl;
			}
		}
	}

private:
	string tileName;
	int tileCost;
	int tileRent;
	int tileGroup;
	int tilePropertyGroup;
	bool dogIsOwner = false;
	bool carIsOwner = false;
};

int LoadSeed(const char* inputSeed, int &seedValue);
int LoadMap(const char* mapDetails, vector <cTileClassParent*> &Map);