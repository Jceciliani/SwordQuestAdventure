/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 9 of 25 in the game
*/

#include "Space9.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space9::Space9()
{
	name = "Lower Maintenance";
	shortForm = " In the center of the room is a small ornate fountain. There is a large metal hatch on one of the tubes\n";
	longForm = "You arrive in a large room. There are many large metal tubes crossing through\n"
		"the room along the walls. the weave in, out and over one another like a man made spiderweb. \n"
		"In the center of the room is a small ornate fountain. There is a large metal hatch on one of the tubes \n\n";

	id = 9;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	hatchOpen = false;
	fountianUsed = false;
}

Space9::~Space9()
{}

void Space9::look(const char* thing)
{
	if (strcmp(thing, "fountian") == 0)
	{
		if (fountianUsed)
		{
			cout << "the fountian is dry" << endl;
		}
		else
		{
			cout << "The fountian is filled with water. It looks very refreashing" << endl;
		}
	}
	else if (strcmp(thing, "tubes") == 0)
	{
		cout << "there are many of them. Likely for sewage disposal. There looks to be a" << endl;
		cout << "maintenince hatch on one of them" << endl;
	}
	else if (strcmp(thing, "hatch") == 0)
	{
		if (hatchOpen)
		{
			cout << "the large metal door is closed but luckily its not locked" << endl;
		}
		else
		{
			cout << "The hatch is open. You could enter the tube" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space9::enter(const char* thing)
{
	if (strcmp(thing, "tube") == 0)
	{
		if (hatchOpen)
		{
			cout << "you slowly enter the tube. To the south you see that it comes down from a room" << endl;
			cout << "above. As you turn to look north you slip in gunk and are carried down the tubes path." << endl;
			cout << "you launch out of the tube and into a wall before falling to the ground. you find yourself in the Sewer Depths" << endl;
		}
		else
		{
			cout << "the hatch to the tube is closed" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space9::open(const char* thing)
{
	if (strcmp(thing, "hatch") == 0)
	{
		if (!hatchOpen)
		{
			cout << "the door is heavy but with some effort it slowly creaks open. " << endl;
			cout << "The hatch is now open" << endl;
			hatchOpen = true;
		}
		else
		{
			cout << "The hatch is already open" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space9::drink(const char* thing)
{
	if (strcmp(thing, "fountian") == 0)
	{
		if (!fountianUsed)
		{
			cout << "you feel strength return to your body as you drink. You quickly consume all" << endl;
			cout << "of the water with in the fountian. The foundtian is now dry." << endl;
			fountianUsed = true;
		}
		else
		{
			cout << "The fountian is dry" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

