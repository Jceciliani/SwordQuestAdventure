/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 19 of 25 in the game
*/

#include "Space19.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space19::Space19()
{
	name = "Volcano Lvl. 5";
	shortForm = "The air is thick with ash. The trial stops at another landing. In thee face of the \n"
	"volcano you can see a small locked compartment. Beside it hangs a blue key, red key ,\n"
	"and a green key.\n";
	longForm = "The air is thick with ash. The trial stops at another landing. In thee face of the \n"
	"volcano you can see a small locked compartment. Beside it hangs a blue key, red key ,\n"
	"and a green key.\n\n"
	"The path to the east continues up the volcano. \n";
	id = 19;
	obj = new Key();
	combatEncounter = false;
	visited = false;
}

Space19::~Space19()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
void Space19::addToContainer(Objects obj)
{
	space19.push_back(obj);
}

void Space19::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space19.size(); i++)
	{
		if(space19[i].getName() == obj.getName())
		{
			space19.erase(space19.begin() + i);
			return;
		}
	}

}

void Space19::printContainer()
{
	for(int i = 0; i < space19.size(); i++)
	{
		cout << space19[i].getName() << endl;
	}	
}

