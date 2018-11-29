/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 16 of 25 in the game
*/

#include "Space16.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space16::Space16()
{
	name = "Volcano Base";
	shortForm = "In the middle of the path there is a large sign post. There is a pile of bones at its base.\n"
		"The path to the east leads back down through the Volcano Foothills \n"
		"The path to the south continues up and the mouintinside to Volcano Lvl. 1\n";
	longForm = " The path continues to curl up the volcano. The scent of sulfur has grown stronger. \n"
		"In the middle of the path there is a large sign post. There is a pile of bones at its base. \n\n"
		"The path to the east leads back down through the Volcano Foothills \n"
		"The path to the south continues up and the mouintinside to Volcano Lvl. 1\n";

	id = 16;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space16::~Space16()
{}

void Space16::look(const char* thing)
{
	if (strcmp(thing, "sign") == 0)
	{
		cout << "The sign reads 'BEWARE the GAUNTLET starts here.'" << endl;
	}

	else if (strcmp(thing, "bones") == 0)
	{
		cout << "Looks like human bones. Possibly victims of the path ahead?" << endl;
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space16::search(const char* thing)
{
	if (strcmp(thing, "bones") == 0)
	{
		cout << "You find a note hidden in one of the skulls. It reads " << endl;
		cout << "Hey steven, I know we said to meet here but we found a better spot up ahead." << endl;
		cout << "If you bring your guard armor, we'll only need one more until we can combine " << endl;
		cout << "them all into something really cool! Then we’ll make bank! Don’t know why" << endl;
		cout << "i’m writing this all where a stranger can find it. Anyways, hurry up!" << endl;
		cout << "-Steve and the gang" << endl;
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}
