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
	if (input.find("don't") < 50/*maxInputLength*/ || input.find("Don't") < 50/*maxInputLength*/)
	{
		cout << "Please don't say don't. It confuses me." << endl;
		return -1;
	}
	// end of input validation 
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
			playerLoc = playerLoc->getEast();
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
			playerLoc = playerLoc->getSouth();
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
			playerLoc = playerLoc->getWest();
			return 0;
		}
	}
	else
	{
		cout << "Sorry, I did not understand your input" << endl << endl;
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
	if(obj1.getName().find("Sword") != -1)
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
	else if(obj1.getName().find("Armor") != -1)	
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

void Game::play(bool loadgame)
{
	// Create Space objects

	int turns = 0;

	char choice;
	if (loadgame == true)
	{
		cout <<"shouldnt get here";
		load();
	}
	
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
	cout << "You impact with a CRACK. Your consciousness fades to the ether." << endl;
    cin.ignore();

	// Randomize the game
	srand(time(NULL));
	while (turns < 50)
	{
		// Clear screen after every iteration
		//cout << string(50, '\n');

		save();
		//cout << endl;
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
			getline(cin, input);
			int res = move(input);
			//if (res == -1)
			//{
				//cout << "It is forbidden to go there" << endl;

			//}
			//else
			//{
			if(playerLoc == spaceArr[0])
			{
				if(input.find("grass") < 50)
				{
					if(input.find("look") < 50)
					{	
						cout << "You look at the grass." << endl;
					}
					else if(input.find("attack") < 50)
					{
						cout << "You attack the grass" << endl;
					}
					else
					{
						cout << "You can't do that to grass." << endl;
					}
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

		cout << "-------------------------------------------------------------------------------------------\n\n" << endl;

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
			}
			else
			{
				cout << s1.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[1])
		{
			if(s2.getVisited() == false)
			{
				cout << s2.getLongForm() << endl;
				// Pick up Forge Hammer
				ba.addToContainer(s2.getObject());
				cout << "Equipped" << endl;
				eq.printContainer();
				cout << "Bag" << endl;
				ba.printContainer();	
			}
			else
			{
				cout << s2.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[2])
		{
			if(s3.getVisited() == false)
			{
				cout << s3.getLongForm() << endl;
				// Pick up Bronze Armor
				ba.addToContainer(s3.getObject());
				// Equip Bronze Armor
				transfer(eq.getObject2(), s3.getObject());
	
				cout << "Equipped" << endl;
				eq.printContainer();
				cout << "Bag" << endl;
				ba.printContainer();	
			}
			else
			{
				cout << s3.getShortForm() << endl;
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
			}
			else
			{
				cout << s4.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[4])
		{
			if(s5.getVisited() == false)
			{
				cout << s5.getLongForm() << endl;
			
				// Pick up Silver Sword
				ba.addToContainer(s5.getObject());
				// Equip Silver Sword
				transfer(s8.getObject(), s5.getObject());

				cout << "Equipped" << endl;
				eq.printContainer();
				cout << "Bag" << endl;
				ba.printContainer();
			}
			else
			{
				cout << s5.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[5])
		{
			if(s6.getVisited() == false)
			{
				
				cout << s6.getLongForm() << endl;

				// Pick up Silver Armor
				ba.addToContainer(s6.getObject());
				// Equip Silver Armor
				transfer(s3.getObject(), s6.getObject());
				cout << "Equipped" << endl;
				eq.printContainer();
				cout << "Bag" << endl;
				ba.printContainer();

			}
			else
			{
				cout << s6.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[6])
		{
			if(s7.getVisited() == false)
			{
				cout << s7.getLongForm() << endl;
			}
			else
			{
				cout << s7.getShortForm() << endl;
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
					// Put wooden sword in bag, equip bronze sword
					transfer(eq.getObject1(), fg.getUltSword());	
					// Print equipped
					cout << "Equipped" << endl;
					eq.printContainer();
					// Print Bag
					cout << "Bag" << endl;
					ba.printContainer();
				}
				cout << s8.getLongForm() << endl;
			}
			else
			{
				cout << s8.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[8])
		{
			if(s9.getVisited() == false)
			{
				cout << s9.getLongForm() << endl;
				cout << "HEALING" << endl;
				char1->setHealth(16);
				cout << "Hero Health after healing: " << char1->getHealth() << endl;	
			}
			else
			{
				cout << s9.getShortForm() << endl;
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
			}
			else
			{
				cout << s10.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[10])
		{
			if(s11.getVisited() == false)
			{
				cout << s11.getLongForm() << endl;
			}
			else
			{
				cout << s11.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[11])
		{
			if(s12.getVisited() == false)
			{
				cout << s12.getLongForm() << endl;
			}
			else
			{
				cout << s12.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[12])
		{

			if(s13.getVisited() == false)
			{
				cout << s13.getLongForm() << endl;
			}
			else
			{
				cout << s13.getShortForm() << endl;
			}	
		}
		else if (playerLoc == spaceArr[13])
		{
			if(s14.getVisited() == false)
			{
				cout << s14.getLongForm() << endl;
			}
			else
			{
				cout << s14.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[14])
		{
			if(s15.getVisited() == false)
			{
				cout << s15.getLongForm() << endl;
				// Place Steel in Bag
				ba.addToContainer(s15.getObject());
				cout << "Equipped" << endl;
				eq.printContainer();
				// Print Bag
				cout << "Bag" << endl;
				ba.printContainer();
				
			}
			else
			{
				cout << s15.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[15])
		{
			if(s16.getVisited() == false)
			{
				cout << s16.getLongForm() << endl;
			}
			else
			{
				cout << s16.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[16])
		{
			if(s17.getVisited() == false)
			{
				cout << s17.getLongForm() << endl;
				cout << "HEALING" << endl;
				char1->setHealth(18);
				cout << "Hero Health after healing: " << char1->getHealth() << endl;	
			}
			else
			{
				cout << s17.getShortForm() << endl;
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
			}
			else
			{
				cout << s19.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[19])
		{
			if(s20.getVisited() == false)
			{
				cout << s20.getLongForm() << endl;
				cout << "HEALING" << endl;
				char1->setHealth(26);
				cout << "Hero Health after healing: " << char1->getHealth() << endl;	
				cout << "TELEPORTING BACK TO SANCTUARY" << endl;
				playerLoc = spaceArr[12];
			}
			else
			{
				cout << s20.getShortForm() << endl;
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
				
					// Pick up Gold Sword
					ba.addToContainer(s21.getObject());
					// Equipped Gold Sword
					transfer(s5.getObject(), s21.getObject());	
					cout << "Equipped" << endl;
					eq.printContainer();
					// Print Bag
					cout << "Bag" << endl;
					ba.printContainer();
	
				}

				cout << s21.getLongForm() << endl;
			}
			else
			{
				cout << s21.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[21])
		{
			if(s22.getVisited() == false)
			{
				cout << s22.getLongForm() << endl;
			}
			else
			{
				cout << s22.getShortForm() << endl;
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

					// Pick up Gold Armor
					ba.addToContainer(s23.getObject());
					// Equip Gold Armor
					transfer(s6.getObject(), s23.getObject());

					cout << "Equipped" << endl;
					eq.printContainer();
					// Print Bag
					cout << "Bag" << endl;
					ba.printContainer();
				}
				cout << s23.getLongForm() << endl;
			}
			else
			{
				cout << s23.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[23])
		{
			if(s24.getVisited() == false)
			{
				// WRONG LOCATION FOR LESSER DRAKE - ONLY FOR TESTING
				if(s24.getEncounter() == false)
				{
					cout << "A LESSER DRAKE APPEARED!\n\n" << endl;
					char2 = new Lesser_Drake();
					fight();
					char2 = NULL;
				}
				cout << s24.getLongForm() << endl;
			}
			else
			{
				cout << s24.getShortForm() << endl;
			}
		}
		else if (playerLoc == spaceArr[24])
		{
			if(s25.getVisited() == false)
			{
				cout << s25.getLongForm() << endl;
			}
			else
			{
				cout << s25.getShortForm() << endl;
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

	savefile << char1->getName() << ",";
	savefile << char1->getLevel() << ",";
	savefile << char1->getStrength() << ",";

	savefile << playerLoc->getId() << ",";

	savefile << eq.getObject1().getId() << ",";
	savefile << eq.getObject2().getId() << ",";

	savefile << ba.getSize()  << ",";
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
	
	
	savefile << s1.checkVisited() << ",";
	savefile << s1.getEncounter() << ",";
	savefile << s1.getSize()  << ",";
    for(int i = 0; i < s1.getSize(); i++)
	{
		savefile << (s1.printItem(i)).getId() << ",";
	}
	

	savefile << s2.checkVisited() << ",";
	savefile << s2.getEncounter() << ",";
	savefile << s2.getSize()  << ",";
    for(int i = 0; i < s2.getSize(); i++)
	{
		savefile << s2.printItem(i).getId() << ",";
	}
	savefile << s3.checkVisited() << ",";
	savefile << s3.getEncounter() << ",";
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
	savefile << s5.getSize()  << ",";
    for(int i = 0; i < s5.getSize(); i++)
	{
		savefile << s5.printItem(i).getId() << ",";
	}

	savefile << s6.checkVisited() << ",";
	savefile << s6.getEncounter() << ",";
	savefile << s6.getSize()  << ",";
    for(int i = 0; i < s6.getSize(); i++)
	{
		savefile << s6.printItem(i).getId() << ",";
	}


	savefile << s7.checkVisited() << ",";
	savefile << s7.getEncounter() << ",";
	savefile << s7.getSize()  << ",";
    for(int i = 0; i < s7.getSize(); i++)
	{
		savefile << s7.printItem(i).getId() << ",";
	}

	savefile << s8.checkVisited() << ",";
	savefile << s8.getEncounter() << ",";
	savefile << s8.getSize()  << ",";
    for(int i = 0; i < s8.getSize(); i++)
	{
		savefile << s8.printItem(i).getId() << ",";
	}

	savefile << s9.checkVisited() << ",";
	savefile << s9.getEncounter() << ",";
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
	savefile << s13.getSize()  << ",";
    for(int i = 0; i < s13.getSize(); i++)
	{
		savefile << s13.printItem(i).getId() << ",";
	}

	savefile << s14.checkVisited() << ",";
	savefile << s14.getEncounter() << ",";
	savefile << s14.getSize()  << ",";
    for(int i = 0; i < s14.getSize(); i++)
	{
		savefile << s14.printItem(i).getId() << ",";
	}

	savefile << s15.checkVisited() << ",";
	savefile << s15.getEncounter() << ",";
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
	savefile << s17.getSize()  << ",";
    for(int i = 0; i < s17.getSize(); i++)
	{
		savefile << s17.printItem(i).getId() << ",";
	}

	savefile << s19.checkVisited() << ",";
	savefile << s19.getEncounter() << ",";
	savefile << s19.getSize()  << ",";
    for(int i = 0; i < s19.getSize(); i++)
	{
		savefile << s19.printItem(i).getId() << ",";
	}

	savefile << s20.checkVisited() << ",";
	savefile << s20.getEncounter() << ",";
	savefile << s20.getSize()  << ",";
    for(int i = 0; i < s20.getSize(); i++)
	{
		savefile << s20.printItem(i).getId() << ",";
	}

	savefile << s21.checkVisited() << ",";
	savefile << s21.getEncounter() << ",";
	savefile << s21.getSize()  << ",";
    for(int i = 0; i < s21.getSize(); i++)
	{
		savefile << s21.printItem(i).getId() << ",";
	}

	savefile << s22.checkVisited() << ",";
	savefile << s22.getEncounter() << ",";
	savefile << s22.getSize()  << ",";
    for(int i = 0; i < s22.getSize(); i++)
	{
		savefile << s22.printItem(i).getId() << ",";
	}

	savefile << s23.checkVisited() << ",";
	savefile << s23.getEncounter() << ",";
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
		string temp;
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
		cout << number;
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
		cout << number;
		size = number;
		
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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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
		size = number;

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

int intlength(int num)
{
	int count = 0;
	while(num)
	{
		num = num / 10;
		count++;
	}
	return count;
}

int* Game::LoadInt(const char *filename, int filepos)
{
	ifstream loadfile;
	int *tempp;
	int temparray[2];
	tempp = temparray;
	loadfile.open (filename, ifstream::in);
	loadfile.seekg(filepos);

	string temp;
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
	
	number = atoi(chararray);
	temparray[0] = number;
	temparray[1] = loadfile.tellg();
	return tempp;
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
