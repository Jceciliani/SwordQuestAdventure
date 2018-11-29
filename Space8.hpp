/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 8 of 25 in the game
*/

#ifndef SPACE8_HPP
#define SPACE8_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space8 : public Space
{
	private:
		vector<Objects> space8;
		bool swordFound;
		bool taken;
	public:
		Space8();
		~Space8();

		void look(const char* thing);
		void search(const char* thing);
		void setSword(int set) { if (set == 1) { swordFound = true; } else { swordFound = false; } }
		bool getSword() { return swordFound; }
		void setTaken(int set) { if (set == 1) { taken = true; } else { taken = false; } }
		bool getTaken() { return taken; }
};
#endif // !SPACE8_HPP
