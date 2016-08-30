/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: BossMon.cpp file. Allows for the creation of a boss monster.
*********************************************************************/

#include "BossMon.hpp"
#include <iostream>

/*********************************************************************
** Function: BossMon
** Description: Constructor
*********************************************************************/
BossMon::BossMon()
{
	dead = false;
	health = 20;
}

/*********************************************************************
** Function: ~BossMon
** Description: Destructor
*********************************************************************/
BossMon::~BossMon()
{
}

/*********************************************************************
** Function: attack
** Description: Monster attacks if health is above 0. Otherwise returns 0 damage.
*********************************************************************/
int BossMon::attack()
{
	std::cout << "A burst of fire surges towards you" << std::endl;
	return 8; //8 damage 
}
