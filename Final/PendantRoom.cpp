/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: PendantRoom.cpp file. Makes a room that holds the mystic pendant needed to advance the game.
*********************************************************************/

#include "PendantRoom.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


/*********************************************************************
** Function: PendantRoom
** Description: Constructor
*********************************************************************/
PendantRoom::PendantRoom()
{
	artFile = "pendant.txt"; //http://ascii.co.uk/art/necklace  artwork file name
	north = NULL;
	west = NULL;
	south = NULL;
	east = NULL;
	playerPoint = NULL;
	pendant = false;
}

/*********************************************************************
** Function: ~PendantRoom
** Description: Destructor
*********************************************************************/
PendantRoom::~PendantRoom()
{
}

/*********************************************************************
** Function: scene
** Description: Plays the room's special scene
*********************************************************************/
direction PendantRoom::scene()
{
	if (!pendant) //pendant not recieved by player
	{
		printArt(artFile); //display art
		cout << endl;
		cout << "You stumble upon the legendary pendant. So beautiful. You take it and put it on." << endl;
		playerPoint->setPendant(true); //player has pendant
		playerPoint->addItem("pendant"); //added to inventory
		pendant = true; //pendant has been taken. room's scene changes
			 
	}

	if (pendant) //player has pendant
	{
		sceneText(); 

		bool sceneEnd = false;

		//prompt player to enter a direction to go in
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
}

/*********************************************************************
** Function: sceneText
** Description: displays special scene text 
*********************************************************************/
void PendantRoom::sceneText()
{
	cout << "This room is now empty. Nothing left to do here." << endl;
}
