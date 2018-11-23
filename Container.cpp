/* Program Name: Sword Quest
Author: Centaurus Team 1
Date: October 9, 2018
Description: All containers used throughout the game
*/

#include "Container.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

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

Objects Bag::printItem(int i)
{
	
		return bag[i];

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

Objects Forge::printItem(int i)
{
	
		return forge[i];

}

bool Forge::getForgeStart()
{
	return forgeStart;
}

bool Forge::startForge()
{
	bool flint = false;
	bool steel = false;
	
	for(int i = 0; i < forge.size(); i ++)
{

	if(strcmp((forge[i].getName()).c_str(), "Flint") == 0)
	{
		flint = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Steel") == 0)
	{
		steel = true;
	}
}
	if(flint == true && steel == true)
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
	bool wood = false;
	bool bronze = false;
	bool silver = false;
	bool gold = false;
	bool hammer = false;

		for(int i = 0; i < forge.size(); i ++)
{
	if(strcmp((forge[i].getName()).c_str(), "Two-Handed Wooden Sword") == 0)
	{
		wood = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Two-Handed Bronze Sword") == 0)
	{
		bronze = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Two-Handed Silver Sword") == 0)
	{
		silver = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Two-Handed Gold Sword") == 0)
	{
		gold = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Forge Hammer") == 0)
	{
		hammer = true;
	}		
}
	if(wood == true && bronze == true && silver == true && gold == true && hammer == true)
	{
		craftUltWeapon = true;
		return true;	
	} 
	else
	{
		return false;
	}
}

bool Forge::ultArmorCrafted()
{

	bool tunic = false;
	bool bronze = false;
	bool silver = false;
	bool gold = false;
	bool hammer = false;

	for(int i = 0; i < forge.size(); i++)
{
	if(strcmp((forge[i].getName()).c_str(), "Tunic Armor") == 0)
	{
		tunic = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Bronze Armor") == 0)
	{
		bronze = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Silver Armor") == 0)
	{
		silver = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Gold Armor") == 0)
	{
		gold = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "Forge Hammer") == 0)
	{
		hammer = true;
	}		
}
	if(tunic == true && bronze == true && silver == true && gold == true && hammer == true)
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

Objects Stash::printItem(int i)
{
	
		return stash[i];

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
		equipped[0] = obj;
		setSword(obj);
	}
	else if(obj.getName().find("Armor") != -1)
	{
		equipped[1] = obj;
		setArmor(obj);
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
	return equipped[0];
}

Objects Equipped::getObject2()
{
	return equipped[1];
}




