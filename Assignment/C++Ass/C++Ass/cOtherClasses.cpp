#include "stdafx.h"
#include "cOtherClasses.h"
#include "defs.h"



	/* This is a setter that will set that starting balance */
	void cPlayerOne::getBalance(int &balance)
	{
		balance = playerBalance;
	}

/* This is the same class as player one but for player two, no changes made */


	void cPlayerTwo::getBalance(int &balance)
	{
		balance = playerBalance;
	}

	/* This is a simple function which will display the winner of the game.
	   It does this by comparing balance and declaring a winner off it. */
	void cManagerClass::mDisplayWinner(int dogBalance, int carBalance)
	{
		if (dogBalance > carBalance)
		{
			cout << "Dog is the winner!" << endl;
		}
		else if (dogBalance < carBalance)
		{
			cout << "Car is the winner!" << endl;
		}
		if (dogBalance == carBalance)
		{
			cout << "Its a Draw!" << endl;
		}
		system("pause");
	}

	// This is my main function used in the program, this allows for the main game to run through it
	void cManagerClass::mPlayGame(cManagerClass* pManager)
	{

		int seed; // This will hold the seed that Random products
		typedef vector <cTileClassParent*> Map; // This the vector in which I hold the tiles
		cPlayerOne* pPlayerOne = new cPlayerOne(); // pointer to the player class
		cPlayerTwo* pPlayerTwo = new cPlayerTwo(); // pointer to the player class
		ePlayerStates playerStates = dog; // sets the enum to dog
		bool goneGo = false; // used for the go bool, to stop go happening twice
		Map map; // This is the vector
		LoadSeed("seed.txt", seed); // This will get the seed and place it in seed.
		LoadMap("Monopoly.txt", map); // This will put all the tiles into map
		auto dogBalance = 0; // sets the balance to 0
		auto carBalance = 0; // ^^
		string playerName; // string to hold player name
		pPlayerOne->getBalance(dogBalance); // gets the balance
		pPlayerTwo->getBalance(carBalance); // gets the balance
		srand(seed); // Sets the sRand to see
		int playerOnePos = 0; // sets the postion to 0
		int playerTwoPos = 0; // ^^^
		cout << "Welcome to Monoloply" << endl; // generic welcome
		cout << " " << endl;
		/* This for loop will run the whole game for start to finish till the end of the game */
		for (auto i = 0; i < MAX_TURNS; i++)
		{
			cout << "//////////////////////////////////////////////////////////" << endl;
			cout << "Round " << i + 1 << "!" << endl; // says what round it is
			cout << " " << endl;
			switch (playerStates) // Switch statment for the states
			{
			case dog:
			{
				playerName = "Dog"; // sets the playername to dog
				int roll = Random(); // roll will hold the number generated for Random
				playerOnePos = playerOnePos + roll; // Updates the player pos
				cout << playerName << " Rolls " << roll << endl; // couts what the player rolls
				if (playerOnePos >= MAX) // checks to see if the player is greater then the max
				{
					map[0]->mStepOn(playerOnePos, dogBalance, carBalance,playerName, goneGo); // polymorphic funcation to go Go tile
					int result = playerOnePos - MAX; // sets the new position of the player
					playerOnePos = result; // sets the pos to the new pos
				}
				map[playerOnePos]->mStepOn(playerOnePos, dogBalance, carBalance ,playerName, goneGo); // polymorphic function to where playerpos is
				cout << " " << endl;
				playerStates = car; // sets player state to car so they can take there turn.
			}
			/* This is the same as the above but with the car instead of the dog */
			case car:
			{
				playerName = "Car";
				int roll = Random();
				playerTwoPos = playerTwoPos + roll;
				cout << playerName << " Rolls " << roll << endl;
				if (playerTwoPos >= MAX)
				{
					map[0]->mStepOn(playerTwoPos, dogBalance, carBalance, playerName, goneGo);
					int result = playerTwoPos - MAX;
					playerTwoPos = result;
				}
				map[playerTwoPos]->mStepOn(playerTwoPos, dogBalance, carBalance,playerName, goneGo);
				cout << " " << endl;
				playerStates = dog;
				cout << "At the end of Round " << i + 1 << endl;
				cout << "Dog Has " << POUND << dogBalance << endl;
				cout << "Car Has " << POUND << carBalance << endl;
				cout << "//////////////////////////////////////////////////////////" << endl;
				cout << " " << endl;
			}
			}
			/*************************************************/
		}
		pManager->mDisplayWinner(dogBalance, carBalance); // This will run through the displayWinner function.

	}

