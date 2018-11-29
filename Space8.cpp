/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 8 of 25 in the game
*/

#include "Space8.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space8::Space8()
{
	name = "Guard Quarters";
	shortForm = "There are papers strewn across the desk. There are a collection of lockers along the west wall\n";
	longForm = "You find an office of some sort, moldy from the dampness that hangs in the air. \n"
		"There are papers strewn across the desk. There are a collection of lockers along the west wall \n\n";

	id = 8;
	obj = new Two_Handed_Bronze_Sword();
	combatEncounter = false;
	visited = false;
	swordFound = false;
	taken = false;
}

Space8::~Space8()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space8::look(const char* thing)
{
	if (strcmp(thing, "papers") == 0 || strcmp(thing, "desk") == 0)
		{
		cout << "The papers strewn across the desk seem to be schedules for the guards," << endl;
		cout << "albeit very very old ones. It seems recently that there was only" << endl;
		cout << "one guard that was off duty. Bob - locker 13" << endl;
		}

	else if (strcmp(thing, "lockers" ) == 0)
	{
		cout << "A large number of small lockers. Around 30. Luckily they don't have locks!" << endl;
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}

void Space8::search(const char* thing)
{
	if (strcmp(thing, "lockers") == 0)
	{
		cout << "But which locker do you want to search?" << endl;
	}
	else if (strcmp(thing, "locker 1") == 0)
	{
		cout << "Nothing here" << endl;
	}

	else if (strcmp(thing, "locker 13") == 0)
	{
		if (taken == false) {
			cout << "You find a bronze sword" << endl;
			swordFound = true;
		}
		else
		{
			cout << "Nothing here" << endl;
		}
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}
