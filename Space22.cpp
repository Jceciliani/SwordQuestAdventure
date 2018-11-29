/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 22 of 25 in the game
*/

#include "Space22.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space22::Space22()
{
	name = "Volcano Lvl. 2";
	shortForm =	"An old man sits in the middle of the path\n";
	longForm = "The path continues upward. You can start to feel heat coming off the mountain. \n"
		"An old man sits in the middle of the path \n\n";

	id = 22;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	answered = false;
	correct = false;
}

Space22::~Space22()
{}


void Space22::look(const char* thing)
{
	if (strcmp(thing, "old man") == 0)
	{

			cout << "he is clothed in rags. The old man is also bald  with a long white beard. Why he" << endl;
			cout << "is sitting cross legged in the middle of the  path you have no idea" << endl;
	

	}
	if (strcmp(thing, "mountian") == 0 || strcmp(thing, "volcano") == 0)
	{

		cout << "with the heat you are feeling it is becoming much mor apparent that you are infact on a volcano \n" << endl;
		cout << "but there is no turning back now. you must push on \n\n" << endl;


	}

	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space22::talk(const char* thing)
{
	if (strcmp(thing, "to old man") == 0)
	{

			if(!answered)
			{
				cout <<" the old man speaks:" << endl;
				cout <<" The more of me you take, the more of me you leave behind. what am i?" << endl;
			}
			else
			{
				if (!correct) 
				{
					cout << " the old man silently frowns at you" << endl;
				}
				else
				{
					cout << " the old man silently smiles at you" << endl;
				}
			}


	}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space22::answer(const char* thing)
{
	if (strcmp(thing, "footsteps") == 0)
	{

			if(!answered)
			{
				cout <<" the old man smiles, and snaps his fingers. you feel warmness come over your body" << endl;
				answered = true;
				correct = true;
			}
			else
			{
				if (!correct)
				{
					cout << " the old man silently frowns at you" << endl;
				}
				else
				{
					cout << " the old man silently smiles at you" << endl;
				}
			}

	}
	else
	{
		if (!answered)
		{
			cout << "the old man shakes his head" << endl;
			answered = true;
		}
		else
		{
			if (!correct)
			{
				cout << " the old man silently frowns at you" << endl;
			}
			else
			{
				cout << " the old man silently smiles at you" << endl;
			}
		}
	}
}
