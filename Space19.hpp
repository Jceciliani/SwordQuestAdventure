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
		bool taken;
	public:
		Space19();
		~Space19();

		void look(const char* thing);
		void pull(const char* thing);
		void open(const char* thing);
		void setContainerOpen(int set) { if (set == 1) { containerOpen = true; } else { containerOpen = false; } }
		bool getContainerOpen() { return containerOpen; }
		void setLock1(int set) { if (set == 1) { lock1Open = true; } else { lock1Open = false; } }
		bool getLock1() { return lock1Open; }
		void setLock2(int set) { if (set == 1) { lock2Open = true; } else { lock2Open = false; } }
		bool getLock2() { return lock2Open; }
		void setLock3(int set) { if (set == 1) { lock3Open = true; } else { lock3Open = false; } }
		bool getLock3() { return lock3Open; }
		void setTaken(int set) { if (set == 1) { taken = true; } else { taken = false; } }
		bool getTaken() { return taken; }
};
#endif // !SPACE19_HPP
