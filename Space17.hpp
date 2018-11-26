/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 17 of 25 in the game
*/

#ifndef SPACE17_HPP
#define SPACE17_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space17 : public Space
{
	private:
		vector<Objects> space17;
		bool fountianUsed;
	public:
		Space17();
		~Space17();

		void look(const char* thing);
		void drink(const char* thing);
		void setFountian(int set) { if (set == 1) { fountianUsed = true; } else { fountianUsed = false; } }
		bool getFountian() { return fountianUsed; }
};
#endif // !SPACE17_HPP
