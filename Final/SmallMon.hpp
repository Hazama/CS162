/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: SmallMon.hpp file
*********************************************************************/

#ifndef SMALLMON_HPP
#define SMALLMON_HPP
#include "Monster.hpp"
#include <cstdlib>
class SmallMon :
	public Monster
{
public:
	SmallMon();
	~SmallMon();
	int attack();
};
#endif