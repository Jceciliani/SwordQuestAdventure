/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Base Space class for all 25 spaces in the game
*/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Characters.hpp"

using namespace std;

class Space
{
	protected:
		Space *north;
		Space *east;
		Space *south;
		Space *west;
		string name;
		string shortForm;
		string longForm;
		int id;
		Objects *obj;
		bool combatEncounter;
		bool visited;
		vector<Objects> space;
	public:
		Space();
		~Space();
		string getName();
		string getShortForm();
		string getLongForm();
		void printSpace();
		int getId();
		// Directions
		Space* getNorth();
		Space* getEast();
		Space* getSouth();
		Space* getWest();
		// Objects
		Objects getObject();
		virtual void addToContainer(Objects obj);
		virtual void deleteFromContainer(Objects obj);
		virtual void printContainer();
		Objects printItem(int i);
		int getSize();
		void setDirections(Space* N, Space* E, Space* S, Space* W);
		bool getVisited();
		bool checkVisited();
		void setVisited(int num){if(num == 1){visited = true;} else {visited = false;}}
		void setEncounter(int num){if(num == 1){combatEncounter = true;} else {combatEncounter = false;}}
		bool getEncounter();
		void setEncounter();
};
#endif // !SPACE_HPP
