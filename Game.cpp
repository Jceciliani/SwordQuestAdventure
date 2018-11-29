/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: This controls the flow of the game and all of the interactions
*/

#include "Game.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

// Container objects
Equipped eq;
Forge fg;
Bag ba;
Stash st;

Game::Game()
{
	// Create game board
	spaceArr = new Space*[25];
	spaceArr[0] = new Space1();
	spaceArr[1] = new Space2();
	spaceArr[2] = new Space3();
	spaceArr[3] = new Space4();
	spaceArr[4] = new Space5();
	spaceArr[5] = new Space6();
	spaceArr[6] = new Space7();
	spaceArr[7] = new Space8();
	spaceArr[8] = new Space9();
	spaceArr[9] = new Space10();
	spaceArr[10] = new Space11();
	spaceArr[11] = new Space12();
	spaceArr[12] = new Space13();
	spaceArr[13] = new Space14();
	spaceArr[14] = new Space15();
	spaceArr[15] = new Space16();
	spaceArr[16] = new Space17();
	spaceArr[17] = new Space18();
	spaceArr[18] = new Space19();
	spaceArr[19] = new Space20();
	spaceArr[20] = new Space21();
	spaceArr[21] = new Space22();
	spaceArr[22] = new Space23();
	spaceArr[23] = new Space24();
	spaceArr[24] = new Space25();

	// Create Connections
	// Space 1
	spaceArr[0]->setDirections(NULL, spaceArr[1], spaceArr[5], NULL);
	// Space 2
	spaceArr[1]->setDirections(NULL, NULL, NULL, spaceArr[0]);
	// Space 3
	spaceArr[2]->setDirections(NULL, spaceArr[3], spaceArr[7], NULL);
	// Space 4
	spaceArr[3]->setDirections(NULL, spaceArr[4], NULL, spaceArr[2]);
	// Space 5
	spaceArr[4]->setDirections(NULL, NULL, spaceArr[9], spaceArr[3]);
	// Space 6
	spaceArr[5]->setDirections(spaceArr[0], spaceArr[6], spaceArr[10], NULL);
	// Space 7
	spaceArr[6]->setDirections(NULL, NULL, spaceArr[11], spaceArr[5]);
	// Space 8
	spaceArr[7]->setDirections(spaceArr[2], spaceArr[8], spaceArr[12], NULL);
	// Space 9
	spaceArr[8]->setDirections(spaceArr[3], spaceArr[9], NULL, spaceArr[7]);
	// Space 10
	spaceArr[9]->setDirections(spaceArr[4], NULL, NULL, spaceArr[8]);
	// Space 11
	spaceArr[10]->setDirections(spaceArr[5], NULL, NULL, NULL);
	// Space 12
	spaceArr[11]->setDirections(spaceArr[6], spaceArr[12], spaceArr[16], NULL);
	// Space 13
	spaceArr[12]->setDirections(spaceArr[7], spaceArr[13], spaceArr[17], spaceArr[11]);
	// Space 14
	spaceArr[13]->setDirections(NULL, spaceArr[14], NULL, spaceArr[12]);
	// Space 15
	spaceArr[14]->setDirections(NULL, NULL, NULL, spaceArr[13]);
	// Space 16
	spaceArr[15]->setDirections(NULL, spaceArr[16], spaceArr[20], NULL);
	// Space 17
	spaceArr[16]->setDirections(spaceArr[11], NULL, NULL, spaceArr[15]);
	// Space 18
	spaceArr[17]->setDirections(NULL, NULL, NULL, NULL);
	// Space 19
	spaceArr[18]->setDirections(NULL, spaceArr[19], NULL, NULL);
	// Space 20
	spaceArr[19]->setDirections(NULL, NULL, spaceArr[24], NULL);
	// Space 21
	spaceArr[20]->setDirections(NULL, spaceArr[21], NULL, NULL);
	// Space 22
	spaceArr[21]->setDirections(NULL, spaceArr[22], NULL, NULL);
	// Space 23
	spaceArr[22]->setDirections(NULL, spaceArr[23], NULL, NULL);
	// Space 24
	spaceArr[23]->setDirections(spaceArr[18], NULL, NULL, NULL);
	// Space 25
	spaceArr[24]->setDirections(spaceArr[19], NULL, NULL, NULL);

	// Create Hero
	char1 = new Hero();	
	// Player starting location - Sancuary 
	playerLoc = spaceArr[12];

}
//  Delete board memory 
Game::~Game()
{
	// Loop deletion - buggy when used last time
	for (int i = 0; i < 25; i++)
	{
		delete spaceArr[i];
	}
	// Delete array
	delete[] spaceArr;
	delete char1;

}
//  Moves hero from space to space
int Game::move(string input)
{
	// Input validation: break out into separate function
	if (input.length() > 50/*maxInputLength*/)
	{
		cout << "Input must be 50 characters or less" << endl;
		return -1;
	}
	else if (input.find("don't") < 50/*maxInputLength*/ || input.find("Don't") < 50/*maxInputLength*/)
	{
		cout << "Please don't say don't. It confuses me." << endl;
		return -1;
	}
	else if (input == "look")
	{
		cout << playerLoc->getLongForm();
	}
	// end of input validation
	// Check for Save or Load Game command
	else if(input.find("savegame") < 50)
	{
		// Call save game function
		save();
		return 1;
	}
	else if(input.find("loadgame") < 50)
	{
		load();
		return 1;
	}
	else if(input.find("exit game") < 50)
	{
		//exit game
		cout << "exiting game" << endl;
		exit(0);
	}
	else if(input == "inventory")
	{
		cout << "\n-----------------------------------------------------------------------------------------" << endl;
		cout << "                        	        Inventory" << endl;
		cout << "-------------------------------------------------------------------------------------------" << endl;
		cout << "Equipped:" << endl;
		eq.printContainer();	
		cout << "-------------------------------------------------------------------------------------------" << endl;
		cout << "Bag" << endl;
		//Print out bag contents
		ba.printContainer();
		cout << "-------------------------------------------------------------------------------------------" << endl;	
		cout << "Stash" << endl;
		// Print out stash contents
		st.printContainer();	
	} 
	else if(input == "status")
	{
		cout << "\n-------------------------------------------------------------------------------------------" << endl; 
		cout << "Current Level: " << char1->getLevel() << endl;
		cout << "Current Health: " << char1->getHealth() << endl;
		cout << "-------------------------------------------------------------------------------------------" << endl;
	}
	else if(input == "help")
	{
		cout << endl;
		cout << "-------------------------------------------------------------------------------------------" << endl;
		cout << "                          AVAILABLE ACTIONS" << endl;
		cout << "-------------------------------------------------------------------------------------------" << endl;
		cout << "north, east, south, west:               Travel in that direction" << endl;
		cout << "<room name>:                            Travel to that room" << endl;
		cout << "look:                                   Get a detailed desciption of the room you are in" << endl;
		cout << "look at <object or feature>:            Get a description of the object or feature" << endl;
		cout << "look in:                                Investigate an object or feature" << endl;
		cout << "search:                                 Investigate an object or feature" << endl;   
		cout << "inventory:                              List your inventory" << endl;
		cout << "equip <item>:                           Use to change weapons and armor" << endl;
		cout << "unequip <item>:                         Use to change weapons and armor" << endl; 
		cout << "take:                                   Acquire an object, putting it in your inventory" << endl;
		cout << "put:                                    Place an object or item" << endl;
		cout << "eat / drink <object>:                   Attempt to eat or drink something" << endl;
		cout << "drop <item>:                            Drop the selected item in this room" << endl;
		cout << "pickup <item>:                          Use to acquire object or item" << endl;
		cout << "attack <object>:                        Attack something in the room" << endl;
		cout << "pull <object>:                          Pull on the object (usually a lever)" << endl;
		cout << "open:                                   Use for stash/forge and room interactions" << endl;
		cout << "use:                                    Interact with some objects and items" << endl;
		cout << "remove:                                 Take out objects and items" << endl; 
		cout << "status:                                 View your current level and hit points" << endl;
		cout << endl;
		cout << "savegame:                               Save your game" << endl;
		cout << "loadgame:                               Load saved game" << endl;
		cout << "exit game:                              Exit the game" << endl;
		cout << "-------------------------------------------------------------------------------------------" << endl << endl;
	} 
	else if (input.find("unequip") < 50)
	{
		if (ba.getSize() >= 5)
		{
			cout << "you cannot do that. your bag is full" << endl;
		}
		else
		{ 
			if (input.find(eq.getObject1().getName()) < 50)
			{
				if (eq.getObject1().getName() != "no sword")
				{
					cout << " you unequip " << eq.getObject1().getName() << endl;
					ba.addToContainer(eq.getObject1());
					eq.addEquipment(No_Sword());
				}
				else
				{
					cout << "you have nothing to unequip" << endl;
				}
			}
			else if (input.find(eq.getObject2().getName()) < 50)
			{
				if (eq.getObject2().getName() != "no armor")
				{
					cout << " you unequip " << eq.getObject2().getName() << endl;
					ba.addToContainer(eq.getObject2());
					eq.addEquipment(No_Armor());
				}
			
				else
				{
					cout << "you have nothing to unequip" << endl;
				}
			}
			
		}
	}
	else if (input.find("equip") < 50)
	{
		for (int i = 0; i < ba.getSize(); i++)
		{
			
			if (input.find(ba.printItem(i).getName()) < 50)
			{
				if (ba.printItem(i).getName().find("sword") < 50) {
					cout << " you equip " << ba.printItem(i).getName() << endl;
					Objects hold = eq.getObject1();
					eq.addEquipment(ba.printItem(i));
					ba.deleteFromContainer(ba.printItem(i));
					if (hold.getName() != "no sword")
					{
						ba.addToContainer(hold);
					}
				}
				else if (ba.printItem(i).getName().find("armor") < 50) {
					cout << " you equip " << ba.printItem(i).getName() << endl;
					Objects hold = eq.getObject2();
					eq.addEquipment(ba.printItem(i));
					ba.deleteFromContainer(ba.printItem(i));
					if (hold.getName() != "no armor")
					{
						ba.addToContainer(hold);
					}
				}
			}
		}
	}
	// Logic for moving different directions. Maybe refactor this down to a small function passing in the direction?
	// Create variables that recognize direction names
	string northLocationName;
	string eastLocationName;
	string southLocationName;
	string westLocationName;
	// Assign values if they exist ie: is there a room that direction?
	if (playerLoc->getNorth() == NULL)
	{
		northLocationName = "-- There is nothing to the north --";
	}
	else
	{
		northLocationName = playerLoc->getNorth()->getName();
	}
	if (playerLoc->getEast() == NULL)
	{
		eastLocationName = "-- There is nothing to the East --";
	}
	else
	{
		eastLocationName = playerLoc->getEast()->getName();
	}
	if (playerLoc->getSouth() == NULL)
	{
		southLocationName = "-- There is nothing to the South --";
	}
	else
	{
		southLocationName = playerLoc->getSouth()->getName();
	}
	if (playerLoc->getWest() == NULL)
	{
		westLocationName = "-- There is nothing to the West --";
	}
	else
	{
		westLocationName = playerLoc->getWest()->getName();
	}
	//cout << "The room to the north is: " << northLocationName << endl;
	//cout << "The result of input.find(northLocationName) is: " << input.find(northLocationName) << endl;
	if (input.find("North") < 50/*maxInputLength*/ || input.find("north") < 50 || input.find(northLocationName) < 50/*maxInputLength*/)
	{
		if (playerLoc->getNorth() == NULL)
		{
			cout << "It is forbidden to go there" << endl;
			return -1;
		}
		else
		{
			playerLoc = playerLoc->getNorth();
			return 0;
		}
	}
	else if (input.find("East") < 50/*maxInputLength*/ || input.find("east") < 50 || input.find(eastLocationName) < 50/*maxInputLength*/)
	{
		if (playerLoc->getEast() == NULL)
		{	
			cout << "It is forbidden to go there" << endl;
			return -1;
		}
		else
		{
			if (playerLoc == spaceArr[13])
			{
				if (s14.getCross() == true)
				{
					playerLoc = playerLoc->getEast();
				}
				else
				{
					cout << "as you cross the room you hear a loud THUNK. sunddenly the floor dissapears from beneith you" << endl;
					cout << "and you begin to fall. the sensation feels familiar. you are whisked down a large metal tube" << endl;
					cout << "getting coated with its innards in the process. you launch out of the tube and into a wall before falling to the ground." << endl;
					cout << "you find yourself in the Sewer Depths" << endl;
					playerLoc = spaceArr[3];
				}
			}
			else
			{
				playerLoc = playerLoc->getEast();
			}
			return 0;
		}
	}
	else if (input.find("South") < 50/*maxInputLength*/ || input.find("south") < 50 || input.find(southLocationName) < 50/*maxInputLength*/)
	{
		if (playerLoc->getSouth() == NULL)
		{
			cout << "It is forbidden to go there" << endl;
			return -1;
		}
		else
		{
			if (playerLoc == spaceArr[6])
			{
				if(s7.getJump() == true)
				{
					cout << "you cant walk anywhere from this island. try jumping!" << endl;
				}
				else if (s7.getCross() == false )
				{
					playerLoc = playerLoc->getSouth();
				}
				else
				{
					cout << "you slowly meander across the bridge. it dipps beneith your weight to the point it is partially submerged" << endl;
					cout << "about half way across the bridge, the creatures living hear find you. Pirahnas being launching themselves at you" << endl;
					cout << "biting at your ankles, hands, butt. whatever they can get at. You sprint to get away, but youve already" << endl;
					cout << "been torn to ribbons" << endl;
					playerLoc = playerLoc->getSouth();
					//damage
				}
			}
			else if (playerLoc == spaceArr[12])
			{
				if (s13.getGate() == true)
				{
					playerLoc = playerLoc->getSouth();
				}
				else
				{
					cout << "the gate blocks your path" << endl;
				}
			}
			else
			{
				playerLoc = playerLoc->getSouth();
			}
			return 0;
		}
	}
	else if (input.find("West") < 50/*maxInputLength*/ || input.find("west") < 50 || input.find(westLocationName) < 50/*maxInputLength*/)
	{
		if (playerLoc->getWest() == NULL)
		{
			cout << "It is forbidden to go there" << endl;
			return -1;
		}
		else
		{
			if (playerLoc == spaceArr[13])
			{
				if (s14.getCross() == false)
				{
					playerLoc = playerLoc->getWest();
				}
				else
				{
					cout << "as you cross the room you hear a loud THUNK. sunddenly the floor dissapears from beneith you" << endl;
					cout << "and you begin to fall. the sensation feels familiar. you are whisked down a large metal tube" << endl;
					cout << "getting coated with its innards in the process. you launch out of the tube and into a wall before falling to the ground." << endl;
					cout << "you find yourself in the Sewer Depths" << endl;
					playerLoc = spaceArr[3];
				}
			}
			else if (playerLoc == spaceArr[6])
			{
				
				if (s7.getJump() == true)
				{
					cout << "you cant walk anywhere from this island. try jumping!" << endl;
				}
				else if (s7.getCross() == true)
				{
					playerLoc = playerLoc->getWest();
				}
				else
				{
					cout << "you slowly meander across the bridge. it dipps beneith your weight to the point it is partially submerged" << endl;
					cout << "about half way across the bridge, the creatures living hear find you. Pirahnas being launching themselves at you" << endl;
					cout << "biting at your ankles, hands, butt. whatever they can get at. You sprint to get away, but youve already" << endl;
					cout << "been torn to ribbons" << endl;
					playerLoc = playerLoc->getWest();
					//damage
					char1->damage(-2);
				}
			}
			else
			{
				playerLoc = playerLoc->getWest();
			}
			return 0;
		}
	}
	else
	{
		// cout << "Sorry, I did not understand your input" << endl << endl;
		return -1;
	}
}



