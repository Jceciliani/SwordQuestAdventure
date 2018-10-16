/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 5 of 25 in the game
*/

#include "Space5.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space5::Space5()
{
	name = "Space5";
	shortForm = "This is the short form";
	longForm = "This is the long form";
	id = 5;
	obj = new Two_Handed_Silver_Sword();
	combatEncounter = false;
	visited = false;
}

Space5::~Space5()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space5::getName()
{
	return name;
}

string Space5::getShortForm()
{
	return shortForm;
}

string Space5::getLongForm()
{
	return longForm;
}

void Space5::printSpace()
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

int Space5::getId()
{
	return id;
}
