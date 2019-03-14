// C++Ass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include "defs.h"
#include "cOtherClasses.h"

using namespace std;

int main()
{
	cManagerClass* pManager = new cManagerClass(); // creates a pointer of the manager class
	pManager->mPlayGame(pManager); // plays the game
}