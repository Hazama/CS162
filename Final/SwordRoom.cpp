/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: SwordRoom.cpp file. Room that holds the magic sword. 
*********************************************************************/

#include "SwordRoom.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;


/*********************************************************************
** Function: SwordRoom
** Description: Constructor
*********************************************************************/
SwordRoom::SwordRoom()
{
	artFile = "magicSword.txt"; //http://www.asciiworld.com/-Blades-.html
	north = NULL;
	west = NULL;
	south = NULL;
	east = NULL;
	playerPoint = NULL;
	sword = false;
}

/*********************************************************************
** Function: ~SwordRoom
** Description: Destructor
*********************************************************************/
SwordRoom::~SwordRoom()
{
}

/*********************************************************************
** Function: scene
** Description: Runs special room scenario
*********************************************************************/
direction SwordRoom::scene()
{
	if (!sword) //sword not recieved by player
	{
		printArt(artFile);
		cout << endl;
		cout << "You stumble upon the legendary magical sword. You feel powerful with it in your hands." << endl;
		playerPoint->setSword(true);
		playerPoint->addItem("magicSword");
		sword = true;
	}
	
	if (sword) //player has sword
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
** Description: Displays special room text
*********************************************************************/
void SwordRoom::sceneText()
{
	cout << "This room is empty now. Nothing left to do here." << endl;
}
