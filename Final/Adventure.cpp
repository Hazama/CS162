/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: Adventure.cpp file. Builds and runs the game.
*********************************************************************/

#include "Adventure.hpp"
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
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** Function: Adventure
** Description: Sets all the pointers of all the rooms. Establishes initial turncount.
*********************************************************************/
Adventure::Adventure()
{

	turnCount = 0;

	//set player pointer in all the rooms
	start.setPlayerPoint(&p1);
	bossR.setPlayerPoint(&p1);
	w1.setPlayerPoint(&p1);
	w2.setPlayerPoint(&p1);
	w3.setPlayerPoint(&p1);
	e1.setPlayerPoint(&p1);
	e2.setPlayerPoint(&p1);
	sword.setPlayerPoint(&p1);
	water.setPlayerPoint(&p1);
	pendant.setPlayerPoint(&p1);
	m1.setPlayerPoint(&p1);
	t1.setPlayerPoint(&p1);
	t2.setPlayerPoint(&p1);

	prevRoom = NULL;
	curRoom = &start; //player begins in start room


	//set up dungeon by connecting rooms

	start.setNorth(&e1);
	start.setEast(&w1);
	start.setWest(&t1);

	w1.setNorth(&m1);
	w1.setWest(&start);

	t1.setEast(&start);
	t1.setNorth(&e2);
	t1.setWest(&water);

	water.setNorth(&sword);
	water.setEast(&t1);

	sword.setSouth(&water);
	sword.setEast(&e2);

	e2.setSouth(&t1);
	e2.setNorth(&w3);
	e2.setEast(&e1);
	e2.setWest(&sword);

	e1.setSouth(&start);
	e1.setEast(&m1);
	e1.setWest(&e2);
	e1.setNorth(&w2);

	m1.setSouth(&w1);
	m1.setWest(&e1);
	m1.setNorth(&pendant);

	pendant.setSouth(&m1);
	pendant.setNorth(&t2);
	pendant.setWest(&w2);

	t2.setSouth(&pendant);

	w2.setSouth(&e1);
	w2.setEast(&pendant);
	w2.setWest(&w3);

	w3.setNorth(&bossR);
	w3.setSouth(&e2);
	w3.setEast(&w2);
}

/*********************************************************************
** Function: ~Adventure
** Description: Destructor
*********************************************************************/
Adventure::~Adventure()
{
}

/*********************************************************************
** Function: Quest
** Description: Runs the game
*********************************************************************/
void Adventure::Quest()
{
	//intro text
	cout << "You have entered the Dragon's Cave to defeat the dragon that has been terrorizing your village." << endl;
	cout << "Armed with only a rusty sword, you have no chance. But luckily there are items of power hidden in the cave." << endl;
	cout << "You must find the mystic pendant, capable of opening the Dragon's lair." << endl;
	cout << "To stand a chance of defeating the dragon in battle you must find the magic sword." << endl;
	cout << "Finally, rumor has it that magical healing waters can be found in this cave. This will surely help you on your quest." << endl;
	cout << "Good luck adventurer." << endl;

	while (!advenEnd) //whole adventure isn't over
	{

		if (start.getpremEnd() == true) //check to see if player left cave before defeating boss 
		{
			cout << "You left the cave before completing your quest" << endl;
			cout << "GAME OVER" << endl;
			advenEnd = true;
			break;
		}
		
		if (bossR.getbossDead() == true) //check to see if player has defeated the boss
		{
			cout << "YOU WIN" << endl;
			advenEnd = true;
			break;
		}

		if (p1.getDead() == true) //check to see if player is dead
		{
			cout << "You have died" << endl;
			advenEnd = true;
			break;
		}

		if (turnCount > 30) //check to see if player has run out of time
		{
			cout << "You ran out of time... GAME OVER" << endl;
			advenEnd = true;
			break;
		}

		cout << endl; 
		playerDisplay();
		cout << endl;
		direction x = curRoom->scene(); //play room scene

		if (x == NORTH) //move player in direction they choose
		{
			prevRoom = curRoom;
			curRoom = curRoom->getNorth();
		}

		else if (x == SOUTH)
		{
			prevRoom = curRoom;
			curRoom = curRoom->getSouth();
		}

		else if (x == EAST)
		{
			prevRoom = curRoom;
			curRoom = curRoom->getEast();
		}

		else if (x == WEST)
		{
			prevRoom = curRoom;
			curRoom = curRoom->getWest();
		}

		else if (x == NONE)
		{
			curRoom = prevRoom; 
		}

		turnCount += 1; //increment time after a move
	}
}

/*********************************************************************
** Function: playerDisplay
** Description: Displays player health and turn count
*********************************************************************/
void Adventure::playerDisplay()
{
	cout << "Current Health: " << p1.getHealth() << endl; 
	cout << "Turn: " << turnCount << endl;
}
