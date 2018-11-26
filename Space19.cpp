/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 19 of 25 in the game
*/

#include "Space19.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space19::Space19()
{
	name = "Volcano Lvl. 5";
	shortForm = " In the face of the volcano you can see a small locked compartment. \n"
	"Beside it there is a blue lever, red lever, and a green lever.\n";
	longForm = "The air is thick with ash. The trial stops at another landing. In the face of the \n"
		"volcano you can see a small locked compartment. Beside it there is a blue lever, red lever,\n"
		"and a green lever.\n\n";

	id = 19;
	obj = new Key();
	combatEncounter = false;
	visited = false;
	containerOpen = false;
	lock1Open = false;
	lock2Open = false;
	lock3Open = false;
}

Space19::~Space19()
{
	if (obj != NULL)
	{
		delete obj;
	}
}

void Space19::look(const char* thing)
{
if (strcmp(thing, "compartment") == 0)
	{
		cout << "a small box set into the face of the mountian." << endl;
		if(containerOpen)
		{
			cout << "the compartment is open" << endl;
		}
		else
		{
			cout << "It has 3 colored locks on it. A red a blue and a green." << endl;
		}
	}
else if (strcmp(thing, "in compartment") == 0)
	{
		if(containerOpen)
		{
			cout << "inside you find a large iron key" << endl;
		}
		else
		{
			cout << "the container is closed and locked" << endl;
		}
	}
	else if(strcmp(thing, "levers") == 0)
	{
			cout << " levers. they probably unlock something. It would be convienient if that lock were close by huh?" << endl; 
			cout << "there is a red lever, a green lever and a blue lever" << endl; 
	}

	else if(strcmp(thing, "red lever") == 0)
	{
			cout << " a red lever. probably unlocks something. It would be convienient if that lock were close by huh?" << endl; 

	}
	else if(strcmp(thing, "green lever") == 0)
	{
			cout << " a green lever. probably unlocks something. It would be convienient if that lock were close by huh?" << endl; 

	}
	else if(strcmp(thing, "blue lever") == 0)
	{
			cout << " a blue lever. probably unlocks something. It would be convienient if that lock were close by huh?" << endl; 

	}
else
		{
			cout << "you cant do that" << endl;
		}
}

void Space19::pull( const char* thing)
{
if(strcmp(thing, "red lever") == 0)
	{
			if(!lock1Open)
			{
			cout << "as you pull you hear a light click" << endl;
			lock1Open = true;
			}
			else 
			{
				cout << "as you pull you hear a heavy thud" << endl;
				lock1Open = false;
				lock2Open = false;
				lock3Open = false;
			}
	}
	else if(strcmp(thing, "green lever") == 0)
	{
			if(lock1Open && !lock2Open){
			cout << "as you pull you hear a light click" << endl;
			lock2Open = true;
			}
			else 
			{
				cout << "as you pull you hear a heavy thud" << endl;
				lock1Open = false;
				lock2Open = false;
				lock3Open = false;
			}
	}
	else if(strcmp(thing, "blue lever") == 0)
	{
			if(lock2Open && lock1Open && !lock3Open){
			cout << "as you pull you hear a light click" << endl;
			lock3Open = true;
			}
			else 
			{
				cout << "as you pull you hear a heavy thud" << endl;
				lock1Open = false;
				lock2Open = false;
				lock3Open = false;
			}
	}
}



void Space19::open(const char* thing)
{
	if (strcmp(thing, "compartment") == 0)
	{
		if (!containerOpen) {
			if (lock1Open && lock2Open && lock3Open)
			{
				cout << "the door is stiff but with effort it opens. the container is now open" << endl;
				containerOpen = true;
			}
			else
			{
				cout << "the door to the compartment wont budge" << endl;
			}
		}
		else {
			cout << "the door is already open" << endl;
		}
	}
}