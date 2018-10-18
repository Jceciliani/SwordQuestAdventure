/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 7 of 25 in the game
*/

#include "Space7.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space7::Space7()
{
	name = "Space7";
	shortForm = "The room is covered in moss and vegetation. Majority of the room is submerged\n
	in a murky liquid. There is a narrow rope bridge that crosses to the eastern wall. A small \n
	mossy island is in the middle of the room";
	longForm = "The room is covered in moss and vegetation. Majority of the room is submerged\n
	in a murky liquid. There is a narrow rope bridge that crosses to the eastern wall. A small \n
	mossy island is in the middle of the room \n\n
	To the east is a small opening through the brush \n
	To the south is path thick with vegetation\n";
	id = 7;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space7::~Space7()
{}

string Space7::getName()
{
	return name;
}

string Space7::getShortForm()
{
	return shortForm;
}

string Space7::getLongForm()
{
	return longForm;
}

void Space7::printSpace()
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

int Space7::getId()
{
	return id;
}
