#include "stdafx.h"
#include "cPropertyTile.h"

/*Property Data Member*/

	/* This is a setter to set all the variables to function parameters */
	void cPropertyTiles::mSetValues(int group, string name, int cost, int rent, int propertyGroup, bool dogOwned, bool carOwned)
	{
		mTileGroup = group;
		mTileName = name;
		mTileCost = cost;
		mTileRent = rent;
		mTilePropertyGroup = propertyGroup;
		mDogIsOwner = dogOwned;
		mCarIsOwner = carOwned;
	}
	void cPropertyTiles::mStepOn(int &playerPos, int &dogBalance, int &carBalance, string &playerName, bool &goneGo) // Polymorhpic function used in the class
	{
		/* These are counters which will increment when a property is bought, so that rent can be double */
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
		/************************************************************************************************/

		cout << playerName << " Land On " << mTileName << endl; // Lets the play know where they have landed
		if (playerName == "Dog") // checks to see if the current player is Dog
		{
			//int counter = 0; // sets the counter to 0
			/* Checks to see if dog and car are owners */
			if (mDogIsOwner == false && mCarIsOwner == false)
			{
				if (dogBalance >= 0) // checks to see if the balance is greater then 0;
				{
					cout << playerName << " Buys " << mTileName << " For " << POUND << mTileCost << endl; // lets the player know they have bought the property
					dogBalance -= mTileCost; // takes the cost away from the balance
					cout << playerName << " now has " << POUND << dogBalance << endl; // lets the player know what the current balance is
					cout << " " << endl; // new line
					mDogIsOwner = true; // set onwer to dog

					/* These if statements are used to check what colour the property is and if the counter is less then the max, if so it will increase
					   the assiacted counter to show the property is owned*/
					if (mTilePropertyGroup == Red && dogPropertyCountZero < MAX_COUNTER)
					{
						dogPropertyCountZero++;
					}
					if (mTilePropertyGroup == Grey && dogPropertyCountOne < MAX_COUNTER)
					{
						dogPropertyCountOne++;
					}
					if (mTilePropertyGroup == Brown && dogPropertyCountTwo < MAX_COUNTER)
					{
						dogPropertyCountTwo++;
					}
					if (mTilePropertyGroup == Orange && dogPropertyCountThree < MAX_COUNTER_ALT)
					{
						dogPropertyCountThree++;
					}
					if (mTilePropertyGroup == Yellow && dogPropertyCountFour < MAX_COUNTER)
					{
						dogPropertyCountFour++;
					}
					if (mTilePropertyGroup == Green && dogPropertyCountFive < MAX_COUNTER)
					{
						dogPropertyCountFive++;
					}
					if (mTilePropertyGroup == Blue && dogPropertyCountSix < MAX_COUNTER_ALT)
					{
						dogPropertyCountSix++;
					}
					if (mTilePropertyGroup == Purple && dogPropertyCountSeven < MAX_COUNTER)
					{
						dogPropertyCountSeven++;
					}
					/*****************************************************************************************/
				}
			}
			/* These if statements are used to double rent, if the counter is equal to the max then it will double the rent of the propertys on that tile colour
			   This will only double rent if its equal to the max and if it is it will increment one last to so it only runs the code once*/
			if (dogPropertyCountZero == MAX_CHECK)
			{
				dogPropertyCountZero++;

				cout << "Rent for properties on Red tiles have been double for car" << endl;
				mTileRent = mTileRent * 2;
			}
			if (dogPropertyCountOne == MAX_CHECK)
			{
				dogPropertyCountOne++;

				cout << "Rent for properties on Grey tiles have been double for car" << endl;
				mTileRent = mTileRent * 2;
			}
			if (dogPropertyCountTwo == MAX_CHECK)
			{
				dogPropertyCountTwo++;

				cout << "Rent for properties on Brown tiles have been double for car" << endl;
				mTileRent = mTileRent * 2;
			}
			if (dogPropertyCountThree == MAX_CHECK_ALT)
			{
				dogPropertyCountThree++;

				cout << "Rent for properties on Orange tiles have been double for car" << endl;
				mTileRent = mTileRent * 2;
			}
			if (dogPropertyCountFour == MAX_CHECK)
			{
				dogPropertyCountFour++;

				cout << "Rent for properties on Yellow tiles have been double for car" << endl;
				mTileRent = mTileRent * 2;
			}
			if (dogPropertyCountFive == MAX_CHECK)
			{
				dogPropertyCountFive++;

				cout << "Rent for properties on Green tiles have been double for car" << endl;
				mTileRent = mTileRent * 2;
			}
			if (dogPropertyCountSix == MAX_CHECK_ALT)
			{
				dogPropertyCountSix++;

				cout << "Rent for properties on Blue tiles have been double for car" << endl;
				mTileRent = mTileRent * 2;
			}
			if (dogPropertyCountSeven == MAX_CHECK)
			{
				dogPropertyCountSeven++;
				cout << "Rent for properties on Purple tiles have been double for car" << endl;
				mTileRent = mTileRent * 2;
			}
			/***********************************************************************************************/



			if (mCarIsOwner == true) // checks to see if the car is the owner
			{
				cout << playerName << " Pays Rent " << POUND << mTileRent << endl; // makes the dog pay rent
				dogBalance -= mTileRent; // takes rent away from balance
				carBalance += mTileRent;
				cout << playerName << " now has " << POUND << dogBalance << endl; // tells the user what they have left
				cout << " " << endl; // new line
			}
		}
		if (playerName == "Car")
		{
			/* This block of code is the same as the above apart from its switchs the players so this is the car's turn */
			if (mDogIsOwner == false && mCarIsOwner == false)
			{
				if (carBalance >= 0)
				{
					cout << playerName << " Buys " << mTileName << " For " << POUND << mTileCost << endl;
					carBalance -= mTileCost;
					cout << playerName << " now has " << POUND << carBalance << endl;
					cout << " " << endl;
					mCarIsOwner = true;

					/* These if statements are used to check what colour the property is and if the counter is less then the max, if so it will increase
					   the assiacted counter to show the property is owned*/
					if (mTilePropertyGroup == Red && carPropertyCountZero < MAX_COUNTER)
					{
						carPropertyCountZero++;
					}
					if (mTilePropertyGroup == Grey && carPropertyCountOne < MAX_COUNTER)
					{
						carPropertyCountOne++;
					}
					if (mTilePropertyGroup == Brown && carPropertyCountTwo < MAX_COUNTER)
					{
						carPropertyCountTwo++;

					}
					if (mTilePropertyGroup == Orange && carPropertyCountThree < MAX_COUNTER_ALT)
					{
						carPropertyCountThree++;

					}
					if (mTilePropertyGroup == Yellow && carPropertyCountFour < MAX_COUNTER)
					{
						carPropertyCountFour++;

					}
					if (mTilePropertyGroup == Green && carPropertyCountFive < MAX_COUNTER)
					{
						carPropertyCountFive++;

					}
					if (mTilePropertyGroup == Blue && carPropertyCountSix < MAX_COUNTER_ALT)
					{
						carPropertyCountSix++;

					}
					if (mTilePropertyGroup == Purple && carPropertyCountSeven < MAX_COUNTER)
					{
						carPropertyCountSeven++;
					}
				}

			}
			/* These if statements are used to double rent, if the counter is equal to the max then it will double the rent of the propertys on that tile colour
			   This will only double rent if its equal to the max and if it is it will increment one last to so it only runs the code once*/
			if (carPropertyCountZero == MAX_CHECK)
			{
				carPropertyCountZero++;

				cout << "Rent for properties on Red tiles have been double for Dog" << endl;
				mTileRent = mTileRent * 2;
			}
			if (carPropertyCountOne == MAX_CHECK)
			{
				carPropertyCountOne++;

				cout << "Rent for properties on Grey tiles have been double for Dog" << endl;
				mTileRent = mTileRent * 2;
			}
			if (carPropertyCountTwo == MAX_CHECK)
			{
				carPropertyCountTwo++;

				cout << "Rent for properties on Brown tiles have been double for Dog" << endl;
				mTileRent = mTileRent * 2;
			}
			if (carPropertyCountThree == MAX_CHECK_ALT)
			{
				carPropertyCountThree++;

				cout << "Rent for properties on Orange tiles have been double for Dog" << endl;
				mTileRent = mTileRent * 2;
			}
			if (carPropertyCountFour == MAX_CHECK)
			{
				carPropertyCountFour++;

				cout << "Rent for properties on Yellow tiles have been double for Dog" << endl;
				mTileRent = mTileRent * 2;
			}
			if (carPropertyCountFive == MAX_CHECK)
			{
				carPropertyCountFive++;

				cout << "Rent for properties on Green tiles have been double for Dog" << endl;
				mTileRent = mTileRent * 2;
			}
			if (carPropertyCountSix == MAX_CHECK_ALT)
			{
				carPropertyCountSix++;

				cout << "Rent for properties on Blue tiles have been double for Dog" << endl;
				mTileRent = mTileRent * 2;
			}
			if (carPropertyCountSeven == MAX_CHECK)
			{
				dogPropertyCountSeven++;

				cout << "Rent for properties on Purple tiles have been double for Dog" << endl;
				mTileRent = mTileRent * MAX_CHECK;
			}
			/*******************************************************************************************/
			if (mDogIsOwner == true)
			{
				cout << playerName << " Pays Rent " << POUND << mTileRent << endl;
				dogBalance += mTileRent;
				carBalance -= mTileRent;
				cout << playerName << " now has " << POUND << carBalance << endl;
				cout << " " << endl;
			}
		}
	}