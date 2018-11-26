/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 7 of 25 in the game
*/

#ifndef SPACE7_HPP
#define SPACE7_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space7 : public Space
{
	private:
		vector<Objects> space7;
		bool jumped;
		bool crossed;
	public:
		Space7();
		~Space7();

		void look(const char* thing);
		void jump(const char* thing);
		void run(const char* thing);
		void setCross(int set) { if (set == 1) { crossed = true; } else { crossed = false; } }
		bool getCross() { return crossed; }
		void setJump(int set) { if (set == 1) { jumped = true; } else { jumped = false; } }
		bool getJump() { return jumped; }
};
#endif // !SPACE7_HPP
