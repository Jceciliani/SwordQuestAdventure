/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 21 of 25 in the game
*/

#include "Space21.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space21::Space21()
{
	name = "Space21";
	shortForm = "The path  widens a bit before tapering back an continuing up. Small flakes of ash \n"
	"float in the air around you. On the side of the path you see a large boulder.";
	longForm = "The path  widens a bit before tapering back an continuing up. Small flakes of ash \n"
	"float in the air around you. On the side of the path you see a large boulder. \n\n"
	"The path to the south leads back down \n"
	"The path to the east continues up the volcano \n";
	id = 21;
	obj = new Two_Handed_Gold_Sword();
	combatEncounter = false;
	visited = false;
}

Space21::~Space21()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
