/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 24 of 25 in the game
*/

#ifndef SPACE24_HPP
#define SPACE24_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space24 : public Space
{
	private:
		vector<Objects> space24;
	public:
		Space24();
		~Space24();

		void look(const char* thing);
		void pull(const char* thing);
};
#endif // !SPACE24_HPP
