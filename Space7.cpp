/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 7 of 25 in the game
*/

#include "Space7.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space7::Space7()
{
	name = "Swamp";
	shortForm = "The room is covered in moss and vegetation. Majority of the room is submerged\n"
	"in a murky liquid. There is a narrow rope bridge that crosses to the eastern wall. A small \n"
	"mossy island is in the middle of the room";
	longForm = "The room is covered in moss and vegetation. Majority of the room is submerged\n"
	"in a murky liquid. There is a narrow rope bridge that crosses to the eastern wall. A small \n"
	"mossy island is in the middle of the room \n\n"
	"To the east is a small opening through the brush \n"
	"To the south is path thick with vegetation\n";
	id = 7;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space7::~Space7()
{}
