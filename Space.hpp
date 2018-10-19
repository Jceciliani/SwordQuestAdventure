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
	public:
		Space();
		~Space();
		string getName();
		string getShortForm();
		string getLongForm();
		void printSpace();
		int getId();
		Space* getNorth();
		Space* getEast();
		Space* getSouth();
		Space* getWest();
		void setDirections(Space* N, Space* E, Space* S, Space* W);
		bool getVisited();
		bool getEncounter();
		void setEncounter();
};
#endif // !SPACE_HPP
