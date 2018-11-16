/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 20 of 25 in the game
*/

#ifndef SPACE20_HPP
#define SPACE20_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space20 : public Space
{
	private:
		vector<Objects> space20;
		bool fountianUsed;
	public:
		Space20();
		~Space20();

		void look(char* thing);
		void drink(char* thing);
		void enter(char* thing);
};
#endif // !SPACE20_HPP
