/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 2 of 25 in the game
*/

#ifndef SPACE2_HPP
#define SPACE2_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space2 : public Space
{
	private:
		vector<Objects> space2;
		bool hammerFound;
		bool taken;
	public:
		Space2();
		~Space2();

		void look(const char* thing);
		void search(const char* thing);
		void setHammer(int set){if (set == 1){hammerFound = true;} else {hammerFound = false;}}
		bool getHammer(){return hammerFound;}
		void setTaken(int set) { if (set == 1) { taken = true; } else { taken = false; } }
		bool getTaken() { return taken; }
};
#endif // !SPACE2_HPP
