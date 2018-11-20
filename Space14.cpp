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
	shortForm = " The walls seem to be etched with something. The floor of the room feels slightly uneven\n";
	longForm = "There is sparse light in the corridor. The walls seem to be etched with something, \n"
		"scarring the walls of the passage way. The floor of the room feels slightly uneven. makes you feel \n"
		"unsettled as though you were stepping onto a boat\n\n";

	id = 14;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	crossed = false;
}

Space14::~Space14()
{}


void Space14::look(char* thing)
{
	if (strcmp(thing, "walls"))
	{
		cout << "the walls look to be etched with a number of name. Middle. Jason. Of. Kevin. Floor. " << endl;
		cout << "Joshua. Death. And many more" << endl;
	}

	else if (strcmp(thing, "floor"))
	{
		cout << "upon closer inspection the floor seems to slightly slope towards the middle of the hall. " << endl;
		cout << "The floor there definitly looks unstable" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space14::run(char* thing)
{
	if (strcmp(thing, "across"))
	{
		cout << "you sprint across the room. You reach the other side unscathed" << endl;
		if (crossed)
		{
			crossed = false;
		}
		else
		{
			crossed = true;
		}

	}
	else if (strcmp(thing, "west"))
	{
		if (crossed)
		{
			cout << "you sprint across the room. You reach the other side unscathed" << endl;
			crossed = false;
		}
		else {
			cout << "you are on the west side of the room" << endl;
		}
	}
	else if (strcmp(thing, "east"))
	{
		if (crossed)
		{
			cout << "you sprint across the room. You reach the other side unscathed" << endl;
			crossed = true;
		}
		else {
			cout << "you are on the east side of the room" << endl;
		}
	}
}

void Space14::jump(char* thing)
{
	if (strcmp(thing, "across"))
	{
		cout << " you make a small run and leap over the majority of the room. You cross unscathed" << endl;
		if (crossed)
		{
			crossed = false;
		}
		else
		{
			crossed = true;
		}

	}
	else if (strcmp(thing, "west"))
	{
		if (crossed)
		{
			cout << " you make a small run and leap over the majority of the room. You cross unscathed" << endl;
			crossed = false;
		}
		else {
			cout << "you are on the west side of the room" << endl;
		}
	}
	else if (strcmp(thing, "east"))
	{
		if (crossed)
		{
			cout << " you make a small run and leap over the majority of the room. You cross unscathed" << endl;
			crossed = true;
		}
		else {
			cout << "you are on the east side of the room" << endl;
		}
	}
}