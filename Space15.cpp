/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 15 of 25 in the game
*/

#include "Space15.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

Space15::Space15()
{
	name = "Crypt";
	shortForm = "The room is filled with candles that were used up long ago and a plethora of \n"
	"intricately painted pots and vases. In the center of the room is a large tomb\n";
	longForm = "The room is filled with candles that were used up long ago and a plethora of \n"
	"intricately painted pots and vases. In the center of the room is a large tomb \n\n"
	"To the west is a doorway to leads to a dimly lit corridor \n";
	id = 15;
	obj = new Steel();
	combatEncounter = false;
	visited = false;
	steelFound = false;
	tombOpen = false;
}

Space15::~Space15()
{
	if (obj != NULL)
	{
		delete obj;
	}
}
void Space15::addToContainer(Objects obj)
{
	space15.push_back(obj);
}

void Space15::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space15.size(); i++)
	{
		if(space15[i].getName() == obj.getName())
		{
			space15.erase(space15.begin() + i);
			return;
		}
	}

}

void Space15::printContainer()
{
	for(int i = 0; i < space15.size(); i++)
	{
		cout << space15[i].getName() << endl;
	}	
}


void Space15::look(char* thing)
{
if(strcmp(thing, "candles"))
		{
			cout << "used up candles. Kinda pointless to collect the wax" << endl; 
		}

	else if(strcmp(thing, "vases"))
	{
			cout << "a bunch of pots and vases. Most of them are painted very well, maybe as an" << endl; 
			cout << "offering. Or is the offering inside of them?" << endl;	
	}
	else if(strcmp(thing, "tomb"))
	{
			cout << "a large tomb made of stone. The patterns on the lid makes you think it is not royalty" << endl; 
			cout << "with in, but probably someone important" << endl;	
	}
	else if(strcmp(thing, "in tomb"))
	{
			if(tombOpen){
			cout << "inside you find a skeleton. Shocker. The skeleton is dressed in simple clothes." << endl; 
			cout << "Simpler than youd expect." << endl;	
			}
			else{
				cout << "the tomb is closed" << endl;
			}
	}
	else
		{
			cout << "you cant do that" << endl;
		}
}

void Space15::search(char* thing)
{
	if (strcmp(thing, "vases"))
	{
		cout << "used up candles. Kinda pointless to collect the wax" << endl;
	}
	else if (strcmp(thing, "skeleton") || strcmp(thing, "clothes"))
	{
		cout << "in one of the skeletons pockets you find a note. It is a letter to the" << endl;
		cout << "new forge master. It reads" << endl;
		cout << "now that you are replacing me as forge master you should know a few things. Our forge is in" << endl;
		cout << "bad condition and dies every few days. Its easy enough to get restarted though. Just hit some" << endl;
		cout << "flint and steel together and that ought to spark it up! Then you can continue banging away with " << endl;
		cout << "your forge hammer as usual. Good luck!" << endl;

	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space15::attack(char* thing)
{
	if (strcmp(thing, "vases"))
	{
		cout << "like a true hylian you start hurling jar after jar after at the wall. After a few you" << endl;
		cout << "feel kinda bad so you stop. But one of the busted pots had a bunch of steel!" << endl;
		cout << "Maybe itll be useful?" << endl;
		steelFound = true;

	}
	else
	{
		cout << "you cant do that" << endl;
	}
}

void Space15::open(char* thing)
{
	if (strcmp(thing, "tomb"))
	{
		if (tombOpen)
		{
			cout << "the tomb is already open" << endl;

		}
		else
		{
			cout << "with a grunt and a shove you push the top off the tomb. The tomb is now open" << endl;
			tombOpen = true;
		}
		cout << "like a true hylian you start hurling jar after jar after at the wall. After a few you" << endl;
		cout << "feel kinda bad so you stop. But one of the busted pots had a bunch of steel!" << endl;
		cout << "Maybe itll be useful?" << endl;
		steelFound = true;

	}
	else
	{
		cout << "you cant do that" << endl;
	}
}