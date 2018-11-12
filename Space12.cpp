/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 12 of 25 in the game
*/

#include "Space12.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space12::Space12()
{
	name = "Crossroads";
	shortForm = "The floor has dissipated from solid stone to a coarse dirt. The room is deceptively \n"
	"large. If not for the walls and ceiling you'd feel like you were outside. In the center of\n"
	"the room is  a signpost. Along the western wall is a small fence off plot of dirt.\n";
	longForm = "The floor has dissipated from solid stone to a coarse dirt. The room is deceptively \n"
	"large. If not for the walls and ceiling you'd feel like you were outside. In the center of\n"
	"the room is  a signpost. Along the western wall is a small fence off plot of dirt.\n\n"
	"To the north there is a path slowly encroached by brush \n"
	"To the south there is a path that slopes upward \n"
	"To the east there is a well lit corridor \n";
	id = 12;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space12::~Space12()
{}
void Space12::addToContainer(Objects obj)
{
	space12.push_back(obj);
}

void Space12::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space12.size(); i++)
	{
		if(space12[i].getName() == obj.getName())
		{
			space12.erase(space12.begin() + i);
			return;
		}
	}

}

void Space12::printContainer()
{
	for(int i = 0; i < space12.size(); i++)
	{
		cout << space12[i].getName() << endl;
	}	
}

void Space12::look(char* thing)
{
	if (strcmp(thing, "plot"))
	{
		cout << "a plot of dirt. the ground look freasher here that outside the fence. maybe" << endl;
		cout << "someone is trying to grow something? i wonder what?" << endl;
	}
	else if (strcmp(thing, "sign"))
	{
		cout << "a small worn signpost. and in a dungeon? how big is this place? the sign pointed" << endl;
		cout << "north reads SWAMP: CAREFUL OF THE PIRAHNAS" << endl;
		cout << "the south sign reads VOLCANO: CAREFUL OF LEVERS" << endl;
		cout << "the east sign reads SANCTUARY: CAREFUL OF FLOORS" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space12::dig(char* thing)
{
	if (strcmp(thing, "plot"))
	{
		cout << "you get down on your hands and knees and start digging through the plot. hoping to find something" << endl;
		cout << "but this action feels oddly familiar. like youve done this exact thing before. you start to remember" << endl;
		cout << "you used to be a farmer..." << endl;
		cout << "but then something crashed into some nearby ruins..." << endl;
		cout << "you went to check it out..." << endl;
		cout << "but then..." << endl;
		cout << "then..." << endl;
		cout << "no idea. but you can figure it out when you make it out of here!" << endl;

	}

	else
	{
		cout << "you cant do that" << endl;
	}
}
