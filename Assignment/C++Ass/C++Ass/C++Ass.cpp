// C++Ass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <ctime>
#include "defs.h"

using namespace std;

int main()
{
	cManagerClass* Manager = new cManagerClass();
	Manager->playGame(Manager);
}