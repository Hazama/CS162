/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: WeakRoom.hpp file
*********************************************************************/

#ifndef WEAKROOM_HPP
#define WEAKROOM_HPP
#include "Room.hpp"
#include "SmallMon.hpp"
#include <cstdlib>
class WeakRoom :
	public Room
{
protected:
	bool battleDone;
	bool run;
	SmallMon s1;
public:
	WeakRoom();
	~WeakRoom();
	void battleScene();
	direction scene();
	void sceneText();
};
#endif