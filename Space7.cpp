/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 7 of 25 in the game
*/

#include "Space7.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

Space7::Space7()
{
	name = "Swamp";
	shortForm = "The room is covered in moss and vegetation. Majority of the room is submerged\n"
	"in a murky liquid. There is a narrow rope bridge that crosses to the eastern wall. A small \n"
	"mossy island is in the middle of the room\n";
	longForm = "The room is covered in moss and vegetation. Majority of the room is submerged\n"
	"in a murky liquid. There is a narrow rope bridge that crosses to the eastern wall. A small \n"
	"mossy island is in the middle of the room \n\n"
	"To the east is a small opening through the brush \n"
	"To the south is path thick with vegetation\n";
	id = 7;
	obj = NULL;
	combatEncounter = false;
	visited = false;
}

Space7::~Space7()
{}
void Space7::addToContainer(Objects obj)
{
	space7.push_back(obj);
}

void Space7::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < space7.size(); i++)
	{
		if(space7[i].getName() == obj.getName())
		{
			space7.erase(space7.begin() + i);
			return;
		}
	}

}

void Space7::printContainer()
{
	for(int i = 0; i < space7.size(); i++)
	{
		cout << space7[i].getName() << endl;
	}	
}

void Space7::look(string thing)
	{
		if(strcmp(thing, "moss") || strcmp(thing, "vegetation")))
		{
			cout << "plants, not too interesting." << endl; 

		}
		else if(strcmp(thing, "rope bridge") || strcmp(thing, "bridge"))
		{
			cout << "a bridge made from rope and wooden planks. The bridge is fairly low," << endl;
			cout <<  "almost touching the water. Seems sturdy enough to cross" << endl;	
		}
		else if(strcmp(thing, "murky liquid"))
		{
			cout << "its a pale brown-green color. That plus the thin film across the" << endl;
			cout << " top makes it difficult to discern anything beneath the surface. Mysterious bubbles" << endl;	
			cout << "come up below. You might not be alone." << endl;
		}
		else
		{
			cout << "you cant do that" << endl;
		}
	}



void Space7::jump(string thing)
	{
		if(strcmp(thing, "to island"))
		{
			cout << "you cross over the murky waters to the solid island." << endl;
			cout <<  "You could probably make it to either opening from here" << endl; 
			jumped = true;

		}
		else if(strcmp(thing, "west") || strcmp(thing, "south"))
		{
			if(jumped)
			{	
				cout << "you make it to the landing" << endl;
				jumped = false
			}
			else
		{
			cout << "you cant do that" << endl;
		}
		}
		else
		{
			cout << "you cant do that" << endl;
		}
	}

void Space7::run(string thing)
{
	
		if(strcmp(thing, "across bridge"))
		{
			cout << "you run across the bridge. You can feel something barely" << endl;
			cout <<  "grazing your heels but you make it across without incident." << endl; 
			if(crossed)
			{
				crossed = false;
			}
			else
			{
				crossed = true;
			}

		}
		else if(strcmp(thing, "west"))
		{
			if(!crossed)
			{
				cout << "you run across the bridge. You can feel something barely" << endl;
				cout <<  "grazing your heels but you make it across without incident." << endl; 
				crossed = true;
			}
			else{
				cout << "you cant do that. the bridge heads south from here" << endl;
			}
		}
		else if(strcmp(thing, "south"))
		{
			if(crossed)
			{
				cout << "you run across the bridge. You can feel something barely" << endl;
				cout <<  "grazing your heels but you make it across without incident." << endl; 
				crossed = false;
			}
			else{
				cout << "you cant do that. the bridge heads west from here" << endl;
			}
		}
}