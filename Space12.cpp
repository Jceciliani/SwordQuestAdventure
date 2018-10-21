/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 12 of 25 in the game
*/

#include "Space12.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space12::Space12()
{
	name = "Crossroads";
	shortForm = "The floor has dissipated from solid stone to a coarse dirt. The room is deceptively \n"
	"large. If not for the walls and ceiling you'd feel like you were outside. In the center of\n"
	"the room is  a signpost. Along the western wall is a small fence off plot of dirt.";
	longForm = "The floor has dissipated from solid stone to a coarse dirt. The room is deceptively \n"
	"large. If not for the walls and ceiling you'd feel like you were outside. In the center of\n"
	"the room is  a signpost. Along the western wall is a small fence off plot of dirt.\n\n"
	"To the north there is a path slowly encroached by brush \n"
	"To the south there is a path that slopes upward \n"
	"To the east there is a well lit corridor \n";
	id = 12;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space12::~Space12()
{}
