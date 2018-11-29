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
	shortForm = "There are piles of broken tools, torn clothes, and bones. To the side you see a book\n";
	longForm = " You find a small cave. Tt is dark, dank and you can hear your footsteps echo through it. \n"
		"It is also covered in piles of broken tools, torn clothes, and bones. To the side you see a book\n\n";

	id = 11;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space11::~Space11()
{}

void Space11::look(const char* thing)
{
	if (strcmp(thing, "cave") == 0|| strcmp(thing, "piles") == 0)
	{
		cout << "Small piles are scattered all over the small cave. Hard to tell at a glance" << endl;
		cout << "if there is anything useful in them" << endl;

	}
	if (strcmp(thing, "book") )
	{
		cout << "The book is labeled 'How to Serve Humans'. Maybe the creature was trying to learn" << endl;
		cout << "how to be in society. Maybe he was good" << endl;

	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space11::search(const char* thing)
{
	if (strcmp(thing, "cave")  == 0|| strcmp(thing, "piles") == 0)
	{
		cout << "While searching you find a large drawing on what used to be the top of a " << endl;
		cout << "carriage.  It looks like crude picture math. It depicts four swords" << endl;
		cout << "plus a unrecognizable black smudge equals a single sword. Just the fact that" << endl;
		cout << "this creature attempted math means its much more intelligent than you would" << endl;
		cout << "have guessed" << endl;
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}

void Space11::read(const char* thing)
{
	if (strcmp(thing, "book") == 0)
	{
		cout << "Wait a minute... THIS IS A COOK BOOK! \n" << endl;

	}
	else
	{
		cout << "You can't do that" << endl;
	}
}
