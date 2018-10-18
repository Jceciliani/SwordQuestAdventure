/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 8 of 25 in the game
*/

#include "Space8.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space8::Space8()
{
	name = "Space8";
	shortForm = "You find an office of some sort, moldy from the dampness that hangs in the air. \n
	There are papers strewn across the desk. There are a collection of lockers along the west wall";
	longForm = "You find an office of some sort, moldy from the dampness that hangs in the air. \n
	There are papers strewn across the desk. There are a collection of lockers along the west wall \n\n
	To the north is a door labeled 'Sewers' \n
	To the east is a door labeled “Maintenance” \n
	To the south is a pair of stairs leading up\n";
	id = 8;
	obj = new Two_Handed_Bronze_Sword();
	combatEncounter = false;
	visited = false;
}

Space8::~Space8()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
