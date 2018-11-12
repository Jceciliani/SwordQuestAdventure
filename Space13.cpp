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
	"In the south western corner is an anvil and furnace. Along the northern wall there is a large wooden chest \n";
	longForm = "You awake to the sound of trickling water and the taste of rubble in your mouth. \n"
	"You are sore, but not as sore as you would expect. You wince as you stand and begin to take \n"
	"in your surroundings.The room itself seems fairly nice, despite being in an extreme state of disuse.\n"
	"The majority of the room is covered in thick coat of dust.In the center of the room is a small ornate fountain \n"
	"In the south western corner is an anvil and furnace. Along the northern wall there is a large wooden chest \n \n"
	"To the south there is a large ominously gated doorway \n"
	"To the west is a doorway that leads down a well lit corridor \n"
	"To the north is a set of moist stairs that lead downward \n"
	"To the east is a doorway that leads through a small dimly lit passage \n";
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
void Space13::addToContainer(Objects obj)
{
	space13.push_back(obj);
}

void Space13::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space13.size(); i++)
	{
		if(space13[i].getName() == obj.getName())
		{
			space13.erase(space13.begin() + i);
			return;
		}
	}

}

void Space13::printContainer()
{
	for(int i = 0; i < space13.size(); i++)
	{
		cout << space13[i].getName() << endl;
	}	
}

void Space13::look(char* thing)
{
	if (strcmp(thing, "fountian"))
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
	else if (strcmp(thing, "forge") || strcmp(thing, "anvil"))
	{
		cout << "a forge and anvil used for crafting weapons and armor" << endl;
		if (forgeLit)
		{
			cout << "you can feel the heat of the fires within it" << endl;
		}
		else
		{
			cout << "it is not currently functioning though. it looks cold and sad" << endl;
		}

	}
	else if (strcmp(thing, "chest") || strcmp(thing, "wooden chest"))
	{
		cout << "the wooden chest looks worn, but still very usable. since it isnt locked you could" << endl;
		cout << "probably store some of your extra things here" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space13::drink(char* thing)
{
	if (strcmp(thing, "from fountian"))
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

void Space13::start(char* thing)
{
	if (strcmp(thing, "forge"))
	{
		if (!forgeLit)
		{
			cout << "you strike the steel on the flint a few times. the sparks catch quickly" << endl;
			cout << "and the forge roars to life. you set the forge hammer down, ready to use it in the future" << endl;
			forgeLit = true;
		}
		else
		{
			cout << "the forge is already burning" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space13::use(char* thing)
{
	if (strcmp(thing, "forge"))
	{
		if (!forgeLit)
		{
			cout << "the forge is cold. try starting the forge before you use it" << endl;
		}
		else
		{
			cout << "you hammer away at the hot metal, sparks flying back at you. you are not" << endl;
			cout << "sure what you are doing but you know you are doing it well.  as you cool your" << endl;
			cout << "new creation, you know it will help you in the battle ahead" << endl;
		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space13::open(char* thing)
{
	if (strcmp(thing, "gate"))
	{
		if (!gateOpened)
		{
			cout << "as you use the large key, the large lock falls to the floor and the gates loudly creak open" << endl;
			cout << "you hear a loud deep growl from beyond the doorway. this is it." << endl;
			gateOpened = true;
		}
		else
		{
			cout << "the gate is already open" << endl;

		}
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}