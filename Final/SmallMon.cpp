/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: SmallMon.cpp file. Makes a small monster.
*********************************************************************/

#include "SmallMon.hpp"
#include <cstdlib>
#include <iostream>

/*********************************************************************
** Function: SmallMon
** Description: Constructor
*********************************************************************/
SmallMon::SmallMon()
{
	health = 5;
	dead = false;
}

/*********************************************************************
** Function: SmallMon
** Description: Destructor
*********************************************************************/
SmallMon::~SmallMon()
{
}

/*********************************************************************
** Function: attack
** Description: Monster attacks if health is above 0. Otherwise returns 0 damage.
*********************************************************************/
int SmallMon::attack()
{
	if (health > 0)
	{
		std::cout << "The monster attacks" << std::endl;
		return rand() % 2 + 2; //2-3 damage 
	}

	else
	{
		std::cout << "The monster is dead" << std::endl;
		return 0;
	}
}
