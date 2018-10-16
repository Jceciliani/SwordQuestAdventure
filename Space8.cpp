/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 8 of 25 in the game
*/

#include "Space8.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space8::Space8()
{
	name = "Space8";
	shortForm = "This is the short form";
	longForm = "This is the long form";
	id = 8;
	obj = new Two_Handed_Bronze_Sword();
	combatEncounter = false;
	visited = false;
}

Space8::~Space8()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space8::getName()
{
	return name;
}

string Space8::getShortForm()
{
	return shortForm;
}

string Space8::getLongForm()
{
	return longForm;
}

void Space8::printSpace()
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

int Space8::getId()
{
	return id;
}
