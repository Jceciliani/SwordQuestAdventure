/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 10 of 25 in the game
*/

#include "Space10.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space10::Space10()
{
	name = "Upper Maintenance";
	shortForm = "You arrive on the end of the walkway. There it is a moderately sized stone \n"
	"platform. In the corner you see a small hovel made of bone,. Metal scraps, and literal shit.";
	longForm = "You arrive on the end of the walkway. There it is a moderately sized stone \n"
	"platform. In the corner you see a small hovel made of bone,. Metal scraps, and literal shit. \n\n"
	"To the west there is a walkway \n"
	"To the north is a ladder leading down\n";
	id = 10;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space10::~Space10()
{}
