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
		cout << "the papers strewn across the desk seem to be schedules for the guards," << endl;
		cout << "albeit very very old ones. Seems that the most recent one only one guard" << endl;
		cout << "one only one guard was off duty. Bob - locker 13" << endl;
		}

	else if (strcmp(thing, "lockers" ) == 0)
	{
		cout << "a large number of small lockers. around 30. Luckily they dont have locks!" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space8::search(const char* thing)
{
	if (strcmp(thing, "lockers") == 0)
	{
		cout << "but which locker do you want to search?" << endl;
	}
	else if (strcmp(thing, "locker 1") == 0)
	{
		cout << "nothing here" << endl;
	}

	else if (strcmp(thing, "locker 13") == 0)
	{
		cout << " you find a bronze sword" << endl;
		swordFound = true;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}