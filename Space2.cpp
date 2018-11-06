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
	name = "Ruins";
	shortForm = "You arrive at the end of the path to find what ages ago must have been a larger\n"
	"complex, now appears to be a single hulking ruin. You see various remains periodically\n"
	"peeking through the rubble.\n";
	longForm = "You arrive at the end of the path to find what ages ago must have been a larger\n"
	"complex, now appears to be a single hulking ruin. You see various remains periodically\n"
	"peeking through the rubble. \n\n"
	"To the west you see a cobblestone path leading to a clearing\n";
	id = 2;
	obj = new Forge_Hammer();
	combatEncounter = false;
	visited = false;
	hammerFound = false;
}

Space2::~Space2()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
void Space2::addToContainer(Objects obj)
{
	space2.push_back(obj);
}

void Space2::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space2.size(); i++)
	{
		if(space2[i].getName() == obj.getName())
		{
			space2.erase(space2.begin() + i);
			return;
		}
	}

}

void Space2::printContainer()
{
	for(int i = 0; i < space2.size(); i++)
	{
		cout << space2[i].getName() << endl;
	}	
}

void Space2::look(string thing)
{
	if(strcmp(thing, "ruins") || strcmp(thing, "remains"))
		{
			cout << "youre no architect, so youre not really sure what kind of building this could" << endl;
			cout << "have been. The are interesting remains poking through." << endl;	
		}
	else
	{
		cout << "you cant do that" << endl;
	}	
}


void Space2::search(string thing)
{
	if(strcmp(thing, "ruins") || strcmp(thing, "remains"))
		{
			cout << "most of it is less interesting upon further inspection. Broken vases," << endl;
			cout << "bones from a severed arm. There is handle that upon further inspection is" << endl;
			cout << "attached to a forge hammer." << endl;
			hammerFound = true;	
		}
	else
	{
		cout << "you cant do that" << endl;
	}
}