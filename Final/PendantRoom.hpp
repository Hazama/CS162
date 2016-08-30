/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: PendantRoom.hpp file
*********************************************************************/

#ifndef PENDANTROOM_HPP
#define PENDANTROOM_HPP
#include "Room.hpp"
#include <cstdlib>
class PendantRoom :
	public Room
{
protected:
	bool pendant;
public:
	PendantRoom();
	~PendantRoom();
	direction scene();
	void sceneText();
};
#endif