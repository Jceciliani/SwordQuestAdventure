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
	public:
		Space8();
		~Space8();

		void look(char* thing);
		void search(char* thing);
};
#endif // !SPACE8_HPP
