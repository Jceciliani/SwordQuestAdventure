/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 9 of 25 in the game
*/

#ifndef SPACE9_HPP
#define SPACE9_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space9 : public Space
{
	private:
		vector<Objects> space9;
		bool hatchOpen;
		bool fountianUsed;
	public:
		Space9();
		~Space9();

		void look(const char* thing);
		void drink(const char* thing);
		void enter(const char* thing);
		void open(const char* thing);
		void setFountian(int set) { if (set == 1) { fountianUsed = true; } else { fountianUsed = false; } }
		bool getFountian() { return fountianUsed; }
		void setHatch(int set) { if (set == 1) { hatchOpen = true; } else { hatchOpen = false; } }
		bool getHatch() { return hatchOpen; }
};
#endif // !SPACE9_HPP
