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
	name = "Volcano Lvl. 3";
	shortForm = "The path continues forward. You question the trails integrity as you see a few \n"
	"chunks separate themselves from the mountain. There is a small alcove in the face of the volcano\n"
	"containing various piles valuables and trinkets.\n";
	longForm = "The path continues forward. You question the trails integrity as you see a few \n"
	"chunks separate themselves from the mountain. There is a small alcove in the face of the volcano\n"
	"containing various piles valuables and trinkets. \n\n"
	"The path to the east continues up the volcano \n";
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
void Space23::addToContainer(Objects obj)
{
	space23.push_back(obj);
}

void Space23::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space23.size(); i++)
	{
		if(space23[i].getName() == obj.getName())
		{
			space23.erase(space23.begin() + i);
			return;
		}
	}

}

void Space23::printContainer()
{
	for(int i = 0; i < space23.size(); i++)
	{
		cout << space23[i].getName() << endl;
	}	
}

