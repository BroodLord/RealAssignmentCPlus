#pragma once
#include "cClassParent.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

enum ePlayerStates // Enum for the different players of the games
{
	dog,
	car
};

class cPlayerOne // The first player class
{
public:
	/* This is a setter that will set that starting balance */
	void getBalance(int &balance);
private:
	int playerBalance = 1500; // starting amount for player one
};
/* This is the same class as player one but for player two, no changes made */
class cPlayerTwo
{
public:
	void getBalance(int &balance);
private:
	int playerBalance = 1500;
};

class cManagerClass // This is the manager class and control everything
{
public:
	/* This is a simple function which will display the winner of the game.
	   It does this by comparing balance and declaring a winner off it. */
	void mDisplayWinner(int dogBalance, int carBalance);

	// This is my main function used in the program, this allows for the main game to run through it
	void mPlayGame(cManagerClass* pManager);
};
