/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: This controls the flow of the game and all of the interactions
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <string>

#include "Space1.hpp"
#include "Space2.hpp"
#include "Space3.hpp"
#include "Space4.hpp"
#include "Space5.hpp"
#include "Space6.hpp"
#include "Space7.hpp"
#include "Space8.hpp"
#include "Space9.hpp"
#include "Space10.hpp"
#include "Space11.hpp"
#include "Space12.hpp"
#include "Space13.hpp"
#include "Space14.hpp"
#include "Space15.hpp"
#include "Space16.hpp"
#include "Space17.hpp"
#include "Space18.hpp"
#include "Space19.hpp"
#include "Space20.hpp"
#include "Space21.hpp"
#include "Space22.hpp"
#include "Space23.hpp"
#include "Space24.hpp"
#include "Space25.hpp"

using namespace std;

class Game
{
	private:
		Space **spaceArr;
		Space *playerLoc;
		Characters* char1;
		Characters* char2;
	public:
		Game();
		~Game();
		void play();
		int move(string input);
		void fight();
		void transfer(Objects, Objects); // Object 1 Equipped, Object 2 Bag
		void bagToForge(Objects);
		void bagToStash(Objects);
		void forgeToBag(Objects);
		void stashToBag(Objects);
};
#endif // !GAME_HPP

