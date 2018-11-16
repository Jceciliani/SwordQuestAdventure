/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 5 of 25 in the game
*/

#include "Space5.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space5::Space5()
{
	name = "Eastern Sewers";
	shortForm = "Foul scents waft up from the waterway, moss and mildew cover the sewer walls.\n"
	"You see a small corporeal form in the corner.\n";
	longForm = "Foul scents waft up from the waterway, moss and mildew cover the sewer walls.\n"
	"You see a small corporeal form in the corner. \n\n"
	"To the west down the walkway you see a bright light and an opening to outside. \n"
	"To the south there is a ladder leading up \n";
	id = 5;
	obj = new Two_Handed_Silver_Sword();
	combatEncounter = false;
	visited = false;
}

Space5::~Space5()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space5::look(char* thing)
{
	if (strcmp(thing, "walkways"))
	{
		cout << "dont. Its gross" << endl;

	}
	else if (strcmp(thing, "walls"))
	{
		cout << "they are covered in moss  and mildew. Its hard to understand how things can grow" << endl;
		cout << "in such a disgusting place. The wonders of nature." << endl;
	}
	else if (strcmp(thing, "walls") || strcmp(thing, "form"))
	{
		cout << "the body appears to have been a guard here at some point. Looking at the" << endl;
		cout << "silver sword sticking out of his chest its not hard to tell how he died." << endl;
		cout << "The question is did he put it there, or someone else?" << endl;
	}
	else
	{
		cout << "you cant do that" << endl;
	}
}