/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 5 of 25 in the game
*/

#ifndef SPACE5_HPP
#define SPACE5_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space5 : public Space
{
	private:
		vector<Objects> space5;
		bool swordFound;
	public:
		Space5();
		~Space5();

		void look (char* thing);
		void setSword(int set) { if (set == 1) {swordFound = true; } else { swordFound = false; } }
		bool getSword() { return swordFound; }
};
#endif // !SPACE5_HPP
