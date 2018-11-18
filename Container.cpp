/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: All containers used throughout the game
*/

#include "Container.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Objects
Bag b;
Forge f;
Stash s;
Equipped e;
// Constructor
Container::Container()
{}
// Destructor
Container::~Container()
{}

void Container::addToContainer(Objects obj)
{
	tester.push_back(obj);
}

void Container::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < tester.size(); i++)
	{
		if(tester[i].getName() == obj.getName())
		{
			tester.erase(tester.begin() + i);
			return;
		}
	}

}

void Container::printContainer()
{
	for (int i = 0; i < tester.size(); i++)
	{
		cout << tester[i].getName() << endl;
	}
}
 
// Bag**********************************************************************
Bag::Bag()
{}

Bag::~Bag()
{
	bag.clear();
}

void Bag::addToContainer(Objects obj)
{
	bag.push_back(obj);
}

void Bag::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < bag.size(); i++)
	{
		if(bag[i].getName() == obj.getName())
		{
			bag.erase(bag.begin() + i);
			return;
		}
	}
}

void Bag::printContainer()
{
	for (int i = 0; i < bag.size(); i++)
	{
		cout << bag[i].getName() << endl;
	}
}

string Bag::printItem(int i)
{
	
		return bag[i].getName();

}

void Bag::transferToForge(Objects obj)
{
	// Add object to forge
	f.addToContainer(obj);
	// Delete objct from bag
	b.deleteFromContainer(obj);
}

void Bag::transferToStash(Objects obj)
{
	// Add object to stash
	s.addToContainer(obj);
	// Delete object from bag
	b.deleteFromContainer(obj);
}

void Bag::transferToEquipped(Objects obj1, Objects obj2)
{
	// Object 1 is in equipped, Object 2 is in bag

	// Transferring two objects at once
	// If the object is a sword
	if(obj1.getName().find("Sword") != -1)
	{
		// Add Sword to Bag
		b.addToContainer(obj1);

		// Delete Sword from equipped
		e.deleteFromContainer(obj1);

		// Add New Sword to Equipped - position 0
		e.insert(0, obj2);

		// Delete new sword from bag
		b.deleteFromContainer(obj2);
	}
	//If the object is armor
	else if(obj1.getName().find("Armor") != -1)	
	{
		// Add Armor to bag
		b.addToContainer(obj1);
		// Delete Armor from equipped
		e.deleteFromContainer(obj1);

		// Add New Armor to Equipped - position 1
		e.insert(1, obj2);

		// Delete new armor from bag
		b.deleteFromContainer(obj2);
	}
}

int Bag::getSize()
{
	return bag.size();
}

// Forge*******************************************************************
Forge::Forge()
{
	forgeStart = false;
	craftUltWeapon = false;
	craftUltArmor = false;	
}

Forge::~Forge()
{
	forge.clear();
}

void Forge::addToContainer(Objects obj)
{
	forge.push_back(obj);
}

void Forge::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < forge.size(); i++)
	{
		if(forge[i].getName() == obj.getName())
		{
			forge.erase(forge.begin() + i);
			return;
		}
	}
}

void Forge::printContainer()
{
	for (int i = 0; i < forge.size(); i++)
	{
		cout << forge[i].getName() << endl;
	}
}

string Forge::printItem(int i)
{
	
		return forge[i].getName();

}

bool Forge::getForgeStart()
{
	return forgeStart;
}

bool Forge::startForge()
{

	if(forge.size() < 2)
	{
		return false;
	}

	else if(forge[0].getName() == "Flint" || forge[0].getName() == "Steel" && forge[1].getName() == "Flint" || forge[1].getName() == "Steel")
	{
		forgeStart = true;
		cout << "The beacon is lit!" << endl;
		return true;
	}
	else
	{
		return false;
	}	
}

bool Forge::ultWeaponCrafted()
{
	if(forge.size() < 5)
	{
		return false;
	}	
	else if(getForgeStart() == true && forge[0].getName() == "Two-Handed Wooden Sword" || forge[0].getName() == "Two-handed Bronze Sword" || forge[0].getName() == "Two-handed Silver Sword" || forge[0].getName() == "Two-Handed Gold Sword" || forge[0].getName() == "Forge Hammer" && forge[1].getName() == "Two-Handed Wooden Sword" || forge[1].getName() == "Two-handed Bronze Sword" || forge[1].getName() == "Two-handed Silver Sword" || forge[1].getName() == "Two-Handed Gold Sword" || forge[1].getName() == "Forge Hammer" && forge[2].getName() == "Two-Handed Wooden Sword" || forge[2].getName() == "Two-handed Bronze Sword" || forge[2].getName() == "Two-handed Silver Sword" || forge[2].getName() == "Two-Handed Gold Sword" || forge[2].getName() == "Forge Hammer" && forge[3].getName() == "Two-Handed Wooden Sword" || forge[3].getName() == "Two-handed Bronze Sword" || forge[3].getName() == "Two-handed Silver Sword" || forge[3].getName() == "Two-Handed Gold Sword" || forge[3].getName() == "Forge Hammer" && forge[4].getName() == "Two-Handed Wooden Sword" || forge[4].getName() == "Two-Handed Bronze Sword" || forge[4].getName() == "Two-Handed Silver Sword" || forge[4].getName() == "Two-Handed Gold Sword" || forge[4].getName() == "Forge Hammer")
		if(forge.size() < 3)
	{
		return false;
	}
	else
	{
		return false;
	}
}

