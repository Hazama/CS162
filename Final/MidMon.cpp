/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: MidMon.cpp file. Allows for the creation of a medium sized monster.
*********************************************************************/

#include "MidMon.hpp"
#include <iostream>
#include <cstdlib>

/*********************************************************************
** Function: MidMon
** Description: Constructor
*********************************************************************/
MidMon::MidMon()
{
	health = 10;
	dead = false;
}

/*********************************************************************
** Function: ~MidMon
** Description: Destructor
*********************************************************************/
MidMon::~MidMon()
{
}

/*********************************************************************
** Function: attack
** Description: Monster attacks if health is above 0. Otherwise returns 0 damage.
*********************************************************************/
int MidMon::attack()
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
