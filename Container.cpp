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
	ultSword = new Two_Handed_Ultimate_Sword();
	ultArmor = new Ultimate_Armor();	
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

	if(strcmp((forge[i].getName()).c_str(), "flint") == 0)
	{
		flint = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "steel") == 0)
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
	if(strcmp((forge[i].getName()).c_str(), "wooden sword") == 0)
	{
		wood = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "bronze sword") == 0)
	{
		bronze = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "silver sword") == 0)
	{
		silver = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "gold sword") == 0)
	{
		gold = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "forge hammer") == 0)
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
	if(strcmp((forge[i].getName()).c_str(), "tunic armor") == 0)
	{
		tunic = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "bronze armor") == 0)
	{
		bronze = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "silver armor") == 0)
	{
		silver = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "gold armor") == 0)
	{
		gold = true;
	}
	if(strcmp((forge[i].getName()).c_str(), "forge hammer") == 0)
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

int Forge::getSize()
{
	return forge.size();
}

Objects Forge::getUltSword()
{
	return *ultSword;
}

Objects Forge::getUltArmor()
{
	return *ultArmor;
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

void Equipped::addEquipment(Objects obj)
{
	if(obj.getName().find("sword") != -1)
	{
		equipped[0] = obj;
		setSword(obj);
	}
	else if(obj.getName().find("armor") != -1)
	{
		equipped[1] = obj;
		setArmor(obj);
	}	
}

//test - global string variables to hold weapon and armor names
string sword = "wooden sword";
string armor = "tunic armor";


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
}

string Equipped::getArmor()
{
	return armor;
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




