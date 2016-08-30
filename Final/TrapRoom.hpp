/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: TrapRoom.hpp file
*********************************************************************/

#ifndef TRAP_HPP
#define TRAP_HPP
#include "Room.hpp"
#include "BigMon.hpp"
#include <cstdlib>
class TrapRoom :
	public Room
{
protected:
	bool battleDone;
	BigMon b1;
public:
	TrapRoom();
	~TrapRoom();
	void battleScene();
	direction scene();
	void sceneText();
};
#endif