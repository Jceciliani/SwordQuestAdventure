/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: Space 6 of 25 in the game
*/

#ifndef SPACE6_HPP
#define SPACE6_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space.hpp"

using namespace std;

class Space6 : public Space
{
	private:
		vector<Objects> space6;
		bool vineCut;
	public:
		Space6();
		~Space6();

		void look(const char* thing);
		void attack(const char* thing);
		void setVine(int set) { if (set == 1) { vineCut = true; } else { vineCut = false; } }
		bool getVine() { return vineCut; }
};
#endif // !SPACE6_HPP
