/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: waterRoom.hpp file
*********************************************************************/

#ifndef WATER_HPP
#define WATER_HPP
#include "Room.hpp"
#include <cstdlib>
class waterRoom :
	public Room
{
protected:
	bool water;
public:
	waterRoom();
	~waterRoom();
	direction scene();
	void sceneText(); 
};
#endif