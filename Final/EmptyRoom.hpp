/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: EmptyRoom.hpp file
*********************************************************************/

#ifndef EMPTY_HPP
#define EMPTY_HPP
#include "Room.hpp"
#include <cstdlib>
class EmptyRoom :
	public Room
{
public:
	EmptyRoom();
	~EmptyRoom();
	void sceneText();
	direction scene();
	void printArt();
};
#endif