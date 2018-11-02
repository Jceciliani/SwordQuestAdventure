/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 14 of 25 in the game
*/

#include "Space14.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space14::Space14()
{
	name = "Mausoleum";
	shortForm = "There is sparse light in the corridor. The walls seem to be etched with something. \n"
	"The floor of the room feels slightly uneven\n";
	longForm = "There is sparse light in the corridor. The walls seem to be etched with something. \n"
	"The floor of the room feels slightly uneven \n\n"
	"To the west is the entrance to the corridor \n"
	"To the east is a doorway to a small room\n";
	id = 14;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space14::~Space14()
{}
void Space14::addToContainer(Objects obj)
{
	space14.push_back(obj);
}

void Space14::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space14.size(); i++)
	{
		if(space14[i].getName() == obj.getName())
		{
			space14.erase(space14.begin() + i);
			return;
		}
	}

}

void Space14::printContainer()
{
	for(int i = 0; i < space14.size(); i++)
	{
		cout << space14[i].getName() << endl;
	}	
}