void Game::fight()
{
	// Damage variable to place into the defense function
	int damage;
	// Death checkers
	bool p1Death = false;
	bool p2Death = false;

	cout << "Entering the fight function" << endl;	

	while (p1Death == false && p2Death == false)
	{
		cout << char1->getName() << " attack: ";
		damage = char1->attack();
		cout << char2->getName() << " defense: ";
		char2->defense(damage);


		// check if player 2 died
		p2Death = char2->fatalBlow();

		if (p2Death == false)
		{
			cout << char2->getName() << " attack: ";
			damage = char2->attack();
			cout << char1->getName() << " defense: ";
			char1->defense(damage);
			cout << endl;
		}
		// check if player 1 died
		p1Death = char1->fatalBlow();
		
		cout << "Press enter to attack" << endl;
		// Pause screen	
		cin.get();
	}

	if (p1Death == true)
	{
		cout << "You have died." << endl;
		cout << "GAME OVER" << endl;
		exit(0);
	}
	else if (p2Death == true)
	{
		cout << "Congratulations! You won!" << endl;
		cout << "Level up! +2 Health" << endl;
		char1->levelUp();
		cout << "Current Level: " << char1->getLevel() << endl;
		cout << "Current Health: " << char1->getHealth() << endl;
		cout << "-------------------------------------------------------------------------------------------\n\n" << endl;

	}

}

// Container utiization functions *****************************************************
void Game::transfer(Objects obj1, Objects obj2)
{
	// Object 1 is in equipped, Object 2 is in bag

	// Transferring two objects at once
	// If the object is a sword
	if(obj1.getName().find("sword") != -1)
	{
		// Add Sword to Bag
		ba.addToContainer(obj1);

		// Delete Sword from equipped
		eq.deleteFromContainer(obj1);

		// Add New Sword to Equipped - position 0
		eq.insert(0, obj2);

		// Delete new sword from bag
		ba.deleteFromContainer(obj2);

		//TEST
		eq.setSword(obj2);
	}
	//If the object is armor
	else if(obj1.getName().find("armor") != -1)	
	{
		// Add Armor to bag
		ba.addToContainer(obj1);
		// Delete Armor from equipped
		eq.deleteFromContainer(obj1);

		// Add New Armor to Equipped - position 1
		eq.insert(1, obj2);

		// Delete new armor from bag
		ba.deleteFromContainer(obj2);

		//TEST
		eq.setArmor(obj2);
	}

	
}

void Game::bagToForge(Objects obj)
{
	ba.deleteFromContainer(obj);
	fg.addToContainer(obj);	
}

void Game::bagToStash(Objects obj)
{
	ba.deleteFromContainer(obj);
	st.addToContainer(obj);
}

