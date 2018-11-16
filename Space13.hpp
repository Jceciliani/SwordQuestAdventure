/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 13 of 25 in the game
*/

#ifndef SPACE13_HPP
#define SPACE13_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space13 : public Space
{
	private:
		vector<Objects> space13;
		bool fountianUsed;
		bool gateOpened;
		bool forgeLit;
	public:
		Space13();
		~Space13();

		void look(char* thing);
		void drink(char* thing);
		void start(char* thing);
		void open(char* thing);
		void use(char* thing);
};
#endif // !SPACE13_HPP