bool Forge::ultArmorCrafted()
{
	if(forge.size() < 5)
	{
		return false;
	}		
	// Hardcoded check if all items are in the forge
	else if(getForgeStart() == true && forge[0].getName() == "Tunic Armor" || forge[0].getName() == "Bronze Armor" || forge[0].getName() == "Silver Armor" || forge[0].getName() == "Gold Armor" || forge[0].getName() == "Forge Hammer" && forge[1].getName() == "Tunic Armor" || forge[1].getName() == "Bronze Armor" || forge[1].getName() == "Silver Armor" || forge[1].getName() == "Gold Armor" || forge[1].getName() == "Forge Hammer" && forge[2].getName() == "Tunic Armor" || forge[2].getName() == "Bronze Armor" || forge[2].getName() == "Silver Armor" || forge[2].getName() == "Gold Armor" || forge[2].getName() == "Forge Hammer" && forge[3].getName() == "Tunic Armor" || forge[3].getName() == "Bronze Armor" || forge[3].getName() == "Silver Armor" || forge[3].getName() == "Gold Armor" || forge[3].getName() == "Forge Hammer" && forge[4].getName() == "Tunic Armor" || forge[4].getName() == "Bronze Armor" || forge[4].getName() == "Silver Armor" || forge[4].getName() == "Gold Armor" || forge[4].getName() == "Forge Hammer")
	{
		craftUltArmor = true;
		return true;
	}
	else
	{
		return false;
	}
}

void Forge::transferToBag(Objects obj)
{	
	// Add object to bag
	b.addToContainer(obj);
	// Delete object from forge
	f.deleteFromContainer(obj);	
}

int Forge::getSize()
{
	return forge.size();
}

// Stash*******************************************************************
Stash::Stash()
{}

Stash::~Stash()
{
	stash.clear();
}

void Stash::addToContainer(Objects obj)
{
	stash.push_back(obj);
}

void Stash::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < stash.size(); i++)
	{
		if(stash[i].getName() == obj.getName())
		{
			stash.erase(stash.begin() + i);
			return;
		}
	}
}

void Stash::printContainer()
{
	for (int i = 0; i < stash.size(); i++)
	{
		cout << stash[i].getName() << endl;
	}
	
}

string Stash::printItem(int i)
{
	
		return stash[i].getName();

}

void Stash::transferToBag(Objects obj)
{
	// Add object to bag
	b.addToContainer(obj);
	// Delete object from stash
	s.deleteFromContainer(obj);
}
int Stash::getSize()
{
	return stash.size();
}

// Equipped******************************************************************
Equipped::Equipped()
{

	// Create starting objects
	obj1 = new Two_Handed_Wooden_Sword();
	obj2 = new Tunic_Armor();
	equipped.push_back(*obj1);
	equipped.push_back(*obj2);		
		
}

Equipped::~Equipped()
{
	if(obj1)
	{
		delete obj1;
	}
	if(obj2)
	{
		delete obj2;
	}

	equipped.clear();

}

void Equipped::addToContainer(Objects obj)
{
	equipped.push_back(obj);
}



void Equipped::addEquipment(Objects obj)
{
	if(obj.getName().find("Sword") != -1)
	{
		equipped.insert(equipped.begin() + 0, obj);
	}
	else if(obj.getName().find("Armor") != -1)
	{
		equipped.insert(equipped.begin() + 1, obj);
	}	
}	

void Equipped::deleteFromContainer(Objects obj)
{
	for(int i = 0; i < equipped.size(); i++)
	{
		if(equipped[i].getName() == obj.getName())
		{
			equipped.erase(equipped.begin() + i);
			return;
		}
	}

}

void Equipped::printContainer()
{
	for (int i = 0; i < equipped.size(); i++)
	{
		cout << equipped[i].getName() << endl;
	}

}

void Equipped::transferToBag(Objects obj1, Objects obj2)
{
	// Object 1 is in bag, Object 2 is in equipped

	// Transferring two objects at once
	// If the object is a sword
	if(obj2.getName().find("Sword") != -1)
	{
		// Add Sword to Bag
		b.addToContainer(obj2);

		// Delete Sword from equipped
		e.deleteFromContainer(obj2);
		cout << "Inserting new sword" << endl;	
		cout << "Object 1: " << obj1.getName() << endl;
		cout << "Object 2: " << obj2.getName() << endl;
		// Add New Sword to Equipped - position 0
		e.insert(0, obj1);

		// Delete new sword from bag
		b.deleteFromContainer(obj1);
	}
	//If the object is armor
	else if(obj1.getName().find("Armor") != -1)	
	{
		// Add Armor to bag
		b.addToContainer(obj2);
		// Delete Armor from equipped
		e.deleteFromContainer(obj2);

		// Add New Armor to Equipped - position 1
		e.insert(1, obj1);

		// Delete new armor from bag
		b.deleteFromContainer(obj1);
	}
}
//TEST - global string variables to hold weapon and armor names
string sword = "Two-Handed Wooden Sword";
string armor = "Tunic Armor";


void Equipped::setSword(Objects obj)
{
	sword = obj.getName();
}

void Equipped::setArmor(Objects obj)
{
	armor = obj.getName();
}	

string Equipped::getSword()
{

	return sword;

	//return equipped[0].getName();
}

string Equipped::getArmor()
{
	return armor;

	//return equipped[1].getName();
}

void Equipped::insert(int i, Objects obj)
{
	equipped.insert(equipped.begin() + i, obj);
}

Objects Equipped::getObject1()
{
	return *obj1;
}

Objects Equipped::getObject2()
{
	return *obj2;
}




