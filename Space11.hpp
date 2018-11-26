/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 11 of 25 in the game
*/

#ifndef SPACE11_HPP
#define SPACE11_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space11 : public Space
{
	private:
		vector<Objects> space11;
	public:
		Space11();
		~Space11();

		void look(const char* thing);
		void search(const char* thing);
		void read(const char* thing);
};
#endif // !SPACE11_HPP
