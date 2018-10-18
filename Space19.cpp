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
	name = "Space19";
	shortForm = "The air is thick with ash. The trial stops at another landing. In thee face of the \n
	volcano you can see a small locked compartment. Beside it hangs a blue key, red key ,\n
	and a green key.";
	longForm = "The air is thick with ash. The trial stops at another landing. In thee face of the \n
	volcano you can see a small locked compartment. Beside it hangs a blue key, red key ,\n
	and a green key.\n\n
	The path to the south leads back down \n
	The path to the east continues up the volcano. \n";
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

string Space19::getName()
{
	return name;
}

string Space19::getShortForm()
{
	return shortForm;
}

string Space19::getLongForm()
{
	return longForm;
}

void Space19::printSpace()
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

int Space19::getId()
{
	return id;
}