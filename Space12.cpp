/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 12 of 25 in the game
*/

#include "Space12.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space12::Space12()
{
	name = "Crossroads";
	shortForm = "In the center of the room is a signpost. Along the western wall is a small fenced-off plot of dirt.\n"
		"To the north there is a path slowly encroached by brush of the Swamp \n"
		"To the south there is a path that slopes upwards through the Volcano Foothills \n"
		"To the east there is a well lit corridor back to the Sanctuary \n";
	longForm = "The floor has dissipated from solid stone to a coarse dirt. The room is deceptively \n"
		"large. If not for the walls and ceiling you'd feel like you were outside. In the center of\n"
		"the room is a signpost. Along the western wall is a small fenced-off plot of dirt.\n\n"
		"To the north there is a path slowly encroached by brush of the Swamp \n"
		"To the south there is a path that slopes upwards through the Volcano Foothills \n"
		"To the east there is a well lit corridor back to the Sanctuary \n";

	id = 12;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space12::~Space12()
{}

void Space12::look(const char* thing)
{
	if (strcmp(thing, "plot") == 0)
	{
		cout << "A plot of dirt. The ground look fresher here than outside the fence. Maybe" << endl;
		cout << "someone is trying to grow something? I wonder what?" << endl;
	}
	else if (strcmp(thing, "sign") == 0)
	{
		cout << "A small worn signpost. And in a dungeon? How big is this place? The sign pointed" << endl;
		cout << "North reads SWAMP: CAREFUL OF THE PIRAHNAS" << endl;
		cout << "South sign reads VOLCANO: CAREFUL OF LEVERS" << endl;
		cout << "East sign reads SANCTUARY: CAREFUL OF FLOORS" << endl;
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space12::dig(const char* thing)
{
	if (strcmp(thing, "plot") == 0)
	{
		cout << "You get down on your hands and knees and start digging through the plot, hoping to find something." << endl;
		cout << "This action feels oddly familiar. Like you've done this exact thing before. You start to remember" << endl;
		cout << "you used to be a farmer..." << endl;
		cout << "but then something crashed into some nearby ruins..." << endl;
		cout << "you went to check it out..." << endl;
		cout << "but then..." << endl;
		cout << "then..." << endl;
		cout << "no idea. But you can figure it out when you make it out of here!" << endl;

	}

	else
	{
		cout << "You can't do that" << endl;
	}
}
