/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: Player.cpp file. Allows for the creation of a Player to navigate the dungeon.
*********************************************************************/

#include "Player.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*********************************************************************
** Function: Player
** Description: Constructor. Sets default values.
*********************************************************************/
Player::Player()
{
	health = 30;
	finSword = false;
	pendant = false; 
	arrNum = 0;
	addItem("rustySword");
	dead = false;
}

/*********************************************************************
** Function: ~Player
** Description: Destructor
*********************************************************************/
Player::~Player()
{
}

/*********************************************************************
** Function: attack
** Description: Returns damage based on what weapon the user has equipped
*********************************************************************/
int Player::attack()
{
	if (finSword == true)
	{
		int damage = rand() % 3 + 6; //6-8 damage
		cout << "You deal " << damage << " damage!" << endl;
		return damage;
	}

	int damage = rand() % 2 + 3; //3-4 damage
	cout << "You deal " << damage << " damage!" << endl;
	return damage;
}

/*********************************************************************
** Function: useItem
** Description: Allows user to use items
** Parameters: a string
*********************************************************************/
void Player::useItem(std::string s)
{
	if (s == "lifeWater")
	{
		cout << "You drink the water of life. Health restored to full" << endl;
		health = 30; //restore health
		removeItem("lifeWater"); //item consumed
	} 

	else if (s == "rustySword")
	{
		cout << "You equip the rusty sword" << endl;
		finSword = false; 
	}

	else if (s == "magicSword")
	{
		cout << "You equip the magic sword" << endl;
		finSword = true; 
	}

	else if (s == "pendant")
	{
		cout << "The pendant does nothing. Except unlock the dragon's lair." << endl;
	}

	else
	{
		cout << "That item doesn't appear to be in your inventory. Maybe you're thinking of another game." << endl;
	}
}

/*********************************************************************
** Function: addItem
** Description: Adds an item to the inventory
** Parameter: A string
*********************************************************************/
void Player::addItem(std::string s)
{
	arr[arrNum] = s;
	arrNum++;
}

/*********************************************************************
** Function: removeItem
** Description: removes item from inventory
** Parameter: A string
*********************************************************************/
void Player::removeItem(std::string s)
{
	for (int i = 0; i < arrNum; i++)
	{
		if (s == arr[i])
		{
			int j = i;

			for (j; j < arrNum - 1; j++)
			{
				arr[j] = arr[j + 1]; //remove item by shifting over subsequent elements down 1 spot
			}

			arrNum -= 1; 
		}
	}
}

void Player::setHealth(int n)
{
	health = n;

	if (health <= 0)
	{
		//cout << "You have died" << endl;
		dead = true;
	}
}

int Player::getHealth()
{
	return health;
}

bool Player::getPendant()
{
	return pendant;
}

void Player::setPendant(bool b)
{
	pendant = b;
}

void Player::setSword(bool b)
{
	finSword = b;
}

bool Player::getSword()
{
	return finSword;
}

/*********************************************************************
** Function: dispayInv
** Description: Allows user to see inventory, and prompts them to use an item or type cancel.
*********************************************************************/
void Player::displayInv()
{
	cout << "Inventory: " << endl; 

	for (int i = 0; i < getarrNum(); i++)
	{
		cout << arr[i] << endl; 
	}

	std::string userInput;

	cout << "Type the name of the item you wish to use. Or type \"cancel\" to exit the inventory" << endl;

	std::cin >> userInput;

	if (userInput != "cancel")
	{
		useItem(userInput);
	}


}

int Player::getarrNum()
{
	return arrNum;
}

/*********************************************************************
** Function: calcDamage
** Description: Calculates new health
** Parameters: An integer, representing damage taken
*********************************************************************/
void Player::calcDamage(int i)
{
	int x = health - i;
	setHealth(x);
}

bool Player::getDead()
{
	return dead;
}
