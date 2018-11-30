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
	name = "eastern sewers";
	shortForm = "Moss and mildew cover the sewer walls. You see a small corporeal form in the corner.\n\n"
	"Down the walkways to the east there is bright light coming from the Sewer Depths \n"
	"To the south there is a ladder leading to the Upper Maintenance area \n";
	longForm = "Foul scents waft up from the waterway, moss and mildew cover the sewer walls.\n"
		"You see a small corporeal form in the corner. You hope you do not meet a similar fate anytime soon\n\n"
		"Down the walkways to the east there is bright light coming from the Sewer Depths \n"
		"To the south there is a ladder leading to the Upper Maintenance area \n";

	id = 5;
	obj = new Two_Handed_Silver_Sword();
	swordFound = false;
	combatEncounter = false;
	visited = false;
	taken = false;
}

Space5::~Space5()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space5::look(const char* thing)
{
	if (strcmp(thing, "walkways") == 0)
	{
		cout << "Don't. It's gross" << endl;

	}
	else if (strcmp(thing, "walls") == 0)
	{
		cout << "They are covered in moss and mildew. It's hard to understand how things can grow" << endl;
		cout << "in such a disgusting place. The wonders of nature." << endl;
	}
	else if (strcmp(thing, "corner") == 0 || strcmp(thing, "form") == 0)
	{
		if (taken == false) {
			cout << "The body appears to have been a guard here at some point. Looking at the" << endl;
			cout << "silver sword sticking out of his chest, it's not hard to tell how he died." << endl;
			cout << "The question is, did he put it there or someone else?" << endl;
			swordFound = true;
		}
		else
		{
			cout << "The body appears to have been a guard here at some point. Looking at the" << endl;
			cout << "sword wound in his chest its not hard to tell how he died." << endl;
			cout << "The question is, did he put it there or someone else?" << endl;
		}
	}
	else
	{
		cout << "You can't do that" << endl;
	}
}
