/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: SwordRoom.hpp file
*********************************************************************/

#ifndef SWORD_HPP
#define SWORD_HPP
#include "Room.hpp"
#include <cstdlib>
class SwordRoom :
	public Room
{
protected:
	bool sword;
public:
	SwordRoom();
	~SwordRoom();
	direction scene();
	void sceneText();
};
#endif