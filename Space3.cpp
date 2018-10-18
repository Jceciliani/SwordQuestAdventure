/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 3 of 25 in the game
*/

#include "Space3.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space3::Space3()
{
	name = "Space3";
	shortForm = "The sewer walkways are grimy and slick. It's not hard to imagine with what. \n
	There appears to be a fishing basket of some kind in the sewer waterway.";
	longForm = "The sewer walkways are grimy and slick. It's not hard to imagine with what. \n
	There appears to be a fishing basket of some kind in the sewer waterway. \n\n
	To the south are stairs leading up to a door \n
	Down the walkways to the east there is bright light and an opening to outside \n";
	id = 3;
	obj = new Bronze_Armor();
	combatEncounter = false;
	visited = false;
}

Space3::~Space3()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
