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
	shortForm = " there are piles of broken tools, torn clothes, and bones. to the side you see a book\n";
	longForm = " You find a small cave. it is dark, dank and you can hear your footsteps echo through it \n"
		"It is also covered it piles of broken tools, torn clothes, and bones. to the side you see a book\n\n";

	id = 11;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space11::~Space11()
{}

void Space11::look(char* thing)
{
	if (strcmp(thing, "cave") || strcmp(thing, "piles"))
	{
		cout << "small piles are scattered all over the small cave. hard to tell at a glance" << endl;
		cout << "if there is anything useful in them" << endl;

	}
	if (strcmp(thing, "book") )
	{
		cout << "the book is labeled 'How to Serve Humans'. maybe the creature was trying to learn" << endl;
		cout << "how to be i society. maybe he was good" << endl;

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

void Space11::read(char* thing)
{
	if (strcmp(thing, "book"))
	{
		cout << "wait a minute... THIS IS A COOK BOOK! \n" << endl;

	}
	else
	{
		cout << "you cant do that" << endl;
	}
}
