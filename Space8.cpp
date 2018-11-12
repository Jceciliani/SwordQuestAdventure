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
	shortForm = "You find an office of some sort, moldy from the dampness that hangs in the air. \n"
	"There are papers strewn across the desk. There are a collection of lockers along the west wall\n";
	longForm = "You find an office of some sort, moldy from the dampness that hangs in the air. \n"
	"There are papers strewn across the desk. There are a collection of lockers along the west wall \n\n"
	"To the north is a door labeled 'Sewers' \n"
	"To the east is a door labeled “Maintenance” \n"
	"To the south is a pair of stairs leading up\n";
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
void Space8::addToContainer(Objects obj)
{
	space8.push_back(obj);
}

void Space8::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space8.size(); i++)
	{
		if(space8[i].getName() == obj.getName())
		{
			space8.erase(space8.begin() + i);
			return;
		}
	}

}

void Space8::printContainer()
{
	for(int i = 0; i < space8.size(); i++)
	{
		cout << space8[i].getName() << endl;
	}	
}

void Space8::look(char* thing)
{
	if (strcmp(thing, "papers") || strcmp(thing, "desk"))
		{
		cout << "the papers strewn across the desk seem to be schedules for the guards," << endl;
		cout << "albeit very very old ones. Seems that the most recent one only one guard" << endl;
		cout << "one only one guard was off duty. Bob - locker 13" << endl;
		}

	else if (strcmp(thing, "lockers"))
	{
		cout << "a large number of small lockers. around 30. Luckily they dont have locks!" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space8::search(char* thing)
{
	if (strcmp(thing, "lockers"))
	{
		cout << "but which locker do you want to search?" << endl;
	}
	else if (strcmp(thing, "locker 1") || strcmp(thing, "locker 2") || strcmp(thing, "locker 3") || strcmp(thing, "locker 4") ||
		strcmp(thing, "locker 5") || strcmp(thing, "locker 6") || strcmp(thing, "locker 7") || strcmp(thing, "locker 8") ||
		strcmp(thing, "locker 9") || strcmp(thing, "locker 10") || strcmp(thing, "locker 11") || strcmp(thing, "locker 12") ||
		strcmp(thing, "locker 14") || strcmp(thing, "locker 15") || strcmp(thing, "locker 16") || strcmp(thing, "locker 17") ||
		strcmp(thing, "locker 18") || strcmp(thing, "locker 19") || strcmp(thing, "locker 20") || strcmp(thing, "locker 21") ||
		strcmp(thing, "locker 22") || strcmp(thing, "locker 23") || strcmp(thing, "locker 24") || strcmp(thing, "locker 25") ||
		strcmp(thing, "locker 26") || strcmp(thing, "locker 27") || strcmp(thing, "locker 28") || strcmp(thing, "locker 29") ||
		strcmp(thing, "locker 30"))
	{
		cout << "nothing here" << endl;
	}

	else if (strcmp(thing, "locker 13"))
	{
		cout << " you find a bronze sword" << endl;
		swordFound = true;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}