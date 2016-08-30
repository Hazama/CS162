/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: BigMon.hpp file
*********************************************************************/

#ifndef BIGMON_HPP
#define BIGMON_HPP
#include "Monster.hpp"
#include <cstdlib>
class BigMon :
	public Monster
{
public:
	BigMon();
	~BigMon();
	int attack();
};
#endif