/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 13 of 25 in the game
*/

#include "Space13.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space13::Space13()
{
	name = "Sanctuary";
	shortForm = "In the center of the room is a small ornate fountain \n"
		"In the south western corner is an anvil and forge. Along the northern wall there is a large wooden chest.\n"
		"A large gate on the southern wall looms over the room \n";
		longForm = "You awake to the sound of trickling water and the taste of rubble in your mouth. \n"
		"You are sore, but not as sore as you would expect. You wince as you stand and begin to take \n"
		"in your surroundings. The room itself seems fairly nice, despite being in an extreme state of disuse.\n"
		"The majority of the room is covered in thick coat of dust. In the center of the room is a small ornate fountain \n"
		"In the south western corner is an anvil and forge. Along the northern wall there is a large wooden chest. \n"
		"A large gate on the southern wall looms over the room, striking unease into your heart \n";

	id = 13;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	fountianUsed = false;
	gateOpened = false;
	forgeLit = false;
}

Space13::~Space13()
{}

void Space13::look(const char* thing)
{
	if (strcmp(thing, "fountian") == 0)
	{
		if (fountianUsed)
		{
			cout << "The fountian is dry" << endl;
		}
		else
		{
			cout << "The fountian is filled with water. It looks very refreashing" << endl;
		}
	}
	else if (strcmp(thing, "forge") == 0 || strcmp(thing, "anvil") == 0)
	{
		cout << "A forge and anvil used for crafting weapons and armor" << endl;
		if (forgeLit)
		{
			cout << "You can feel the heat of the fires within it" << endl;
		}
		else
		{
			cout << "It is not currently functioning though. it looks cold and sad" << endl;
		}

	}
	else if (strcmp(thing, "chest") == 0 || strcmp(thing, "wooden chest") == 0)
	{
		cout << "The wooden chest looks worn, but still very usable. Since it isn't locked you could" << endl;
		cout << "probably store some of your extra things here" << endl;
	}
	else if (strcmp(thing, "gate") == 0)
	{
		cout << "A large ominous gate. the black steel it is made from is sturdy and threatening" << endl;
		if (!gateOpened)
		{
			cout << "The gate is closed an bars your exit" << endl;

		}
		else
		{
			cout << "The gate is open" << endl;

		}
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space13::drink(const char* thing)
{
	if (strcmp(thing, "fountian") == 0)
	{
		if (!fountianUsed)
		{
			cout << "You feel strength return to your body as you drink. You quickly consume all" << endl;
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
		cout << "You cant do that" << endl;
	}
}

void Space13::start(const char* thing)
{
	if (strcmp(thing, "forge") == 0)
	{
		if (!forgeLit)
		{
			cout << "You strike the steel on the flint a few times. the sparks catch quickly" << endl;
			cout << "and the forge roars to life. You set the forge hammer down, ready to use it in the future" << endl;
			
		}
		else
		{
			cout << "The forge is already burning" << endl;
		}
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}

void Space13::use(const char* thing)
{
	if (strcmp(thing, "forge") == 0)
	{
		if (!forgeLit)
		{
			cout << "The forge is cold. Try starting the forge before you use it" << endl;
		}
		else
		{
			cout << "You hammer away at the hot metal, sparks flying back at you. You are not" << endl;
			cout << "sure what you are doing but you know you are doing it well.  As you cool your" << endl;
			cout << "new creation, you know it will help you in the battle ahead" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space13::open(const char* thing)
{
	if (strcmp(thing, "gate") == 0)
	{
		if (!gateOpened)
		{
			cout << "As you use the large key, the large lock falls to the floor and the gates loudly creak open." << endl;
			cout << "You hear a loud deep growl from beyond the doorway. This is it." << endl;
			
		}
		else
		{
			cout << "The gate is already open" << endl;

		}
	}
	else
	{
		cout << "You cant do that" << endl;
	}
}
