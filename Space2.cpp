/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 2 of 25 in the game
*/

#include "Space2.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space2::Space2()
{
	name = "Space2";
	shortForm = "This is the short form";
	longForm = "This is the long form";
	id = 2;
	obj = new Forge_Hammer();
	combatEncounter = false;
	visited = false;
}

Space2::~Space2()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space2::getName()
{
	return name;
}

string Space2::getShortForm()
{
	return shortForm;
}

string Space2::getLongForm()
{
	return longForm;
}

void Space2::printSpace()
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

int Space2::getId()
{
	return id;
}