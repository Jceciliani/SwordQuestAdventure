/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 21 of 25 in the game
*/

#ifndef SPACE21_HPP
#define SPACE21_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space21 : public Space
{
	private:
		vector<Objects> space21;
		bool boulderMoved;
	public:
		Space21();
		~Space21();

		void look(const char* thing);
		void push(const char* thing);
		void setBoulder(int set) { if (set == 1) { boulderMoved = true; } else { boulderMoved = false; } }
		bool getBoulder() { return boulderMoved; }

};
#endif // !SPACE21_HPP
