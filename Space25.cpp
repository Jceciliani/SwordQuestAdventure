/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 25 of 25 in the game
*/

#include "Space25.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space25::Space25()
{
	name = "Volcanic Chamber";
	shortForm = "You reach a small platform in the middle of the burning lake. You won't last long \n"
	"in this heat. The stalactites spark from the heat.\n";
	longForm = "You reach a small platform in the middle of the burning lake. You won't last long \n"
	"in this heat. The stalactites spark from the heat. \n\n"
	"To the north is a steep climb out of the volcano \n";
	id = 25;
	obj = new Flint();
	combatEncounter = false;
	visited = false;
}

Space25::~Space25()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
void Space25::addToContainer(Objects obj)
{
	space25.push_back(obj);
}

void Space25::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space25.size(); i++)
	{
		if(space25[i].getName() == obj.getName())
		{
			space25.erase(space25.begin() + i);
			return;
		}
	}

}

void Space25::printContainer()
{
	for(int i = 0; i < space25.size(); i++)
	{
		cout << space25[i].getName() << endl;
	}	
}
void Space25::look(string thing)
{
	if (strcmp(thing, "lake"))
	{
			cout << "a lake made of lava. you are in a volcano after all. trying to go any closer to it" << endl;
			cout << "would not bode well for you." << endl;
	}
	else if(strcmp(thing, "stalagtite"))
	{
			cout << "small towers of a weird black substance. they seem to spark everyso often. they seem" << endl;
			cout << "like they would be easy enough to break if you needed to" << endl;
	}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space25::attack(string thing)
{
	if (strcmp(thing, "stalagtite"))
	{
			cout << "you swing down with your sword at one of the stalagtites. upon impact a shower of sparks" << endl;
			cout << "erupts from it. a large chunk of the stalagtite falls to the ground. from what just occured" << endl;
			cout << "you can guess that they are made of flint" << endl;
			flintFound = true;
	}

	else
		{
			cout << "you cant do that" << endl;
		}
}