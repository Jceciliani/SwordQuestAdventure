/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 23 of 25 in the game
*/

#ifndef SPACE23_HPP
#define SPACE23_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space23 : public Space
{
	private:
		vector<Objects> space23;
		bool armorFound;
	public:
		Space23();
		~Space23();

		void look(const char* thing);
		void search(const char* thiing);
		void eat(const char* thing);
		void setFound(int set) { if (set == 1) { armorFound = true; } else { armorFound = false; } }
		bool getFound() { return armorFound; }
};
#endif // !SPACE23_HPP
