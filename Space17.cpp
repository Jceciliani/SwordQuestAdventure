/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 17 of 25 in the game
*/

#include "Space17.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space17::Space17()
{
	name = "Volcano Foothills";
	shortForm = "You are at the base of a large volcano. Its shadow looms over you. There is a faint \n"
	"smell of sulfur in the air. In the middle of the path there is a small ornate fountain.\n";
	longForm = "You are at the base of a large volcano. Its shadow looms over you. There is a faint \n"
	"smell of sulfur in the air. In the middle of the path there is a small ornate fountain. \n\n"
	"To the north is a path sloping down and away from the volcano \n"
	"To west is a trail leading up the volcano\n";
	id = 17;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space17::~Space17()
{}
void Space17::addToContainer(Objects obj)
{
	space17.push_back(obj);
}

void Space17::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space17.size(); i++)
	{
		if(space17[i].getName() == obj.getName())
		{
			space17.erase(space17.begin() + i);
			return;
		}
	}

}

void Space17::printContainer()
{
	for(int i = 0; i < space17.size(); i++)
	{
		cout << space17[i].getName() << endl;
	}	
}

void Space17::look(string thing)
{
if (strcmp(thing, "fountian"))
	{
		if(fountianUsed)
		{
			cout << "the fountian is dry" << endl;
		}
		else
		{
			cout << "The fountian is filled with water. It looks very refreashing" << endl;
		}
	}

	else if(strcmp(thing, "volcano"))
	{
			cout << "its a volcano… in a dungeon? Anyways it seems to be still active. Maybe theres " << endl; 
			cout << "something that will help up there?" << endl; 
	}
else
		{
			cout << "you cant do that" << endl;
		}
}

void Space17::drink(string thing)
{
if (strcmp(thing, "from fountian"))
	{
		if(!fountianUsed)
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