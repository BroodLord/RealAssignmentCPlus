#include "stdafx.h"
#include "cAirportTile.h"




	/* This is a setter that will set all the variables in the class */
	void cAirportTile::mSetValues(int group, string name, bool dogOwner, bool &carOwner)
	{
		mTileGroup = group;
		mTileName = name;
		mDogIsOwner = dogOwner;
		mCarIsOwner = carOwner;
	}
	/* This is the polymorphic function which will be used though the polymorphic class */
	void cAirportTile::mStepOn(int &playerPos, int &dogBalance, int &carBalance ,string &playerName, bool &goneGo)
	{
		cout << playerName << " Lands On " << mTileName << endl; // ouputs what the user has landed on
		if (playerName == "Dog") // If player name is equal to player_one_name it will be player one's turn.
		{
			if (mDogIsOwner == false && mCarIsOwner == false) // Checks to see if the property has been brought
			{
				if (dogBalance >= 0) // checks to see if the balance is above 0
				{
					cout << playerName << " Buys " << mTileName << " For " << POUND << mTileCost << endl; // Outputs what tile they are buying
					dogBalance -= mTileCost; // takes away the cost from the player balance
					cout << playerName << " Now Has " << POUND << dogBalance << endl; // outputs the players balance
					cout << " " << endl; // new line gap
					mDogIsOwner = true; // Sets the player to the owner.
				}
			}
			if (mCarIsOwner == true) // checks to see if player two is the onwer
			{
				cout << playerName << " Pays " << POUND << mTileCost << " For Goods " << endl; // outputs what the user is paying for
				dogBalance -= mTileFee; // takes away the fee from the balance
				cout << playerName << " Now Has " << POUND << dogBalance << endl; // tells the player what balance they have
				cout << " " << endl; // new line gap
			}
		}
		/* This if statement is the same as the above but for playerTwo */
		if (playerName == "Car")
		{
			if (mDogIsOwner == false && mCarIsOwner == false)
			{
				if (dogBalance >= 0)
				{
					cout << playerName << " Buys " << mTileName << " For " << POUND << mTileCost << endl;
					dogBalance -= mTileCost;
					cout << playerName << " Now Has " << POUND << dogBalance << endl;
					cout << " " << endl;
					mCarIsOwner = true;
				}
			}
			if (mDogIsOwner == true)
			{
				cout << playerName << " Pays " << POUND << mTileCost << " For Goods " << endl;
				dogBalance -= mTileFee;
				cout << playerName << " Now Has " << POUND << dogBalance << endl;
				cout << " " << endl;
			}
		}
		/**************************************************************/
	}
