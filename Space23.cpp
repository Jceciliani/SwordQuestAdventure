/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 23 of 25 in the game
*/

#include "Space23.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space23::Space23()
{
	name = "Space23";
	shortForm = "This is the short form";
	longForm = "This is the long form";
	id = 23;
	obj = new Gold_Armor();
	combatEncounter = false;
	visited = false;
}

Space23::~Space23()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space23::getName()
{
	return name;
}

string Space23::getShortForm()
{
	return shortForm;
}

string Space23::getLongForm()
{
	return longForm;
}

void Space23::printSpace()
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

int Space23::getId()
{
	return id;
}
