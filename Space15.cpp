/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 15 of 25 in the game
*/

#include "Space15.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space15::Space15()
{
	name = "Crypt";
	shortForm = "The room is filled with candles that were used up long ago and a plethora of \n"
	"intricately painted pots and vases. In the center of the room is a large tomb\n";
	longForm = "The room is filled with candles that were used up long ago and a plethora of \n"
	"intricately painted pots and vases. In the center of the room is a large tomb \n\n"
	"To the west is a doorway to leads to a dimly lit corridor \n";
	id = 15;
	obj = new Steel();
	combatEncounter = false;
	visited = false;
}

Space15::~Space15()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
