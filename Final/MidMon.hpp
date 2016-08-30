/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: MidMon.hpp file
*********************************************************************/

#ifndef MIDMON_HPP
#define MIDMON_HPP
#include "Monster.hpp"
#include <cstdlib>
class MidMon :
	public Monster
{
public:
	MidMon();
	~MidMon();
	int attack();
};
#endif
