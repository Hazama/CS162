/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: EmptyRoom.cpp file. Allows for the creation of empty rooms.
*********************************************************************/

#include "EmptyRoom.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
/*********************************************************************
** Function: EmptyRoom
** Description: Constructor
*********************************************************************/
EmptyRoom::EmptyRoom()
{
	north = NULL;
	west = NULL;
	south = NULL;
	east = NULL;
	playerPoint = NULL;
}

/*********************************************************************
** Function: ~EmptyRoom
** Description: Destructor
*********************************************************************/
EmptyRoom::~EmptyRoom()
{
}

/*********************************************************************
** Function: sceneText
** Description: Displays special scene text
*********************************************************************/
void EmptyRoom::sceneText()
{
	cout << "An empty room. You feel like you may have seen this before." << endl;
}

/*********************************************************************
** Function: scene
** Description: Runs room's special scene
*********************************************************************/
direction EmptyRoom::scene()
{
	sceneText();

	bool sceneEnd = false;

	//prompt user to enter direction
	while (!sceneEnd)
	{
		int userInput;

		cout << "1. Go North" << endl;
		cout << "2. Go East" << endl;
		cout << "3. Go South" << endl;
		cout << "4. Go West" << endl;
		cout << "5. Check inventory" << endl;

		cin >> userInput;

		if (userInput == 1)
		{
			if (north != NULL)
			{
				sceneEnd = true;
				return NORTH;
			}

			else
			{
				cout << "You cannot go that way." << endl;
			}
		}

		else if (userInput == 2)
		{
			if (east != NULL)
			{
				sceneEnd = true;
				return EAST;
			}

			else
			{
				cout << "You cannot go that way." << endl;
			}
		}

		else if (userInput == 3)
		{
			if (south != NULL)
			{
				sceneEnd = true;
				return SOUTH;
			}
			else
			{
				cout << "You cannot go that way." << endl;
			}
		}

		else if (userInput == 4)
		{
			if (west != NULL)
			{
				sceneEnd = true;
				return WEST;
			}
			else
			{
				cout << "You cannot go that way." << endl;
			}
		}

		else if (userInput == 5)
		{
			playerPoint->displayInv();

		}

		else
		{
			cout << "Invalid Input" << endl;
		}
	}
}

/*********************************************************************
** Function: printArt
** Description: displays artwork
*********************************************************************/
void EmptyRoom::printArt()
{
	cout << endl;
}
