/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: BossMon.hpp file
*********************************************************************/

#ifndef BOSS_HPP
#define BOSS_HPP
#include "Monster.hpp"
#include <cstdlib>
class BossMon :
	public Monster
{
public:
	BossMon();
	~BossMon();
	int attack();
};
#endif