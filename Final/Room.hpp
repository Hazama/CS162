/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: Room.hpp file
*********************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Direction.hpp"
#include "Player.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Room
{
protected:
	std::string artFile;
	Player *playerPoint;
	Room *north;
	Room *south;
	Room *west;
	Room *east;
public:
	Room();
	~Room();
	virtual void printArt(std::string filename);
	std::string gatherArtwork(std::ifstream& File);
	virtual direction scene() = 0;
	void setNorth(Room *p);
	void setSouth(Room *p);
	void setWest(Room *p);
	void setEast(Room *p);
	Room* getNorth();
	Room* getSouth();
	Room* getEast();
	Room* getWest();
	virtual void sceneText();
	void setPlayerPoint(Player *p);
	Player getPlayer();
};
#endif
