/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 18 of 25 in the game
*/

#include "Space18.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space18::Space18()
{
	name = "Dragon Keep";
	shortForm = "This is the short form\n";
	longForm = "This is the long form\n";
	id = 18;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space18::~Space18()
{}
void Space18::addToContainer(Objects obj)
{
	space18.push_back(obj);
}

void Space18::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space18.size(); i++)
	{
		if(space18[i].getName() == obj.getName())
		{
			space18.erase(space18.begin() + i);
			return;
		}
	}

}

void Space18::printContainer()
{
	for(int i = 0; i < space18.size(); i++)
	{
		cout << space18[i].getName() << endl;
	}	
}

