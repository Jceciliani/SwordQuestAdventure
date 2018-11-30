/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 25 of 25 in the game
*/

#include "Space25.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space25::Space25()
{
	name = "volcanic chamber";
	shortForm = "You reach a small platform in the middle of the burning lake. \n"
	"The stalactites spark from the heat.\n\n"
		"To the north you can see a steep climb back to the Volcano Summit\n";
	longForm = "You reach a small platform in the middle of the burning lake. Noxious gases slowly bubble to the magmas surface. \n"
		"You won't last long in this heat. The stalactites spark from the heat. The rock formations litter the small island\n\n"
		"To the north you can see a steep climb back to the Volcano Summit\n";

	id = 25;
	obj = new Flint();
	combatEncounter = false;
	visited = false;
	flintFound = false;
	taken = false;
}

Space25::~Space25()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
void Space25::look(const char* thing)
{
	if (strcmp(thing, "lake") == 0)
	{
			cout << "A lake made of lava. You are in a volcano after all. Trying to go any closer to it" << endl;
			cout << "would not bode well for you." << endl;
	}
	else if(strcmp(thing, "stalactite") == 0)
	{
			cout << "Small towers of a weird black substance. They seem to spark everyso often. They seem" << endl;
			cout << "like they would be easy enough to break if you needed to" << endl;
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space25::attack(const char* thing)
{
	if (strcmp(thing, "stalactite") == 0)
	{
			cout << "You swing down with your sword at one of the stalactites. Upon impact a shower of sparks" << endl;
			cout << "erupts from it. A large chunk of the stalactite falls to the ground. From what just occured" << endl;
			cout << "you can guess that they are made of flint" << endl;
			flintFound = true;
			if (taken == true) {
				cout << "You really dont need anymore of it though" << endl;
			}
	}

	else
		{
			cout << "You can't do that" << endl;
		}
}
