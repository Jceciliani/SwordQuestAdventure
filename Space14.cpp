/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 14 of 25 in the game
*/

#include "Space14.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space14::Space14()
{
	name = "Mausoleum";
	shortForm = "There is sparse light in the corridor. The walls seem to be etched with something. \n"
	"The floor of the room feels slightly uneven";
	longForm = "There is sparse light in the corridor. The walls seem to be etched with something. \n"
	"The floor of the room feels slightly uneven \n\n"
	"To the west is the entrance to the corridor \n"
	"To the east is a doorway to a small room\n";
	id = 14;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space14::~Space14()
{}
