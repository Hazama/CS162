/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: waterRoom.cpp file. Holds the magical healing water. 
*********************************************************************/

#include "waterRoom.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** Function: waterRoom
** Description: Constructor
*********************************************************************/
waterRoom::waterRoom()
{
	artFile = "water.txt"; //http://www.chris.com/ascii/index.php?art=objects/bottles
	north = NULL;
	west = NULL;
	south = NULL;
	east = NULL;
	playerPoint = NULL;
	water = false;
}

/*********************************************************************
** Function: ~waterRoom
** Description: Destructor
*********************************************************************/
waterRoom::~waterRoom()
{
}

/*********************************************************************
** Function: scene
** Description: Runs special scenario
*********************************************************************/
direction waterRoom::scene()
{
	if (!water) //water not yet taken by player
	{
		printArt(artFile);
		cout << endl;
		cout << "You stumble upon a magical healing spring. You bottle up the healing waters." << endl;
		playerPoint->addItem("lifeWater");
		water = true;

	}

	if (water)
	{
		sceneText();

		bool sceneEnd = false;

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
** Description: Special room text
*********************************************************************/
void waterRoom::sceneText()
{
	cout << "It would be greedy to take more water. Best to move on." << endl;
}
