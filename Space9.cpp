/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 9 of 25 in the game
*/

#include "Space9.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space9::Space9()
{
	name = "Space9";
	shortForm = "You arrive in a large room. There are many large metal tubes crossing through\n
	the room along the walls. In the center of the room is a small ornate fountain.There are\n
	a collection of lockers along the west wall. There is a large metal hatch on one of the tubes";
	longForm = "You arrive in a large room. There are many large metal tubes crossing through\n
	the room along the walls. In the center of the room is a small ornate fountain.There are\n
	a collection of lockers along the west wall. There is a large metal hatch on one of the tubes \n\n
	To the east there is a walkway\n
	To the west is an office door\n";
	id = 9;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space9::~Space9()
{}

string Space9::getName()
{
	return name;
}

string Space9::getShortForm()
{
	return shortForm;
}

string Space9::getLongForm()
{
	return longForm;
}

void Space9::printSpace()
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

int Space9::getId()
{
	return id;
}
