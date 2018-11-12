/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 23 of 25 in the game
*/

#include "Space23.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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

void Space23::look(char* thing)
{
	if (strcmp(thing, "trail"))
	{
			cout << "the path ahead looks perilous. be cautious." << endl;
	}
	else if (strcmp(thing, "piles") || strcmp(thing, "valuables") )
	{
			cout << "a small hoard that could rival king Midas. it must have taken ages" << endl;
			cout << "to collect it all. maybe there is something useful in there, besides gold" << endl;
	}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space23::search(char* thing)
{
	if (strcmp(thing, "piles") || strcmp(thing, "valuables") )
	{
			cout << "shoveling through piles of coins like they were dirt gets old really quickly" << endl;
			cout << "luckily it doesnt take too long to find something useful. the coins and chalices part to" << endl;
			cout << "reveal a fancy set of golden armor" << endl;
	}
	else
		{
			cout << "you cant do that" << endl;
		}
}