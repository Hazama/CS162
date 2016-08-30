/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: StartRoom.hpp file
*********************************************************************/

#ifndef START_HPP
#define START_HPP
#include "Room.hpp"
#include <cstdlib>
class StartRoom :
	public Room
{
protected:
	bool premEnd;
public:
	StartRoom();
	~StartRoom();
	direction scene();
	void sceneText();
	bool getpremEnd();
};
#endif