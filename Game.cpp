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

void Game::play()
{
	// Create Space objects
	Space1 s1;
	Space2 s2;
	Space3 s3;
	Space4 s4;
	Space5 s5;
	Space6 s6;
	Space7 s7;
	Space8 s8;
	Space9 s9;
	Space10 s10;
	Space11 s11;
	Space12 s12;
	Space13 s13;
	Space14 s14;
	Space15 s15;
	Space16 s16;
	Space17 s17;
	Space18 s18;
	Space19 s19;
	Space20 s20;
	Space21 s21;
	Space22 s22;
	Space23 s23;
	Space24 s24;
	Space25 s25;

	int turns = 0;

	char choice;
	
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
	while (turns < 25)
	{
		// Clear screen after every iteration
		//cout << string(50, '\n');

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
			cout << "Where do you want to go?" << endl;
			getline(cin, input);
			int res = move(input);
			if (res == -1)
			{
				//cout << "It is forbidden to go there" << endl;

			}
			else
			{
				break;
			}
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


				ba.addToContainer(s3.getObject());
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
			//TEST
			cout << "Equipped" << endl;
			fg.addToContainer(s25.getObject());
			fg.addToContainer(s2.getObject());
			if(fg.startForge())
			{
				cout << "Nice" << endl;
			}
			else
			{
				cout << "Bummer" << endl;
			}
			// Print current equipment 
			eq.printContainer();
			if(s8.getVisited() == false)
			{
				if(s8.getEncounter() == false)
				{
					cout << "A GIANT RAT APPEARED!\n\n" << endl;
					char2 = new Rat();
					fight();
					char2 = NULL;
					// Put wooden sword in bag, equip bronze sword
					transfer(eq.getObject1(), s8.getObject());	
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
			//TEST
			cout << "Space Container" << endl;
			s1.deleteFromContainer(s2.getObject());
			s1.printContainer();
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
