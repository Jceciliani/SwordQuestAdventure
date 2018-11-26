/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 14 of 25 in the game
*/

#ifndef SPACE14_HPP
#define SPACE14_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space14 : public Space
{
	private:
		vector<Objects> space14;
		bool crossed;
	public:
		Space14();
		~Space14();

		void look(const char* thing);
		void run(const char* thing);
		void jump(const char* thing);
		void setCross(int set) { if (set == 1) { crossed = true; } else { crossed = false; } }
		bool getCross() { return crossed; }

};
#endif // !SPACE14_HPP
