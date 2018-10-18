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
	shortForm = "The path continues forward. You question the trails integrity as you see a few \n
	chunks separate themselves from the mountain. There is a small alcove in the face of the volcano\n
	containing various piles valuables and trinkets.";
	longForm = "The path continues forward. You question the trails integrity as you see a few \n
	chunks separate themselves from the mountain. There is a small alcove in the face of the volcano\n
	containing various piles valuables and trinkets. \n\n
	The path to the west leads back down \n
	The path to the east continues up the volcano \n";
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
