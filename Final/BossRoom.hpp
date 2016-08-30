/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: BossRoom.hpp file
*********************************************************************/

#ifndef BOSSROOM_HPP
#define BOSSROOM_HPP
#include "Room.hpp"
#include "BossMon.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
class BossRoom :
	public Room
{
private:
	bool bossDead;
	BossMon boss;
public:
	BossRoom();
	~BossRoom();
	direction scene();
	void sceneText();
	bool getbossDead();
	void battleScene();
};
#endif