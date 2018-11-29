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
	name = "Volcanic Chamber";
	shortForm = "You reach a small platform in the middle of the burning lake. \n"
	"The stalagtites spark from the heat.\n";
	longForm = "You reach a small platform in the middle of the burning lake. Noxious gases slowly bubble to the magmas surface \n"
		"You won't last long in this heat. The stalagtites spark from the heat. The rock formations litter the small island\n\n";

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
			cout << "a lake made of lava. you are in a volcano after all. trying to go any closer to it" << endl;
			cout << "would not bode well for you." << endl;
	}
	else if(strcmp(thing, "stalagtite") == 0)
	{
			cout << "small towers of a weird black substance. they seem to spark everyso often. they seem" << endl;
			cout << "like they would be easy enough to break if you needed to" << endl;
	}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space25::attack(const char* thing)
{
	if (strcmp(thing, "stalagtite") == 0)
	{
			cout << "you swing down with your sword at one of the stalagtites. upon impact a shower of sparks" << endl;
			cout << "erupts from it. a large chunk of the stalagtite falls to the ground. from what just occured" << endl;
			cout << "you can guess that they are made of flint" << endl;
			flintFound = true;
			if (taken == true) {
				cout << "you really dont need anymore of it though" << endl;
			}
	}

	else
		{
			cout << "you cant do that" << endl;
		}
}
