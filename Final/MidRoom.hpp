/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: MidRoom.hpp file
*********************************************************************/

#ifndef MIDROOM_HPP
#define MIDROOM_HPP
#include "Room.hpp"
#include "MidMon.hpp"
#include <cstdlib>
class MidRoom :
	public Room
{
protected:
	bool battleDone;
	bool run;
	MidMon m1;
public:
	MidRoom();
	~MidRoom();
	void battleScene();
	direction scene();
	void sceneText();
};
#endif
