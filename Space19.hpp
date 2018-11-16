/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 19 of 25 in the game
*/

#ifndef SPACE19_HPP
#define SPACE19_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space19 : public Space
{
	private:
		vector<Objects> space19;
		bool containerOpen;
		bool lock1Open;
		bool lock2Open;
		bool lock3Open;
	public:
		Space19();
		~Space19();

		void look(char* thing);
		void pull(char* thing);
		void open(char* thing);
};
#endif // !SPACE19_HPP
