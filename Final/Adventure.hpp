/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: Adventure.hpp file
*********************************************************************/

#ifndef ADVENTURE_HPP
#define ADVENTURE_HPP

#include "Player.hpp"
#include "Room.hpp"
#include "EmptyRoom.hpp"
#include "WeakRoom.hpp"
#include "MidRoom.hpp"
#include "TrapRoom.hpp"
#include "BossRoom.hpp"
#include "Direction.hpp"
#include "PendantRoom.hpp"
#include "StartRoom.hpp"
#include "SwordRoom.hpp"
#include "waterRoom.hpp"
#include <cstdlib>
class Adventure
{
protected:
	bool advenEnd;
	Room *curRoom;
	Room *prevRoom;
	StartRoom start;
	BossRoom bossR;
	WeakRoom w1;
	WeakRoom w2;
	WeakRoom w3;
	EmptyRoom e1;
	EmptyRoom e2;
	SwordRoom sword;
	waterRoom water;
	PendantRoom pendant;
	MidRoom m1;
	TrapRoom t1;
	TrapRoom t2;

	Player p1;

	int turnCount;
public:
	Adventure();
	~Adventure();
	void Quest(); 
	void playerDisplay();
};
#endif