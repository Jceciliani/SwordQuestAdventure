/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 16 of 25 in the game
*/

#include "Space16.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space16::Space16()
{
	name = "Space16";
	shortForm = " The path continues to curl up the volcano. The scent of sulfur has grown stronger. \n
	In the middle of the path there is a large sign post. There is a pile of bones at its base.";
	longForm = " The path continues to curl up the volcano. The scent of sulfur has grown stronger. \n
	In the middle of the path there is a large sign post. There is a pile of bones at its base. \n\n
	The path to the east leads back down. \n
	The path to the south continues up the volcano\n";
	id = 16;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space16::~Space16()
{}

string Space16::getName()
{
	return name;
}

string Space16::getShortForm()
{
	return shortForm;
}

string Space16::getLongForm()
{
	return longForm;
}

void Space16::printSpace()
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

int Space16::getId()
{
	return id;
}