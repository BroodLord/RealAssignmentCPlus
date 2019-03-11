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
				cout << playerName << " Pay Food Bill " << "Player Loses " << POUND << "20" << endl;//  << endl;
				dogBalance -= 20;
			}
			if (ranEvent == 2)
			{
				cout << playerName << " Pay Phone Bill " << "Player Loses " << POUND << "50" << endl;
				dogBalance -= 50;
			}
			if (ranEvent == 3)
			{
				cout << playerName << " Pay Heating Bill " << "Player Loses " << POUND << "100" << endl;
				dogBalance -= 100;
			}
			if (ranEvent == 4)
			{
				cout << playerName << " Pay Vehicle Bill" << "Player Loses " << POUND << "150" << endl;
				dogBalance -= 150;
			}
			if (ranEvent == 5)
			{
				cout << playerName << " Pay Fuel Bill " << "Player Loses " << POUND << "200" << endl;
				dogBalance += 200;
			}
			if (ranEvent == 6)
			{
				cout << playerName << " Pay Windfall Tax " << "Player Loses " << POUND << "300" << endl;
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
		static int dogPropertyCountZero = 0;
		static int dogPropertyCountOne = 0;
		static int dogPropertyCountTwo = 0;
		static int dogPropertyCountThree = 0;
		static int dogPropertyCountFour = 0;
		static int dogPropertyCountFive = 0;
		static int dogPropertyCountSix = 0;
		static int dogPropertyCountSeven = 0;
		static int carPropertyCountZero = 0;
		static int carPropertyCountOne = 0;
		static int carPropertyCountTwo = 0;
		static int carPropertyCountThree = 0;
		static int carPropertyCountFour = 0;
		static int carPropertyCountFive = 0;
		static int carPropertyCountSix = 0;
		static int carPropertyCountSeven = 0;

		cout << playerName << " Land On " << tileName << endl;//  << endl;
		if (playerName == "Dog")
		{
			int counter = 0;
			if (dogIsOwner == false && carIsOwner == false)
			{
				if (dogBalance >= 0)
				{
					cout << playerName << " Buys " << tileName << " For " << POUND << tileCost << endl;
					dogBalance -= tileCost;
					cout << playerName << " now has " << POUND << dogBalance << endl;
					cout << " " << endl;
					dogIsOwner = true;

					if (tilePropertyGroup == 0 && dogPropertyCountZero < 3)
					{
						dogPropertyCountZero++;
					}
					if (tilePropertyGroup == 1 && dogPropertyCountOne < 3)
					{
						dogPropertyCountOne++;
					}
					if (tilePropertyGroup == 2 && dogPropertyCountTwo < 3)
					{
						dogPropertyCountTwo++;
					}
					if (tilePropertyGroup == 3 && dogPropertyCountThree < 3)
					{
						dogPropertyCountThree++;
					}
					if (tilePropertyGroup == 4 && dogPropertyCountFour < 3)
					{
						dogPropertyCountFour++;
					}
					if (tilePropertyGroup == 5 && dogPropertyCountFive < 3)
					{
						dogPropertyCountFive++;
					}
					if (tilePropertyGroup == 6 && dogPropertyCountSix < 4)
					{
						dogPropertyCountSix++;
					}
					if (tilePropertyGroup == 7 && dogPropertyCountSeven < 3)
					{
						dogPropertyCountSeven++;
					}
				}
			}
			if (dogPropertyCountZero == 2)
			{
				dogPropertyCountZero++;
				
				cout << "Rent for properties on Red tiles have been double for car" << endl;
				tileRent = tileRent * 2;
			}
			if (dogPropertyCountOne == 2)
			{
				dogPropertyCountOne++;
			
				cout << "Rent for properties on Grey tiles have been double for car" << endl;
				tileRent = tileRent * 2;
			}
            if (dogPropertyCountTwo == 2)
			{
				dogPropertyCountTwo++;
			
				cout << "Rent for properties on Brown tiles have been double for car" << endl;
			tileRent = tileRent * 2;
			}
			if (dogPropertyCountThree == 3)
			{
				dogPropertyCountThree++;
				
				cout << "Rent for properties on Orange tiles have been double for car" << endl;
			tileRent = tileRent * 2;
			}
			if (dogPropertyCountFour == 2)
			{
				dogPropertyCountFour++;
				
				cout << "Rent for properties on Yellow tiles have been double for car" << endl;
				tileRent = tileRent * 2;
			}
			if (dogPropertyCountFive == 2)
			{
				dogPropertyCountFive++;
				
				cout << "Rent for properties on Green tiles have been double for car" << endl;
				tileRent = tileRent * 2;
			}
			if (dogPropertyCountSix == 3)
			{
				dogPropertyCountSix++;
				
				cout << "Rent for properties on Blue tiles have been double for car" << endl;
				tileRent = tileRent * 2;
			}
			if (dogPropertyCountSeven == 2)
			{
				dogPropertyCountSeven++;
				cout << "Rent for properties on Purple tiles have been double for car" << endl;
				tileRent = tileRent * 2;
			}



			if (carIsOwner == true)
			{
				cout << playerName << " Pays Rent " << POUND << tileRent << endl;
				dogBalance -= tileRent;
				cout << playerName << " now has " << POUND << dogBalance << endl;
				cout << " " << endl;
			}
		}
		if (playerName == "Car")
		{
			int counter = 0;
			if (dogIsOwner == false && carIsOwner == false)
			{
				if (dogBalance >= 0)
				{
					cout << playerName << " Buys " << tileName << " For " << POUND << tileCost << endl;
					dogBalance -= tileCost;
					cout << playerName << " now has " << POUND << dogBalance << endl;
					cout << " " << endl;
					carIsOwner = true;
					if (tilePropertyGroup == 0 && carPropertyCountZero < 3)
					{
						carPropertyCountZero++;
					}
					if (tilePropertyGroup == 1 && carPropertyCountOne < 3)
					{
						carPropertyCountOne++;
					}
					if (tilePropertyGroup == 2 && carPropertyCountTwo < 3)
					{
						carPropertyCountTwo++;
						
					}
					if (tilePropertyGroup == 3 && carPropertyCountThree < 4)
					{
						carPropertyCountThree++;
						
					}
					if (tilePropertyGroup == 4 && carPropertyCountFour < 3)
					{
						carPropertyCountFour++;
						
					}
					if (tilePropertyGroup == 5 && carPropertyCountFive < 3)
					{
						carPropertyCountFive++;
						
					}
					if (tilePropertyGroup == 6 && carPropertyCountSix < 4)
					{
						carPropertyCountSix++;
						
					}
					if (tilePropertyGroup == 7 && carPropertyCountSeven < 3)
					{
						carPropertyCountSeven++;
					}
				}

			}
			if (carPropertyCountZero == 2)
			{
				carPropertyCountZero++;
				
				cout << "Rent for properties on Red tiles have been double for Dog" << endl;
				tileRent = tileRent * 2;
			}
			if (carPropertyCountOne == 2)
			{
				carPropertyCountOne++;
				
				cout << "Rent for properties on Grey tiles have been double for Dog" << endl;
				tileRent = tileRent * 2;
			}
			if (carPropertyCountTwo == 2)
			{
				carPropertyCountTwo++;
				
				cout << "Rent for properties on Brown tiles have been double for Dog" << endl;
				tileRent = tileRent * 2;
			}
			if (carPropertyCountThree == 3)
			{
				carPropertyCountThree++;
			
				cout << "Rent for properties on Orange tiles have been double for Dog" << endl;
				tileRent = tileRent * 2;
			}
			if (carPropertyCountFour == 2)
			{
				carPropertyCountFour++;
				
				cout << "Rent for properties on Yellow tiles have been double for Dog" << endl;
				tileRent = tileRent * 2;
			}
			if (carPropertyCountFive == 2)
			{
				carPropertyCountFive++;
				
				cout << "Rent for properties on Green tiles have been double for Dog" << endl;
				tileRent = tileRent * 2;
			}
			if (carPropertyCountSix == 3)
			{
				carPropertyCountSix++;
				
				cout << "Rent for properties on Blue tiles have been double for Dog" << endl;
				tileRent = tileRent * 2;
			}
			if (carPropertyCountSeven == 2)
			{
				dogPropertyCountSeven++;
				
				cout << "Rent for properties on Purple tiles have been double for Dog" << endl;
				tileRent = tileRent * 2;
			}
			if (dogIsOwner == true)
			{
				cout << playerName << " Pays Rent " << POUND << tileRent << endl;
				dogBalance -= tileRent;
				cout << playerName << " now has " << POUND << dogBalance << endl;
				cout << " " << endl;
			}
		}
	}

