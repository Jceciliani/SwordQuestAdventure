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
	shortForm = "This is the short form";
	longForm = "This is the long form";
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