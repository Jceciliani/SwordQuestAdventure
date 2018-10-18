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
	name = "Space14";
	shortForm = "There is sparse light in the corridor. The walls seem to be etched with something. \n
	The floor of the room feels slightly uneven";
	longForm = "There is sparse light in the corridor. The walls seem to be etched with something. \n
	The floor of the room feels slightly uneven \n\n
	To the west is the entrance to the corridor \n
	To the east is a doorway to a small room\n";
	id = 14;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space14::~Space14()
{}

string Space14::getName()
{
	return name;
}

string Space14::getShortForm()
{
	return shortForm;
}

string Space14::getLongForm()
{
	return longForm;
}

void Space14::printSpace()
{
	if (visited == false)
	{
		cout << "Current Location: " << getName() << endl;
		cout << getLongForm() << endl;
	}
	else
	{
		cout << "Current Location: " << getName() << endl;
		cout << getShortForm() << endl;
	}
}

int Space14::getId()
{
	return id;
}