/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: Monster.cpp file. Monster base class. All monsters inherit from this.
*********************************************************************/

#include "Monster.hpp"
#include <iostream>

/*********************************************************************
** Function: Monster
** Description: Constructor
*********************************************************************/
Monster::Monster()
{
}

/*********************************************************************
** Function: ~Monster
** Description: Detructor
*********************************************************************/
Monster::~Monster()
{
}

/*********************************************************************
** Function: attack
** Description: inherited function
*********************************************************************/
int Monster::attack()
{
	return 0;
}

/*********************************************************************
** Function: setHealth
** Description: sets health to i. Updates death status if monster's health dips to 0 or below.
** Paramters: An integer representing the new health
*********************************************************************/
void Monster::setHealth(int i)
{
	health = i;
	
	if (health <= 0)
	{
		dead = true;
		//std::cout << "You defeated the monster" << std::endl;
	}
}
/*********************************************************************
** Function: calcDamage
** Description: Calculates the new health of a monster and passes it to setHealth
** Parameters: An integer representing the damage taken
*********************************************************************/
void Monster::calcDamage(int i)
{
	int newHP = health - i;

	setHealth(newHP);
}

bool Monster::getDead()
{
	return dead;
}