protected:
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

class cManagerClass
{
public:


	void displayWinner(int dogBalance, int carBalance)
	{
		if (dogBalance > carBalance)
		{
			cout << "Dog is the winner!" << endl;
		}
		else if (dogBalance < carBalance)
		{
			cout << "Car is the winner!" << endl;
		}
		system("pause");
	}

	void playGame(cManagerClass* Manager)
	{

		int seed;
		typedef vector <cTileClassParent*> Map;
		cPlayerOne* playerOne = new cPlayerOne();
		cPlayerTwo* playerTwo = new cPlayerTwo();
		ePlayerStates playerStates = dog;
		bool goneGo = false;
		Map map;
		LoadSeed("seed.txt", seed);
		LoadMap("Monopoly.txt", map);
		auto dogBalance = 0;
		auto carBalance = 0;
		string playerName;
		playerOne->getBalance(dogBalance);
		playerTwo->getBalance(carBalance);
		srand(10);
		int playerOnePos = 0;
		int playerTwoPos = 0;
		const int MAX = 26;
		cout << "Welcome to Monoloply" << endl;
		cout << " " << endl;
		for (auto i = 0; i < 20; i++)
		{
			cout << "Round " << i << "!" << endl;
			cout << " "  << endl;
			switch (playerStates)
			{
			case dog:
			{
				playerName = "Dog";
				int roll = Random();
				playerOnePos = playerOnePos + roll;
				cout << playerName << " Rolls " << roll << endl;
				if (playerOnePos >= 26)
				{
					map[0]->stepOn(playerOnePos, dogBalance, playerName, goneGo);
					int result = playerOnePos - MAX;
					playerOnePos = result;
				}
				map[playerOnePos]->stepOn(playerOnePos, dogBalance, playerName, goneGo);
				cout << " " << endl;													
				playerStates = car;
			}
			case car:
			{
				playerName = "Car";
				int roll = Random();
				playerTwoPos = playerTwoPos + roll;
				cout << playerName << " Rolls " << roll << endl;
				if (playerTwoPos >= 26)
				{
					map[0]->stepOn(playerTwoPos, carBalance, playerName, goneGo);
					int result = playerTwoPos - MAX;
					playerTwoPos = result;
				}
				map[playerTwoPos]->stepOn(playerTwoPos, carBalance, playerName, goneGo);
				cout << " " << endl;
				playerStates = dog;
			}
			}
		}
		Manager->displayWinner(dogBalance, carBalance);
		
	}
};