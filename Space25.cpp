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
	name = "Space25";
	shortForm = "This is the short form";
	longForm = "This is the long form";
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

string Space25::getName()
{
	return name;
}

string Space25::getShortForm()
{
	return shortForm;
}

string Space25::getLongForm()
{
	return longForm;
}

void Space25::printSpace()
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

int Space25::getId()
{
	return id;
}
