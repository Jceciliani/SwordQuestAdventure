/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 15 of 25 in the game
*/

#include "Space15.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space15::Space15()
{
	name = "Space15";
	shortForm = "This is the short form";
	longForm = "This is the long form";
	id = 15;
	obj = new Steel();
	combatEncounter = false;
	visited = false;
}

Space15::~Space15()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space15::getName()
{
	return name;
}

string Space15::getShortForm()
{
	return shortForm;
}

string Space15::getLongForm()
{
	return longForm;
}

void Space15::printSpace()
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

int Space15::getId()
{
	return id;
}