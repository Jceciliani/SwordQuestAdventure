/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 22 of 25 in the game
*/

#include "Space22.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space22::Space22()
{
	name = "Space22";
	shortForm = "The path continues upward. You can start to feel heat coming off the mountain. \n
	An old man sits in the middle of the path";
	longForm = "The path continues upward. You can start to feel heat coming off the mountain. \n
	An old man sits in the middle of the path \n\n
	The path to the west leads back down \n
	The path to the east continues up the volcano \n";
	id = 22;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space22::~Space22()
{}

string Space22::getName()
{
	return name;
}

string Space22::getShortForm()
{
	return shortForm;
}

string Space22::getLongForm()
{
	return longForm;
}

void Space22::printSpace()
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

int Space22::getId()
{
	return id;
}
