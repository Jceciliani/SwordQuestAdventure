/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 21 of 25 in the game
*/

#include "Space21.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space21::Space21()
{
	name = "Space21";
	shortForm = "This is the short form";
	longForm = "This is the long form";
	id = 21;
	obj = new Two_Handed_Gold_Sword();
	combatEncounter = false;
	visited = false;
}

Space21::~Space21()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

string Space21::getName()
{
	return name;
}

string Space21::getShortForm()
{
	return shortForm;
}

string Space21::getLongForm()
{
	return longForm;
}

void Space21::printSpace()
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

int Space21::getId()
{
	return id;
}
