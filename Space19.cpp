/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 19 of 25 in the game
*/

#include "Space19.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space19::Space19()
{
	name = "Volcano Lvl. 5";
	shortForm = "The air is thick with ash. The trial stops at another landing. In thee face of the \n"
	"volcano you can see a small locked compartment. Beside it hangs a blue key, red key ,\n"
	"and a green key.\n";
	longForm = "The air is thick with ash. The trial stops at another landing. In thee face of the \n"
	"volcano you can see a small locked compartment. Beside it hangs a blue key, red key ,\n"
	"and a green key.\n\n"
	"The path to the east continues up the volcano. \n";
	id = 19;
	obj = new Key();
	combatEncounter = false;
	visited = false;
}

Space19::~Space19()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
