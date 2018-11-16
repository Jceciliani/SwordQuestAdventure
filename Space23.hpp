/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 23 of 25 in the game
*/

#ifndef SPACE23_HPP
#define SPACE23_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space23 : public Space
{
	private:
		vector<Objects> space23;
	public:
		Space23();
		~Space23();

		void look(char* thing);
		void search(char* thiing);
};
#endif // !SPACE23_HPP
