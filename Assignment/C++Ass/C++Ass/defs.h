#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "cClassParent.h"

using namespace std;


int LoadSeed(const char* inputSeed, int &seedValue); // will return a seed for the sRand;
int LoadMap(const char* mapDetails, vector <cTileClassParent*> &Map); // will return the map with all the tiles in the vector
