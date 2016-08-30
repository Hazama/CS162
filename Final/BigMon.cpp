/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: BigMon.cpp. Allows for the creation of a large monster.
*********************************************************************/

#include "BigMon.hpp"
#include <iostream>
#include <cstdlib>

/*********************************************************************
** Function: BigMon
** Description: Constructor
*********************************************************************/
BigMon::BigMon()
{
	health = 15;
	dead = false;
}

/*********************************************************************
** Function: ~BigMon
** Description: Destructor
*********************************************************************/
BigMon::~BigMon()
{
}

/*********************************************************************
** Function: attack
** Description: Monster attacks if health is above 0. Otherwise returns 0 damage.
*********************************************************************/
int BigMon::attack()
{
	if (health > 0)
	{
		std::cout << "The monster attacks" << std::endl;
		return rand() % 3 + 3; //3-5 damage 
	}

	else
	{
		std::cout << "The monster is dead" << std::endl;
		return 0;
	}
}
