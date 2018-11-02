/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 24 of 25 in the game
*/

#include "Space24.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space24::Space24()
{
	name = "Volcano Lvl. 4";
	shortForm = "The path starts to wind up the mountain at a much steeper pace. There is a small\n"
	"landing before the trail cuts in and up the volcano.  In the middle of the landing is a small lever.\n";
	longForm = "The path starts to wind up the mountain at a much steeper pace. There is a small\n"
	"landing before the trail cuts in and up the volcano.  In the middle of the landing is a small lever. \n\n"
	"The path to the north continues up the volcano.\n";
	id = 24;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space24::~Space24()
{}
void Space24::addToContainer(Objects obj)
{
	space24.push_back(obj);
}

void Space24::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space24.size(); i++)
	{
		if(space24[i].getName() == obj.getName())
		{
			space24.erase(space24.begin() + i);
			return;
		}
	}

}

void Space24::printContainer()
{
	for(int i = 0; i < space24.size(); i++)
	{
		cout << space24[i].getName() << endl;
	}	
}