void Game::forgeToBag(Objects obj)
{	
	fg.deleteFromContainer(obj);
	ba.addToContainer(obj);	
}

void Game::stashToBag(Objects obj)
{
	if(ba.getSize() < 5)
	{
		st.deleteFromContainer(obj);
		ba.addToContainer(obj);	
	}
	else
	{
		cout << "To bag can only hold 5 items" << endl;
	}	
}
//*********************************************************************************

// Healing function
void Game::heal()
{

	int health = 8 + (char1->getLevel() * 2);
	char1->setHealth(health);

}

void Game::play(bool loadgame)
{
	// Create Space objects

	int turns = 0;
	string charName;
	char choice;
	if (loadgame == true)
	{

		load();
	}
	else {
		cout << "You are falling before you can even stand." << endl;
		cin.ignore();
		cout << "CRACK" << endl;
		cout << "A streak of crimson hits you in the chest. You are sent hurling across the room" << endl;
		cout << "separated from your beloved farm tool. CRASH you meet the wall in a very unfriendly manner." << endl;
		cout << "You begin to feel your own shades of crimson begin to leak from your head and your chest." << endl;
		cout << "You have a loose grip on consciousness, but you can't give up. This may be your one chance." << endl;
		cout << "As you try to stand, you feel the floor beneath you shift. Suddenly the floor on this side" << endl;
		cout << "of the throne room begins to give way. You attempt to jump to safety but you are falling" << endl;
		cout << "before you can even stand." << endl;

		cin.ignore();

		cout << "Falling..." << endl;
		cin.ignore();
		cout << "Falling..." << endl;
		cin.ignore();
		cout << "Falling..." << endl;
		cin.ignore();
		cout << "You impact with a CRACK. Your consciousness fades to the ether.\n\n" << endl;
		cin.ignore();

		cout << "You wake with a start and everything is fuzzy.... What is your name?" << endl;
		cout << "> ";
		getline(cin, charName);
		// Set name to hero
		char1->setName(charName);
	}
	// Seperator before the game starts
	cout << "\n\n" << endl;
	cout << "Type <help> for list of actions\n\n" << endl;	
	// Randomize the game
	srand(time(NULL));
	while (turns < 10000)
	{


		// Shows locations
		if (playerLoc->getNorth() == NULL)
		{
			cout << "North: There is nothing there" << endl;
		}
		else
		{
			cout << "North: " << playerLoc->getNorth()->getName() << endl;
 		}
		if (playerLoc->getEast() == NULL)
		{
			cout << "East: There is nothing there" << endl;
		}
		else
		{
			cout << "East: " << playerLoc->getEast()->getName() << endl;
		}
		if (playerLoc->getSouth() == NULL)
		{
			cout << "South: There is nothing there" << endl;
		}
		else
		{
			cout << "South: " << playerLoc->getSouth()->getName() << endl;
		}
		if (playerLoc->getWest() == NULL)
		{
			cout << "West: There is nothing there" << endl;
		}
		else
		{
			cout << "West: " << playerLoc->getWest()->getName() << endl;
		}

		// Error handling
		while (1)
		{
			string input;
			cout << "What do you want to do?" << endl;
			cout << "> ";
			getline(cin, input);
			cout << endl;
			cout << "-------------------------------------------------------------------------------------------" << endl;
			int res = move(input);
			//if (res == -1)
			//{
				//cout << "It is forbidden to go there" << endl;

			//}
			//else
			//{
			if(playerLoc == spaceArr[0]) // Space1 Fields
			{
				if(input.find("grass") < 50)
				{
					if(input.find("look") < 50 || input.find("search") < 50)
					{	
						cout << "You look at the grass." << endl;
						s1.look("grass");
					}
					else if(input.find("attack") < 50 || input.find("hit") < 50)
					{
						cout << "You attack the grass" << endl;
						s1.attack("grass");
					}
					else
					{
						cout << "You can't do that to grass." << endl;
					}
				}
				else if(input.find("wind") < 50)
				{
					if(input.find("look") < 50)
					{	
						s1.look("wind");
					}
					else
					{
						cout << "you cant do that" << endl;
					}
				}
				else if (input.find("drop") < 50) 
				{
					bool candrop = false;
					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s1.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));
							candrop = true;
						}
					}
					if (candrop == false)
					{
						cout << "you cant do that" << endl;
					}
				}
				else if (input.find("pickup") < 50 || input.find("grab") < 50)
				{
					

					for (int i = 0; i < s1.getSize(); i++)
					{
						if (input.find(s1.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << ba.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s1.deleteFromContainer(ba.printItem(i));
						}
					}
				}

			}
			if(playerLoc == spaceArr[1]) // Space2 Ruins
			{
				if(input.find("ruin") < 50 || input.find("remains") < 50)
				{
					if(input.find("look") < 50 || input.find("gaze") < 50)
					{
						cout << "You look at the ruins" << endl;
						s2.look("ruins");
					}
					else if(input.find("take") < 50 || input.find("grab") < 50)
					{
						cout << "They're too big to take with you" << endl;
					}
					else if(input.find("search") < 50)
					{
						s2.search("ruins");
					}
					else
					{
						cout << "You can't do that to ruins" << endl;
					}
				}
				
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s2.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s2.getSize(); i++)
					{
						if (input.find(s2.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s2.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s2.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("hammer") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50 || input.find("pick up") < 50)
					{
						if (s2.getTaken() == true) {
							if (s2.getHammer() == true)
							{
								if (ba.getSize() >= 5)
								{
									cout << " the bag is full. you cant pick that up." << endl;
								}
								else
								{
									cout << "You pickup the Forge Hammer" << endl;
									ba.addToContainer(s2.getObject());
								}
							}

							else
							{
								cout << "You haven't found a hammer here" << endl;
							}
						}
						else {
							cout << " you already took that" << endl;
						}
					}
				}

			}
			if(playerLoc == spaceArr[2]) // Space3 Western Sewers
			{
				if(input.find("basket") < 50)
				{
					if(input.find("take") < 50 || input.find("grab") < 50)
					{
						s3.take("basket");
					}
					else if(input.find("look") < 50)
					{
						s3.look("basket");
					}
					else
					{
						cout << "You can't do that with the basket" << endl;
					}
				}
				else if(input.find("rope") < 50)
				{
					if(input.find("pull") < 50 || input.find("tug") < 50 || input.find("yank") < 50)
					{
						s3.pull("rope");
					}
					else if(input.find("look") < 50)
					{
						s3.look("rope");
					}
					else
					{
						cout << "That won't work with the rope." << endl;
					}
				}
				
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s3.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s3.getSize(); i++)
					{
						if (input.find(s3.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s3.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s3.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("armor") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s3.getPulled() == true)
						{
							if (s3.getTaken() == false) {
								if (ba.getSize() >= 5)
								{
									cout << " the bag is full. you cant pick that up." << endl;
								}
								else
								{
									cout << "You pickup the Bronze Armor" << endl;
									ba.addToContainer(s3.getObject());
									s3.setTaken(1);
								}
							}
							else
							{
								cout << " you already took that."
							}
						}

						else
						{
							cout << "You haven't found armor here" << endl;
						}
					}
				}
			}
			if(playerLoc == spaceArr[3]) // Space4 Sewer Depths
			{
				if(input.find("ocean") < 50)
				{
					if(input.find("look") < 50)
					{
						s4.look("ocean");
					}
					else if(input.find("take") < 50 || input.find("grab") < 50)
					{
						cout << "It's too big to take with you!" << endl;
					}
					else
					{
						cout << "You can't do that with the ocean" << endl;
					}
				}
				else if(input.find("bridge") < 50)
				{
					if(input.find("look") < 50 || input.find("search") < 50)
					{
						s4.look("bridge");
					}
					
					else
					{
						cout << "You can't do that with the bridge" << endl;
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s4.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s4.getSize(); i++)
					{
						if (input.find(s4.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s4.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s4.deleteFromContainer(ba.printItem(i));
						}
					}
				}
			}
			if(playerLoc == spaceArr[4]) // Space5 Eastern Sewers
			{
				if(input.find("wall") < 50)
				{
					if(input.find("look") < 50 || input.find("search") < 50)
					{
						s5.look("walls");
					}
					else
					{
						cout << "You can't do that with the wall" << endl;
					}
				}
				else if(input.find("form") < 50)
				{
					if(input.find("look") < 50 || input.find("search") < 50)
					{
						s5.look("form");
					}
					else if(input.find("eat") < 50)
					{
						cout << "Well... desperate times...you feel worse now." << endl;
						//damage character
						char1->damage(-1);
					}
					else
					{
						cout << "You can't do that" << endl;
					}
				}
				
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s5.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s5.getSize(); i++)
					{
						if (input.find(s5.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s5.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s5.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("sword") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s5.getTaken() == false)
						{
							if (s5.getSword() == true)
							{
								if (ba.getSize() >= 5)
								{
									cout << " the bag is full. you cant pick that up." << endl;
								}
								else
								{
									cout << "You pickup the Silver Sword" << endl;
									ba.addToContainer(s5.getObject());
								}
							}

							else
							{
								cout << "You haven't found a sword here" << endl;
							}
						}
						else
						{
							cout << "you already took this" << endl;
						}
					}
				}
			}
			if(playerLoc == spaceArr[5]) // Space6 Jungle
			{
				if(input.find("canopy") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s6.look("canopy");
					}
				}
				else if(input.find("vegitation") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s6.look("vegitation");
					}
				}
				else if(input.find("vines") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s6.look("vines");
					}
					else if (input.find("attack") < 50 || input.find("cut") < 50 || input.find("hack") < 50)
					{
						s6.attack("vines");
					}
				}
				
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s6.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s6.getSize(); i++)
					{
						if (input.find(s6.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s6.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s6.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("armor") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s6.getTaken() == false) {
							if (s6.getVine() == true)
							{
								if (ba.getSize() >= 5)
								{
									cout << " the bag is full. you cant pick that up." << endl;
								}
								else
								{
									cout << "You pickup the Silver Armor" << endl;
									ba.addToContainer(s6.getObject());
								}
							}

							else
							{
								cout << "You haven't found armor here" << endl;
							}
						}
						else
						{
							cout << "you already took that" << endl;
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[6]) // Space7 Swamp
			{
				if(input.find("moss") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s7.look("moss");
					}
				}
				else if(input.find("bridge") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s7.look("bridge");
					}
					if (input.find("run") < 50 || input.find("sprint") < 50)
					{
						s7.run("bridge");
					}
					if (input.find("use") < 50)
					{
						// Damage from the trap
						char1->damage(-2);
					}
				}
				else if(input.find("liquid") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s7.look("liquid");
					}
				}
				else if (input.find("island") < 50)
				{
					if (input.find("jump") < 50 || input.find("hop") < 50)
					{
						s7.jump("island");
					}
				}
				else if (input.find("west") < 50)
				{
					if (input.find("jump") < 50 || input.find("hop") < 50)
					{
						s7.jump("west");
					}
					if (input.find("run") < 50)
					{
						s7.run("west");
					}
				}
				else if (input.find("south") < 50)
				{
					if (input.find("jump") < 50 || input.find("hop") < 50)
					{
						s7.jump("south");
					}
					if (input.find("run") < 50)
					{
						s7.run("south");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s7.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s7.getSize(); i++)
					{
						if (input.find(s7.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s7.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s7.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[7]) // Space8 Guard Quarters
			{
				if(input.find("papers") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s8.look("papers");
					}
				}
				else if(input.find("desk") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s8.look("desk");
					}
				}
				else if(input.find("locker") < 50)
				{
					if (input.find("look") < 50)
					{
						s8.look("locker");
					}
					else if (input.find("search") < 50)
					{
						if (input.find("13") < 50)
						{
							s8.search("locker 13");
						}
						else if (input.find("locker 1") < 50 || input.find("locker 2") < 50 || input.find("locker 3") < 50 || input.find("locker 4") < 50 ||
							input.find("locker 5") < 50 || input.find("locker 6") < 50 || input.find("locker 7") < 50 || input.find("locker 8") < 50 ||
							input.find("locker 9") < 50 || input.find("locker 10") < 50 || input.find("locker 11") < 50 || input.find("locker 12") < 50 ||
							input.find("locker 14") < 50 || input.find("locker 15") < 50 || input.find("locker 16") < 50 || input.find("locker 17") < 50 ||
							input.find("locker 18") < 50 || input.find("locker 19") < 50 || input.find("locker 20") < 50 || input.find("locker 21") < 50 ||
							input.find("locker 22") < 50 || input.find("locker 23") < 50 || input.find("locker 24") < 50 || input.find("locker 25") < 50 ||
							input.find("locker 26") < 50 || input.find("locker 27") < 50 || input.find("locker 28") < 50 || input.find("locker 29") < 50 ||
							input.find("locker 30") < 50)
						{
							s8.search("locker 1");
						}
						else if (input.find("lockers") < 50)
						{
							s8.search("lockers");
						}
					}
				}

				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s8.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s8.getSize(); i++)
					{
						if (input.find(s8.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s8.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s8.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("sword") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s8.getTaken() == true) {
							if (s8.getSword() == true)
							{
								if (ba.getSize() >= 5)
								{
									cout << " the bag is full. you cant pick that up." << endl;
								}
								else
								{
									cout << "You pickup the Bronze Sword" << endl;
									ba.addToContainer(s8.getObject());
								}
							}

							else
							{
								cout << "You haven't found a sword here" << endl;
							}
						}
						else
						{
							cout << "you already took that" << endl;
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[8]) // Space9 Lower Maintenance
			{
				if(input.find("fountain") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s9.look("fountian");
					}
					else if (input.find("drink") < 50)
					{
						if (!(s9.getFountian()))
						{
							heal();
						}
						s9.drink("fountian");
						
					}
				}
				else if(input.find("tube") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s9.look("tubes");
					}
					else if (input.find("enter") < 50 || input.find("go in") < 50)
					{
						s9.enter("tube");
						playerLoc = spaceArr[3];
					}
				}
				else if(input.find("hatch") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s9.look("hatch");
					}
					else if (input.find("open") < 50)
					{
						s9.open("hatch");
					}
					else if (input.find("enter") < 50 || input.find("go in") < 50)
					{
						s9.enter("tube");
						playerLoc == spaceArr[3];
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s9.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s9.getSize(); i++)
					{
						if (input.find(s9.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s9.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s9.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[9]) // Space10 Upper Maintenance
			{
				if(input.find("hovel") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s10.look("hovel");
					}
				}
				else if(input.find("corner") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s10.look("corner");
					}
				}
				else if(input.find("sack") < 50)
				{
					if (input.find("look") < 50)
					{
						s10.look("sack");
					}
					else if (input.find("search") < 50)
					{
						s10.search("sack");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s10.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s10.getSize(); i++)
					{
						if (input.find(s10.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s10.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s10.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[10]) // Space11 Cave
			{
				if(input.find("cave") < 50)
				{
					if (input.find("look") < 50)
					{
						s11.look("cave");
					}
					else if (input.find("search") < 50)
					{
						s11.search("cave");
					}
				}
				else if(input.find("pile") < 50)
				{
					if (input.find("look") < 50)
					{
						s11.look("cave");
					}
					else if (input.find("read") < 50)
					{
						s11.search("cave");
					}
				}
				else if(input.find("book") < 50 || input.find("search") < 50)
				{
					if (input.find("look") < 50)
					{
						s11.look("book");
					}
					else if (input.find("read") < 50)
					{
						s11.read("book");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s11.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s11.getSize(); i++)
					{
						if (input.find(s11.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s11.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s11.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[11]) // Space12 Crossroads
			{
		
				if(input.find("plot") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s12.look("plot");
					}
					else if (input.find("dig") < 50)
					{
						s12.dig("plot");
					}
				}
				else if(input.find("sign") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s12.look("sign");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s12.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s12.getSize(); i++)
					{
						if (input.find(s12.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s12.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s12.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[12]) // Space13 Sanctuary
			{

				if(input.find("fountain") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s13.look("fountian");
					}
					else if (input.find("drink") < 50)
					{
						if (!(s13.getFountian()))
						{
							heal();
						}
						s13.drink("fountian");
						
					}
				}
				else if(input.find("forge") < 50)
				{
					if (input.find("look in") < 50)
					{
						fg.printContainer();
					}
					else if (input.find("look") < 50)
					{
						s13.look("forge");
					}
					else if (input.find("put") < 50)
					{
						for (int i = 0; i < ba.getSize(); i++)
						{
							if (input.find(ba.printItem(i).getName()) < 50)
							{
								cout << " you put " << ba.printItem(i).getName() << "into the forge" << endl;
								fg.addToContainer(ba.printItem(i));
								ba.deleteFromContainer(ba.printItem(i));

							}
						}
					}
					else if (input.find("remove") < 50 || input.find("take") < 50)
					{
						for (int i = 0; i < fg.getSize(); i++)
						{
							if (input.find(fg.printItem(i).getName()) < 50)
							{
								if (ba.getSize() <= 5)
								{
									cout << " you take " << fg.printItem(i).getName() << "from the forge" << endl;
									ba.addToContainer(fg.printItem(i));
									fg.deleteFromContainer(fg.printItem(i));
								}
								else
								{
									cout << " your inventory is full" << endl;
								}
							}
						}
					}
					else if (input.find("use") < 50)
					{
						if (fg.getForgeStart() == true)
						{
							if (fg.ultArmorCrafted())
							{
								s13.use("forge");
								cout << " you created the ultimate armor" << endl;
								fg.clear();
								fg.addToContainer(fg.getUltArmor());
								fg.addToContainer(s2.getObject());
							}
						
							if (fg.ultWeaponCrafted())
							{
								s13.use("forge");
								cout << " you created the ultimate sword" << endl;
								fg.clear();
								fg.addToContainer(fg.getUltSword());
								fg.addToContainer(s2.getObject());
							}
						}
						else
						{
							s13.use("forge");
						}
					}
					else if (input.find("start") < 50)
					{
						if(fg.getForgeStart() == true)
						{
							s13.start("forge");
						}
						else
						{
							if (fg.startForge() == true)
							{
								s13.start("forge");
								s13.setForge(1);
								fg.clear();
							}
							else
							{
								cout << "you dont have the proper materials in the forge to start it" << endl;
							}
						}
					}
				}
				else if(input.find("chest") < 50)
				{
					if (input.find("look in") < 50)
					{
						st.printContainer();
					}
					else if (input.find("look") < 50)
					{
						s13.look("chest");
					}
					else if (input.find("put") < 50)
					{
						for (int i = 0; i < ba.getSize(); i++)
						{
							if (input.find(ba.printItem(i).getName()) < 50)
							{
								cout << " you put " << ba.printItem(i).getName() << " into the stash" << endl;
								st.addToContainer(ba.printItem(i));
								ba.deleteFromContainer(ba.printItem(i));

							}
						}
					}
					else if (input.find("take") < 50)
					{
						for (int i = 0; i < st.getSize(); i++)
						{
							if (input.find(st.printItem(i).getName()) < 50)
							{
								if (ba.getSize() <= 5)
								{
									cout << " you take " << st.printItem(i).getName() << "from the stash" << endl;
									ba.addToContainer(st.printItem(i));
									st.deleteFromContainer(st.printItem(i));
								}
								else
								{
									cout << " your inventory is full" << endl;
								}
							}
						}
					}
				}
				if (input.find("gate") < 50)
				{
					if (input.find("look") < 50)
					{
						s13.look("gate");
					}
					else if (input.find("open") < 50)
					{
						for (int i = 0; i < ba.getSize(); i++)
						{
							if (ba.printItem(i).getName() == "key")
							{
								s13.open("gate");
								s13.setGate(1);
							}
						}
						if (s13.getGate() == false)
						{
							cout << "you need a key to open the gate" << endl;
						}
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s13.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s13.getSize(); i++)
					{
						if (input.find(s13.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s13.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s13.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[13]) // Space14 Mausoleum
			{
				if(input.find("wall") < 50)
				{
					if (input.find("look") < 50)
					{
						s14.look("walls");
					}
				}
				else if(input.find("floor") < 50)
				{
					if (input.find("look") < 50)
					{
						s14.look("floor");
					}
				}
				else if (input.find("across") < 50)
				{
					if (input.find("jump") < 50 || input.find("hop") < 50)
					{
						s14.jump("across");
					}
					else if (input.find("run") < 50)
					{
						s14.run("across");
					}
				}
				else if (input.find("west") < 50)
				{
					if (input.find("jump") < 50 || input.find("hop") < 50)
					{
						s14.jump("west");
					}
					else if (input.find("run") < 50)
					{
						s14.run("west");
					}
				}
				else if (input.find("east") < 50)
				{
					if (input.find("jump") < 50 || input.find("hop") < 50)
					{
						s14.jump("east");
					}
					else if (input.find("run") < 50)
					{
						s14.run("east");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s14.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s14.getSize(); i++)
					{
						if (input.find(s14.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s14.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s14.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[14]) // Space15 Crypt
			{
				if(input.find("candle") < 50)
				{
					if (input.find("look") < 50)
					{
						s15.look("candles");
					}
				}
				else if(input.find("vase") < 50)
				{
					if (input.find("look") < 50)
					{
						s15.look("vases");
					}
					else if (input.find("attack") < 50 || input.find("smash") < 50)
					{
						s15.attack("vases");
					}
					else if (input.find("search") < 50)
					{
						s15.search("vases");
					}
				}
				else if(input.find("tomb") < 50)
				{
					if (input.find("look") < 50)
					{
						if (input.find("in") < 50)
						{
							s15.look("in tomb");
						}
						else
						{
							s15.look("tomb");
						}
					}
					else if (input.find("open") < 50)
					{
						s15.open("tomb");
					}
				}
				else if (input.find("skeleton") < 50)
				{
					if (input.find("look") < 50)
					{
						s15.look("skeleton");
					}
					else if (input.find("search") < 50)
					{
						s15.search("skeleton");
					}
				}

				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s15.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s15.getSize(); i++)
					{
						if (input.find(s15.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s15.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s15.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("steel") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s15.getTaken() == false) {
							if (s15.getSteel() == true)
							{
								if (ba.getSize() >= 5)
								{
									cout << " the bag is full. you cant pick that up." << endl;
								}
								else
								{
									cout << "You pickup the Steel" << endl;
									ba.addToContainer(s15.getObject());
								}
							}

							else
							{
								cout << "You haven't found steel here" << endl;
							}
						}
						else
						{
							cout << " you already took that" << endl;
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[15]) // Space16 Volcano Base
			{
				if(input.find("sign") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s16.look("sign");
					}
				}
				else if(input.find("bone") < 50)
				{
					if (input.find("look") < 50)
					{
						s16.look("bones");
					}
					else if (input.find("search") < 50)
					{
						s16.search("bones");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s16.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s16.getSize(); i++)
					{
						if (input.find(s16.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s16.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s16.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[16]) // Space17 Volcano Foothills
			{
				if(input.find("fountain") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s17.look("fountian");
					}
					else if (input.find("drink") < 50)
					{
						if (!(s17.getFountian()))
						{
							heal();
						}
						s17.drink("fountian");
					}
				}
				else if(input.find("volcano") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s17.look("volcano");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s17.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s17.getSize(); i++)
					{
						if (input.find(s17.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s17.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s17.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[17]) // Space18 Dragon Keep
			{
				cout <<  "END" << endl;
				exit(0);
				
			}
			if(playerLoc == spaceArr[18]) // Space19 Volcano lvl 5
			{
				if(input.find("compartment") < 50)
				{
					if (input.find("look") < 50)
					{
						if (input.find("in") < 50)
						{
							s19.look("in compartment");
						}
						else
						{
							s19.look("compartment");
						}
					}
					else if (input.find("open") < 50)
					{
						s19.open("compartment");
					}
				}
				else if(input.find("red lever") < 50)
				{
					if (input.find("look") < 50)
					{
						s19.look("red lever");
					}
					else if(input.find("pull") < 50 || input.find("grab") < 50)
					{
						s19.pull("red lever");
					}
				}
				else if(input.find("green lever") < 50)
				{
					if (input.find("look") < 50)
					{
						s19.look("green lever");
					}
					else if (input.find("pull") < 50 || input.find("grab") < 50)
					{
						s19.pull("green lever");
					}
				}
				else if(input.find("blue lever") < 50)
				{
					if (input.find("look") < 50)
					{
						s19.look("blue lever");
					}
					else if (input.find("pull") < 50 || input.find("grab") < 50)
					{
						s19.pull("blue lever");
					}
				}
				else if (input.find("lever") < 50)
				{
					if (input.find("look") < 50)
					{
						s19.look("levers");
					}
				}
				
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s19.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s19.getSize(); i++)
					{
						if (input.find(s19.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s19.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s19.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("key") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s19.getTaken() == false) {
							if (s19.getContainerOpen() == true)
							{
								if (ba.getSize() >= 5)
								{
									cout << " the bag is full. you cant pick that up." << endl;
								}
								else
								{
									cout << "You pickup the Key" << endl;
									ba.addToContainer(s19.getObject());
								}
							}

							else
							{
								cout << "You haven't found a key here" << endl;

							}
						}
						else {
							cout << "You already took that " << endl;
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[19]) // Space20 Volcano Summit
			{
				if(input.find("fountain") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s20.look("fountain");
					}
					else if (input.find("drink") < 50)
					{
						if (s20.getFountian() == false)
						{
							heal();
						}
						s20.drink("fountain");
					}
				}
				else if(input.find("rock") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s20.look("rocks");
					}
				}
				else if(input.find("gateway") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s20.look("gateway");
					}
					else if (input.find("enter") < 50 || input.find("go in") < 50)
					{
						s20.enter("gateway");
						playerLoc = spaceArr[12];
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s20.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s20.getSize(); i++)
					{
						if (input.find(s20.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s20.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s20.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[20]) // Space21 Volcano Lvl 1
			{
				if(input.find("boulder") < 50)
				{
					if (input.find("look") < 50)
					{
						s21.look("boulder");
					}
					else if (input.find("push") < 50)
					{
						s21.push("boulder");
					}
				}

				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s21.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s21.getSize(); i++)
					{
						if (input.find(s21.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s21.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s21.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("sword") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s21.getTaken() == false) {
							if (s21.getBoulder() == true)
							{
								if (ba.getSize() >= 5)
								{
									cout << " the bag is full. you cant pick that up." << endl;
								}
								else
								{
									cout << "You pickup the Gold Sword" << endl;
									ba.addToContainer(s21.getObject());
								}
							}

							else
							{
								cout << "You haven't found a sword here" << endl;
							}
						}
						else
						{
							cout << " you already took that" << endl;
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[21]) // Space22 Volcano Lvl 2
			{
				if(input.find("old man") < 50)
				{
					if (input.find("look") < 50)
					{
						s22.look("old man");
					}
					else if (input.find("talk") < 50 || input.find("speak") < 50 || input.find("call") < 50)
					{
						s22.talk("to old man");
						
					}
					
				}
				else if(input.find("mountain") < 50)
				{
					if (input.find("look") < 50)
					{
						s22.look("mountian");
					}
				}
				else if(input.find("volcano") < 50)
				{
					if (input.find("look") < 50)
					{
						s22.look("volcano");
					}
				}
				else if (input.find("answer") < 50)
				{
					if (input.find("footsteps") < 50)
					{
						s22.answer("footsteps");
						heal();
					}
					else
					{
						s22.answer("wrong");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s22.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s22.getSize(); i++)
					{
						if (input.find(s22.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s22.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s22.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[22]) // Space23 Volcano Lvl3
			{
				if(input.find("valuable") < 50)
				{
					if (input.find("look") < 50)
					{
						s23.look("valuables");
					}
					else if (input.find("search") < 50)
					{
						s23.search("valuables");
					}
				}
				else if(input.find("pile") < 50)
				{
					if (input.find("look") < 50)
					{
						s23.look("piles");
					}
					else if (input.find("search") < 50)
					{
						s23.search("piles");
					}
				}
				else if(input.find("trail") < 50)
				{
					if (input.find("look") < 50)
					{
						s23.look("trail");
					}
				}
				else if (input.find("bread") < 50)
				{
					if (input.find("look") < 50)
					{
						s23.look("bread");
					}
					else if (input.find("eat") < 50)
					{
						s23.eat("bread");
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s23.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s23.getSize(); i++)
					{
						if (input.find(s23.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s23.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s23.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else if (input.find("armor") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s23.getFound() == true)
						{
							if (ba.getSize() >= 5)
							{
								cout << " the bag is full. you cant pick that up." << endl;
							}
							else
							{
								cout << "You pickup the Gold Armor" << endl;
								ba.addToContainer(s23.getObject());
								
							}
						}
						else
						{
							cout << "You haven't found a armor here" << endl;
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[23]) // Space24 Volcano Lvl 4
			{
				if(input.find("lever") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s24.look("lever");
					}
					else if (input.find("pull") < 50 || input.find("grab") < 50)
					{
						s24.pull("lever");
						//damage
						char1->damage(-5);
						playerLoc = spaceArr[15];
					}
				}
				else if(input.find("landing") < 50)
				{
					if (input.find("look") < 50)
					{
						s24.look("landing");
					}
				}
				/*else if(input.find("locker") < 50)
				{

				}*/
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s24.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s24.getSize(); i++)
					{
						if (input.find(s24.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s24.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s24.deleteFromContainer(ba.printItem(i));
						}
					}
				}
				else
				{

				}
			}
			if(playerLoc == spaceArr[24]) // Space25 Volcanic Chamber
			{
				if(input.find("lake") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s25.look("lake");
					}
				}
				else if(input.find("stalagtite") < 50)
				{
					if (input.find("look") < 50 || input.find("search") < 50)
					{
						s25.look("stalagtite");
					}
					else if (input.find("attack") < 50 || input.find("hit") < 50)
					{
						s25.attack("stalagtite");
					
					}
				}
				else if (input.find("drop") < 50)
				{

					for (int i = 0; i < ba.getSize(); i++)
					{
						if (input.find(ba.printItem(i).getName()) < 50)
						{
							cout << " you drop " << ba.printItem(i).getName() << endl;
							s25.addToContainer(ba.printItem(i));
							ba.deleteFromContainer(ba.printItem(i));

						}
					}
				}
				else if (input.find("pickup") < 50)
				{

					for (int i = 0; i < s25.getSize(); i++)
					{
						if (input.find(s25.printItem(i).getName()) < 50)
						{
							cout << " you pickup " << s25.printItem(i).getName() << endl;
							ba.addToContainer(ba.printItem(i));
							s25.deleteFromContainer(ba.printItem(i));
						}
					}
				}

				else if (input.find("flint") < 50)
				{
					if (input.find("take") < 50 || input.find("grab") < 50)
					{
						if (s25.getFlint() == true)
						{
							if (ba.getSize() >= 5)
							{
								cout << " the bag is full. you cant pick that up." << endl;
							}
							else
							{
								cout << "You pickup the Flint" << endl;
								ba.addToContainer(s25.getObject());
							}
						}

						else
						{
							cout << "You haven't found flint here" << endl;
						}
					}
				}
				else
				{

				}
			}

			break;
			//}
		/*
			else
			{
				cout << "Invalid input - Please enter N, E, S or W." << endl;
			}
		*/	
		}

		//cout << "-------------------------------------------------------------------------------------------\n\n" << endl;
		cout << endl;
		// All the magic happens here - interaction with objects, fighting, etc.
		if (playerLoc == spaceArr[0])
		{
			if(s1.getVisited() == false)
			{
				if(s1.getEncounter() == false)
				{
					cout << "A NAGA APPEARED!\n\n" << endl;
					char2 = new Naga();
					fight();
					char2 = NULL;

				}
				cout << s1.getLongForm() << endl;
				if (s1.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s1.printContainer();
				}
			}
			else
			{
				cout << s1.getShortForm() << endl;
				if (s1.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s1.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[1])
		{
			if(s2.getVisited() == false)
			{
				cout << s2.getLongForm() << endl;
				if (s2.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s2.printContainer();
				}
			}
			else
			{
				cout << s2.getShortForm() << endl;
				if (s2.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s2.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[2])
		{
			if(s3.getVisited() == false)
			{
				cout << s3.getLongForm() << endl;
				if (s3.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s3.printContainer();
				}
			}
			else
			{
				cout << s3.getShortForm() << endl;
				if (s3.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s3.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[3])
		{
			if(s4.getVisited() == false)
			{
				if(s4.getEncounter() == false)
				{
					cout << "A GOBLIN APPEARED!\n\n" << endl;
					char2 = new Goblin();
					fight();
					char2 = NULL;
				}
				cout << s4.getLongForm() << endl;
				if (s4.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s4.printContainer();
				}
			}
			else
			{
				cout << s4.getShortForm() << endl;
				if (s4.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s4.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[4])
		{
			if(s5.getVisited() == false)
			{
				cout << s5.getLongForm() << endl; if (s5.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s5.printContainer();
				}
			}
			else
			{
				cout << s5.getShortForm() << endl; 
				if (s5.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s5.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[5])
		{
			if(s6.getVisited() == false)
			{
				
				cout << s6.getLongForm() << endl;
				if (s6.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s6.printContainer();
				}
			}
			else
			{
				cout << s6.getShortForm() << endl; 
				if (s6.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s6.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[6])
		{
			if(s7.getVisited() == false)
			{
				cout << s7.getLongForm() << endl;
				if (s7.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s7.printContainer();
				}
			}
			else
			{
				cout << s7.getShortForm() << endl;
				if (s7.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s7.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[7])
		{
			if(s8.getVisited() == false)
			{
				if(s8.getEncounter() == false)
				{
					cout << "A GIANT RAT APPEARED!\n\n" << endl;
					char2 = new Rat();
					fight();
					char2 = NULL;
				}
				cout << s8.getLongForm() << endl;
				if (s8.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s8.printContainer();
				}
			}
			else
			{
				cout << s8.getShortForm() << endl;
				if (s8.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s8.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[8])
		{
			if(s9.getVisited() == false)
			{
				cout << s9.getLongForm() << endl;
				if (s9.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s9.printContainer();
				}
			}
			else
			{
				cout << s9.getShortForm() << endl;
				if (s9.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s9.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[9])
		{
			if(s10.getVisited() == false)
			{
				if(s10.getEncounter() == false)
				{				
					cout << "A HOBGOBLIN APPEARED!\n\n" << endl;
					char2 = new Hobgoblin();
					fight();
					char2 = NULL;
				}
				cout << s10.getLongForm() << endl;
				if (s10.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s10.printContainer();
				}
			}
			else
			{
				cout << s10.getShortForm() << endl;
				if (s10.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s10.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[10])
		{
			if(s11.getVisited() == false)
			{
				if(s11.getEncounter() == false)
				{
					cout << "A TROLL APPEARED!\n\n" << endl;
					char2 = new Troll();
					fight();
					char2 = NULL;
				}
				cout << s11.getLongForm() << endl;
				if (s11.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s11.printContainer();
				}
			}
			else
			{
				cout << s11.getShortForm() << endl;
				if (s11.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s11.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[11])
		{
			if(s12.getVisited() == false)
			{
				cout << s12.getLongForm() << endl;
				if (s12.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s12.printContainer();
				}
			}
			else
			{
				cout << s12.getShortForm() << endl;
				if (s12.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s12.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[12])
		{

			if(s13.getVisited() == false)
			{
				cout << s13.getLongForm() << endl;
				if (s13.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s13.printContainer();
				}
			}
			else
			{
				cout << s13.getShortForm() << endl;
				if (s13.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s13.printContainer();
				}
			}	
		}
		else if (playerLoc == spaceArr[13])
		{
			if(s14.getVisited() == false)
			{
				cout << s14.getLongForm() << endl;
				if (s14.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s14.printContainer();
				}
			}
			else
			{
				cout << s14.getShortForm() << endl;
				if (s14.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s14.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[14])
		{
			if(s15.getVisited() == false)
			{
				cout << s15.getLongForm() << endl;
				if (s15.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s15.printContainer();
				}
			}
			else
			{
				cout << s15.getShortForm() << endl;
				if (s15.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s15.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[15])
		{
			if(s16.getVisited() == false)
			{
				cout << s16.getLongForm() << endl;
				if (s16.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s16.printContainer();
				}
			}
			else
			{
				cout << s16.getShortForm() << endl;
				if (s16.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s16.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[16])
		{
			if(s17.getVisited() == false)
			{
				cout << s17.getLongForm() << endl;
				if (s17.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s17.printContainer();
				}
			}
			else
			{
				cout << s17.getShortForm() << endl;
				if (s17.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s17.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[17])
		{
			if(s18.getVisited() == false)
			{
				if(s18.getEncounter() == false)
				{
					cout << "A DRAGON APPEARED!" << endl;
					char2 = new Dragon();
					fight();
					char2 = NULL;
		
				}
				cout << s18.getLongForm() << endl;

			}
			else
			{
				cout << s18.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[18])
		{
			if(s19.getVisited() == false)
			{
				if(s19.getEncounter() == false)
				{
					cout << "A MOUNTAIN GIANT APPEARED!\n\n" << endl;
					char2 = new Mountain_Giant();
					fight();
					char2 = NULL;
				}
				cout << s19.getLongForm() << endl;
				if (s19.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s19.printContainer();
				}
			}
			else
			{
				if(s19.getEncounter() == false)
				{
					cout << "A MOUNTAIN GIANT APPEARED!\n\n" << endl;
					char2 = new Mountain_Giant();
					fight();
					char2 = NULL;
				}
				cout << s19.getShortForm() << endl;
				if (s19.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s19.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[19])
		{
			if(s20.getVisited() == false)
			{
				cout << s20.getLongForm() << endl;
				if (s20.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s20.printContainer();
				}
			}
			else
			{
				cout << s20.getShortForm() << endl;
				if (s20.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s20.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[20])
		{
			if(s21.getVisited() == false)
			{
				if(s21.getEncounter() == false)
				{
					cout << "A WIZARD APPEARED!\n\n" << endl;
					char2 = new Wizard();
					fight();
					char2 = NULL;
				}

				cout << s21.getLongForm() << endl;
				if (s21.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s21.printContainer();
				}
			}
			else
			{
				if(s21.getEncounter() == false)
				{
					cout << "A WIZARD APPEARED!\n\n" << endl;
					char2 = new Wizard();
					fight();
					char2 = NULL;
				}
				cout << s21.getShortForm() << endl;
				if (s21.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s21.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[21])
		{
			if(s22.getVisited() == false)
			{
				cout << s22.getLongForm() << endl;
				if (s22.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s22.printContainer();
				}
			}
			else
			{
				cout << s22.getShortForm() << endl;
				if (s22.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s22.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[22])
		{
			if(s23.getVisited() == false)
			{
				if(s23.getEncounter() == false)
				{
					cout << "A GANG OF BANDITS!\n\n" << endl;
					char2 = new Gang_of_Bandits();
					fight();
					char2 = NULL;
				}
				cout << s23.getLongForm() << endl;
				if (s23.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s23.printContainer();
				}
			}
			else
			{
				if(s23.getEncounter() == false)
				{
					cout << "A GANG OF BANDITS!\n\n" << endl;
					char2 = new Gang_of_Bandits();
					fight();
					char2 = NULL;
				}
				cout << s23.getShortForm() << endl;
				if (s23.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s23.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[23])
		{
			if(s24.getVisited() == false)
			{
				cout << s24.getLongForm() << endl;
				if (s24.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s24.printContainer();
				}
			}
			else
			{
				cout << s24.getShortForm() << endl;
				if (s24.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s24.printContainer();
				}
			}
		}
		else if (playerLoc == spaceArr[24])
		{
			if(s25.getVisited() == false)
			{
				if (s23.getEncounter() == false)
				{
					cout << "A LESSER DRAKE!\n\n" << endl;
					char2 = new Lesser_Drake();
					fight();
					char2 = NULL;
				}
				cout << s25.getLongForm() << endl;
				if (s25.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s25.printContainer();
				}
			}
			else
			{
				cout << s25.getShortForm() << endl;
				if (s25.getSize() != 0)
				{
					cout << "on the ground you see the following items:" << endl;
					s25.printContainer();
				}
			}
		}
		else
		{ }

		turns++;
	}
}

void Game::save()
{


	cout << "Now Saving..." << endl;

	ofstream savefile ("SaveGame.txt");

	savefile << char1->getName() << ",";//character vars
	savefile << char1->getLevel() << ",";
	savefile << char1->getStrength() << ",";

	savefile << playerLoc->getId() << ",";

	savefile << eq.getObject1().getId() << ",";
	savefile << eq.getObject2().getId() << ",";

	savefile << ba.getSize()  << ",";//containers
	for(int i = 0; i < ba.getSize(); i++)
	{
		savefile << (ba.printItem(i)).getId() << ",";
	}

	savefile << st.getSize()  << ",";
	for(int i = 0; i < st.getSize(); i++)
	{
		savefile << (st.printItem(i)).getId() << ",";
	}

	savefile << fg.getSize()  << ",";
    for(int i = 0; i < fg.getSize(); i++)
	{
		savefile << (fg.printItem(i)).getId() << ",";
	}

	savefile << fg.getForgeStart() << ",";
	savefile << fg.ultArmorCrafted() << ",";
	savefile << fg.ultWeaponCrafted() << ",";
	
	//rooms
	savefile << s1.checkVisited() << ",";
	savefile << s1.getEncounter() << ",";
	savefile << s1.getSize()  << ",";
    for(int i = 0; i < s1.getSize(); i++)
	{
		savefile << (s1.printItem(i)).getId() << ",";
	}
	

	savefile << s2.checkVisited() << ",";
	savefile << s2.getEncounter() << ",";
	savefile << s2.getHammer() << ",";
	savefile << s2.getSize()  << ",";
    for(int i = 0; i < s2.getSize(); i++)
	{
		savefile << s2.printItem(i).getId() << ",";
	}
	savefile << s3.checkVisited() << ",";
	savefile << s3.getEncounter() << ",";
	savefile << s3.getPulled() << ",";
	savefile << s3.getSize()  << ",";
    for(int i = 0; i < s3.getSize(); i++)
	{
		savefile << s3.printItem(i).getId() << ",";
	}

	savefile << s4.checkVisited() << ",";
	savefile << s4.getEncounter() << ",";
	savefile << s4.getSize()  << ",";
    for(int i = 0; i < s4.getSize(); i++)
	{
		savefile << s4.printItem(i).getId() << ",";
	}

	savefile << s5.checkVisited() << ",";
	savefile << s5.getEncounter() << ",";
	savefile << s5.getSword() << ",";
	savefile << s5.getSize()  << ",";
    for(int i = 0; i < s5.getSize(); i++)
	{
		savefile << s5.printItem(i).getId() << ",";
	}

	savefile << s6.checkVisited() << ",";
	savefile << s6.getEncounter() << ",";
	savefile << s6.getVine() << ",";
	savefile << s6.getSize()  << ",";
    for(int i = 0; i < s6.getSize(); i++)
	{
		savefile << s6.printItem(i).getId() << ",";
	}


	savefile << s7.checkVisited() << ",";
	savefile << s7.getEncounter() << ",";
	savefile << s7.getCross() << ",";
	savefile << s7.getJump() << ",";
	savefile << s7.getSize()  << ",";
    for(int i = 0; i < s7.getSize(); i++)
	{
		savefile << s7.printItem(i).getId() << ",";
	}

	savefile << s8.checkVisited() << ",";
	savefile << s8.getEncounter() << ",";
	savefile << s8.getSword() << ",";
	savefile << s8.getSize()  << ",";
    for(int i = 0; i < s8.getSize(); i++)
	{
		savefile << s8.printItem(i).getId() << ",";
	}

	savefile << s9.checkVisited() << ",";
	savefile << s9.getEncounter() << ",";
	savefile << s9.getFountian() << ",";
	savefile << s9.getHatch() << ",";
	savefile << s9.getSize()  << ",";
    for(int i = 0; i < s9.getSize(); i++)
	{
		savefile << s9.printItem(i).getId() << ",";
	}

	savefile << s10.checkVisited() << ",";
	savefile << s10.getEncounter() << ",";
	savefile << s10.getSize()  << ",";
    for(int i = 0; i < s10.getSize(); i++)
	{
		savefile << s10.printItem(i).getId() << ",";
	}

	savefile << s11.checkVisited() << ",";
	savefile << s11.getEncounter() << ",";
	savefile << s11.getSize()  << ",";
    for(int i = 0; i < s11.getSize(); i++)
	{
		savefile << s11.printItem(i).getId() << ",";
	}

	savefile << s12.checkVisited() << ",";
	savefile << s12.getEncounter() << ",";
	savefile << s12.getSize()  << ",";
    for(int i = 0; i < s12.getSize(); i++)
	{
		savefile << s12.printItem(i).getId() << ",";
	}

	savefile << s13.checkVisited() << ",";
	savefile << s13.getEncounter() << ",";
	savefile << s13.getFountian() << ",";
	savefile << s13.getGate() << ",";
	savefile << s13.getForge() << ",";
	savefile << s13.getSize()  << ",";
    for(int i = 0; i < s13.getSize(); i++)
	{
		savefile << s13.printItem(i).getId() << ",";
	}

	savefile << s14.checkVisited() << ",";
	savefile << s14.getEncounter() << ",";
	savefile << s14.getCross() << ",";
	savefile << s14.getSize()  << ",";
    for(int i = 0; i < s14.getSize(); i++)
	{
		savefile << s14.printItem(i).getId() << ",";
	}

	savefile << s15.checkVisited() << ",";
	savefile << s15.getEncounter() << ",";
	savefile << s15.getSteel() << ",";
	savefile << s15.getTomb() << ",";
	savefile << s15.getSize()  << ",";
    for(int i = 0; i < s15.getSize(); i++)
	{
		savefile << s15.printItem(i).getId() << ",";
	}

	savefile << s16.checkVisited() << ",";
	savefile << s16.getEncounter() << ",";
	savefile << s16.getSize()  << ",";
    for(int i = 0; i < s16.getSize(); i++)
	{
		savefile << s16.printItem(i).getId() << ",";
	}

	savefile << s17.checkVisited() << ",";
	savefile << s17.getEncounter() << ",";
	savefile << s17.getFountian() << ",";
	savefile << s17.getSize()  << ",";
    for(int i = 0; i < s17.getSize(); i++)
	{
		savefile << s17.printItem(i).getId() << ",";
	}

	savefile << s19.checkVisited() << ",";
	savefile << s19.getEncounter() << ",";
	savefile << s19.getContainerOpen() << ",";
	savefile << s19.getLock1() << ",";
	savefile << s19.getLock2() << ",";
	savefile << s19.getLock3() << ",";
	savefile << s19.getSize()  << ",";
    for(int i = 0; i < s19.getSize(); i++)
	{
		savefile << s19.printItem(i).getId() << ",";
	}

	savefile << s20.checkVisited() << ",";
	savefile << s20.getEncounter() << ",";
	savefile << s20.getFountian() << ",";
	savefile << s20.getSize()  << ",";
    for(int i = 0; i < s20.getSize(); i++)
	{
		savefile << s20.printItem(i).getId() << ",";
	}

	savefile << s21.checkVisited() << ",";
	savefile << s21.getEncounter() << ",";
	savefile << s21.getBoulder() << ",";
	savefile << s21.getSize()  << ",";
    for(int i = 0; i < s21.getSize(); i++)
	{
		savefile << s21.printItem(i).getId() << ",";
	}

	savefile << s22.checkVisited() << ",";
	savefile << s22.getEncounter() << ",";
	savefile << s22.getAnswered() << ",";
	savefile << s22.getCorrect() << ",";
	savefile << s22.getSize()  << ",";
    for(int i = 0; i < s22.getSize(); i++)
	{
		savefile << s22.printItem(i).getId() << ",";
	}

	savefile << s23.checkVisited() << ",";
	savefile << s23.getEncounter() << ",";
	savefile << s23.getFound() << ",";
	savefile << s23.getSize()  << ",";
    for(int i = 0; i < s23.getSize(); i++)
	{
		savefile << s23.printItem(i).getId() << ",";
	}

	savefile << s24.checkVisited() << ",";
	savefile << s24.getEncounter() << ",";
	savefile << s24.getSize()  << ",";
    for(int i = 0; i < s24.getSize(); i++)
	{
		savefile << s24.printItem(i).getId() << ",";
	}

	savefile << s25.checkVisited() << ",";
	savefile << s25.getEncounter() << ",";
	savefile << s25.getFlint() << ",";
	savefile << s25.getSize()  << ",";
    for(int i = 0; i < s25.getSize(); i++)
	{
		savefile << s25.printItem(i).getId() << ",";
	}

	savefile.close();

	cout << "Done" << endl;
}

void Game::load()
{
	ifstream loadfile;
	const char* filename = "SaveGame.txt";
	loadfile.open (filename, ifstream::in);
	int temparray[2];
	int *arraypointer;
	arraypointer = temparray;


	if(loadfile.is_open())
	{
		string temp; //character vars
		int count = 0;
		char chararray[32];
		int number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}

		char1->setName(chararray);

	
		count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		char1->setLevel(number);


		count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		char1->setStrength(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		playerLoc = spaceArr[(number - 1)];

		count = 0;//containers
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		eq.addEquipment(finditem(number));

		
				count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		eq.addEquipment(finditem(number));
		

		count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		int size = number;
		count = 0;
		chararray[0] = 0;
		number;
		ba.clear();
		for(int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;
			number;

			while(loadfile.good())
			{
				temp = (char) loadfile.get();

				if(temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else{
					chararray[count] = temp[0];
					count++;
				}
			}
	
			number = atoi(chararray);
			ba.addToContainer(finditem(number));
			
		}

		count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		size = number;
		count = 0;
		chararray[0] = 0;
		number;
		st.clear();
		for(int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;
			number;

			while(loadfile.good())
			{
				temp = (char) loadfile.get();

				if(temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else{
					chararray[count] = temp[0];
					count++;
				}
			}
	
			number = atoi(chararray);
			st.addToContainer(finditem(number));
			
		}

				count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		size = number;
		count = 0;
		chararray[0] = 0;
		number;
		fg.clear();
		for(int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;
			number;

			while(loadfile.good())
			{
				temp = (char) loadfile.get();

				if(temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else{
					chararray[count] = temp[0];
					count++;
				}
			}
	
			number = atoi(chararray);
			fg.addToContainer(finditem(number));
			
		}

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		fg.setForgeStart(number);

		count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		fg.setUltA(number);
		

		count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		fg.setUltW(number);



		count = 0;//rooms
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		s1.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		
		s1.setEncounter(number);
		

		count = 0;
		chararray[0] = 0;
		number;

		while(loadfile.good())
		{
			temp = (char) loadfile.get();

			if(temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else{
				chararray[count] = temp[0];
				count++;
			}
		}
	
		number = atoi(chararray);
		
		size = number;
		count = 0;
		chararray[0] = 0;
		number;
		s1.clear();
		for(int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while(loadfile.good())
			{
				temp = (char) loadfile.get();

				if(temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else{
					chararray[count] = temp[0];
					count++;
				}
			}
	
			number = atoi(chararray);

			s1.addToContainer(finditem(number));
			
		}
		count = 0;
		chararray[0] = 0;
		number;
		
		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s2.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s2.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s2.setHammer(number);



		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;

		s2.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s2.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;
		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s3.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s3.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s3.setPulled(number);



		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;

		s3.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s3.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;
		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s4.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s4.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s4.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s4.addToContainer(finditem(number));

		}

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s5.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s5.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s5.setSword(number);



		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s5.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s5.addToContainer(finditem(number));

		}

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s6.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s6.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s6.setVine(number);



		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;

		s6.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s6.addToContainer(finditem(number));

		}

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s7.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s7.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s7.setCross(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s7.setJump(number);



		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s7.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s7.addToContainer(finditem(number));

		}

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s8.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s8.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s8.setSword(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s8.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s8.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s9.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s9.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s9.setFountian(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s9.setHatch(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;

		s9.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s9.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s10.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s10.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s10.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s10.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s11.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s11.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s11.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s11.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s12.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s12.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s12.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s12.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s13.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s13.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s13.setFountian(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s13.setGate(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s13.setForge(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s13.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s13.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s14.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s14.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s14.setCross(number);



		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s14.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s14.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s15.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s15.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s15.setSteel(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s15.setTomb(number);





		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s15.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s15.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s16.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s16.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s16.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s16.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s17.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s17.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s17.setFountian(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s17.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s17.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s19.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s19.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s19.setContainerOpen(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s19.setLock1(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s19.setLock2(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s19.setLock3(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s19.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s19.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s20.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s20.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s20.setFountian(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s20.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s20.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s21.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s21.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);

		s21.setBoulder(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s21.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s21.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s22.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s22.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s22.setAnswered(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s22.setCorrect(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;

		s22.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s22.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s23.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s23.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s23.setFound(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s23.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s23.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s24.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s24.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s24.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s24.addToContainer(finditem(number));

		}
		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		s25.setVisited(number);


		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s25.setEncounter(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		
		s25.setFlint(number);

		count = 0;
		chararray[0] = 0;
		number;

		while (loadfile.good())
		{
			temp = (char)loadfile.get();

			if (temp[0] == ',')
			{
				chararray[count] = 0;
				count = 0;
				break;
			}
			else {
				chararray[count] = temp[0];
				count++;
			}
		}

		number = atoi(chararray);
		size = number;
		s25.clear();
		count = 0;
		chararray[0] = 0;
		number;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			chararray[0] = 0;


			while (loadfile.good())
			{
				temp = (char)loadfile.get();

				if (temp[0] == ',')
				{
					chararray[count] = 0;
					count = 0;
					break;
				}
				else {
					chararray[count] = temp[0];
					count++;
				}
			}

			number = atoi(chararray);
			s25.addToContainer(finditem(number));

		}

		loadfile.close();
	}



	
}

Objects Game::finditem(int name)
{
	if(name == 1)
	{
		return Two_Handed_Wooden_Sword();
	}
	else if(name == 2)
	{
		return Two_Handed_Bronze_Sword();
	}
	else if(name == 3)
	{
		return Two_Handed_Silver_Sword();
	}
	else if(name == 4)
	{
		return Two_Handed_Gold_Sword();
	}
	else if(name == 5)
		{
		return Two_Handed_Ultimate_Sword();
	}
	else if(name == 6)
	{
		return Tunic_Armor();
	}
	else if(name == 7)
	{
		return Bronze_Armor();
	}
	else if(name == 8)
	{
		return Silver_Armor();
	}
	else if(name == 9)
	{
		return Gold_Armor();
	}
	else if(name == 10)
	{
		return Ultimate_Armor();
	}
	else if(name == 11)
	{
		return Forge_Hammer();
	}
	else if(name == 12)
	{
		return Flint();
	}
	else if(name == 13)
	{
		return Steel();
	}
	else if(name == 14)
	{
		return  Key();
	}

}


