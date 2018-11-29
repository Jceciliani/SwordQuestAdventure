/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 14 of 25 in the game
*/

#include "Space14.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space14::Space14()
{
	name = "Mausoleum";
	shortForm = "The walls seem to be etched with something. The floor of the room feels slightly uneven\n"
		"To the west is a small corridor back to the Sanctuary \n"
		"To the east is a doorway to a small Crypt\n";
	longForm = "There is sparse light in the corridor. The walls seem to be etched with something, \n"
		"scarring the walls of the passage way. The floor of the room feels slightly uneven. Makes you feel \n"
		"unsettled as though you were stepping onto a boat\n\n"
		"To the west is a small corridor back to the Sanctuary \n"
		"To the east is a doorway to a small Crypt\n";

	id = 14;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	crossed = false;
}

Space14::~Space14()
{}


void Space14::look(const char* thing)
{
	if (strcmp(thing, "walls") == 0)
	{
		cout << "The walls look to be etched with a number of name. Middle. Jason. Of. Kevin. Floor. " << endl;
		cout << "Josh. Death. And many more" << endl;
	}

	else if (strcmp(thing, "floor") == 0)
	{
		cout << "Upon closer inspection, the floor seems to slightly slope towards the middle of the hall. " << endl;
		cout << "The floor there definitly looks unstable" << endl;
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space14::run(const char* thing)
{
	if (strcmp(thing, "across") == 0)
	{
		cout << "You sprint across the room. You reach the other side unscathed" << endl;
		if (crossed)
		{
			crossed = false;
		}
		else
		{
			crossed = true;
		}

	}
	else if (strcmp(thing, "west") == 0)
	{
		if (crossed)
		{
			cout << "You sprint across the room. You reach the other side unscathed" << endl;
			crossed = false;
		}
		else {
			cout << "You are on the west side of the room" << endl;
		}
	}
	else if (strcmp(thing, "east"))
	{
		if (crossed)
		{
			cout << "You sprint across the room. You reach the other side unscathed" << endl;
			crossed = true;
		}
		else {
			cout << "You are on the east side of the room" << endl;
		}
	}
}

void Space14::jump( const char* thing)
{
	if (strcmp(thing, "across") == 0)
	{
		cout << "You make a small run and leap over the majority of the room. You cross unscathed" << endl;
		if (crossed)
		{
			crossed = false;
		}
		else
		{
			crossed = true;
		}

	}
	else if (strcmp(thing, "west") == 0)
	{
		if (crossed)
		{
			cout << " You make a small run and leap over the majority of the room. You cross unscathed" << endl;
			crossed = false;
		}
		else {
			cout << "You are on the west side of the room" << endl;
		}
	}
	else if (strcmp(thing, "east") == 0)
	{
		if (crossed)
		{
			cout << "You make a small run and leap over the majority of the room. You cross unscathed" << endl;
			crossed = true;
		}
		else {
			cout << "You are on the east side of the room" << endl;
		}
	}
}
