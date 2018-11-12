/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 11 of 25 in the game
*/

#include "Space11.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space11::Space11()
{
	name = "Cave";
	shortForm = " You find a small cave. It is covered it piles of broken tools, torn clothes, and bones.\n";
	longForm = " You find a small cave. It is covered it piles of broken tools, torn clothes, and bones. \n\n"
	"To the north is a wide path marked with broken branches \n";
	id = 11;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space11::~Space11()
{}
void Space11::addToContainer(Objects obj)
{
	space11.push_back(obj);
}

void Space11::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space11.size(); i++)
	{
		if(space11[i].getName() == obj.getName())
		{
			space11.erase(space11.begin() + i);
			return;
		}
	}

}

void Space11::printContainer()
{
	for(int i = 0; i < space11.size(); i++)
	{
		cout << space11[i].getName() << endl;
	}	
}

void Space11::look(char* thing)
{
	if (strcmp(thing, "cave") || strcmp(thing, "piles"))
	{
		cout << "small piles are scattered all over the small cave. hard to tell at a glance" << endl;
		cout << "if there is anything useful in them" << endl;

	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space11::search(char* thing)
{
	if (strcmp(thing, "cave") || strcmp(thing, "piles"))
	{
		cout << "While searching you find a large drawing on what used to be the top of a " << endl;
		cout << "cairrage.  It looks like crude picture math. It depicts four swords" << endl;
		cout << " plus a inrecognisable black smudge equals a single sword. Just the fact that" << endl;
		cout << " this creature attempted math means its much more inttelligent than you would" << endl;
		cout << " have guessed" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}