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
	shortForm = "The path continues upward. You can start to feel heat coming off the mountain. \n"
	"An old man sits in the middle of the path\n";
	longForm = "The path continues upward. You can start to feel heat coming off the mountain. \n"
	"An old man sits in the middle of the path \n\n"
	"The path to the east continues up the volcano \n";
	id = 22;
	obj = NULL;
	combatEncounter = false;
	visited = false;
	answered = false;
	correct = false;
}

Space22::~Space22()
{}
void Space22::addToContainer(Objects obj)
{
	space22.push_back(obj);
}

void Space22::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space22.size(); i++)
	{
		if(space22[i].getName() == obj.getName())
		{
			space22.erase(space22.begin() + i);
			return;
		}
	}

}

void Space22::printContainer()
{
	for(int i = 0; i < space22.size(); i++)
	{
		cout << space22[i].getName() << endl;
	}	
}

void Space22::look(char* thing)
{
	if (strcmp(thing, "old man"))
	{

			cout << "he is clothed in rags. The old man is also bald  with a long white beard. Why he" << endl;
			cout << "is sitting cross legged in the middle of the  path you have no idea" << endl;
	

	}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space22::talk(char* thing)
{
	if (strcmp(thing, "to old man"))
	{

			if(!answered)
			{
				cout <<" the old man speaks:" << endl;
				cout <<" The more of me you take, the more of me you leave behind. what am i?" << endl;
			}
			else
			{
				cout <<" the old man is silent" << endl;
			}

	}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space22::answer(char* thing)
{
	answered = true;
	if (strcmp(thing, "footsteps"))
	{

			if(!answered)
			{
				cout <<" the old man smiles, and snaps his fingers. you feel warmness come over your body" << endl;
				answered = true;
				correct = true;
			}
			else
			{
				cout <<"the old man is silent" << endl;
			}

	}
	else
		{
			cout << "the old man shakes his head" << endl;
			answered = true;
		}
}
