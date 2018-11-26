/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 25 of 25 in the game
*/

#ifndef SPACE25_HPP
#define SPACE25_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space25 : public Space
{
	private:
		vector<Objects> space25;
		bool flintFound;
	public:
		Space25();
		~Space25();

		void look(const char* thing);
		void attack(const char* thing);
		void setFlint(int set) { if (set == 1) { flintFound = true; } else { flintFound = false; } }
		bool getFlint() { return flintFound; }
};
#endif // !SPACE25_HPP
