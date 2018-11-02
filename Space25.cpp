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

