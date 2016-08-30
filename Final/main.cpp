/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: main.cpp file. Makes an adventure object and calls its Quest function to run the game.
*********************************************************************/

#include "EmptyRoom.hpp"
#include "Room.hpp"
#include "Player.hpp"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "Adventure.hpp"

/*********************************************************************
** Function: main
** Description: Creates adventure and calls its Quest function to run game.
*********************************************************************/
int main()
{
	srand(time(NULL)); //seed for random number generation

	Adventure a1;

	a1.Quest();

	return 0;
}