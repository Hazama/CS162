/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: TrapRoom.cpp file. Holds a large monster, and traps the player until monster is defeated. 
*********************************************************************/

#include "TrapRoom.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** Function: TrapRoom
** Description: Constructor
*********************************************************************/
TrapRoom::TrapRoom()
{
	artFile = "largemon.txt"; //http://chris.com/ascii/index.php?art=creatures/monsters
	battleDone = false;
	north = NULL;
	west = NULL;
	south = NULL;
	east = NULL;
	playerPoint = NULL;
}

/*********************************************************************
** Function: ~TrapRoom
** Description: Destructor
*********************************************************************/
TrapRoom::~TrapRoom()
{
}

/*********************************************************************
** Function: battleScene
** Description: Runs combat between monster and player
*********************************************************************/
void TrapRoom::battleScene()
{

	printArt(artFile);

	cout << "You stumble into a trap! A large monster corners you." << endl;
	playerPoint->calcDamage(b1.attack()); //monster attacks


	while (b1.getDead() == false && playerPoint->getDead() == false) //battle until someone dies
	{
		int userInput;
		cout << "Current Health: " << playerPoint->getHealth() << endl;
		cout << "1. Attack" << endl;
		cout << "2. Check Inventory" << endl;
		cout << "3. Run away" << endl;
		cout << "4. Beg for mercy" << endl;

		cin >> userInput;

		if (userInput == 1)
		{
			b1.calcDamage(playerPoint->attack()); //player attacks
			playerPoint->calcDamage(b1.attack()); //monster fights back
		}

		else if (userInput == 2)
		{
			playerPoint->displayInv();
		}

		else if (userInput == 3)
		{
			cout << "You can't run from this fight!" << endl;
		}

		else if (userInput == 4)
		{
			cout << "The monster laughs at you. NO MERCY!" << endl;
			playerPoint->calcDamage(b1.attack());
		}

		else
		{
			cout << "That isn't a valid option." << endl;
		}

		if (b1.getDead())
		{
			battleDone = true;
		}

		if (playerPoint->getDead() == true)
		{
			battleDone = true;
		}

	}
}

/*********************************************************************
** Function: scene
** Description: runs special room scenario
*********************************************************************/
direction TrapRoom::scene()
{
	if (!battleDone)
	{
		battleScene();
	}

	if (battleDone == true);
	{

		if (playerPoint->getDead() == true)
		{
			return NONE;
		}

		sceneText();

		bool sceneEnd = false;

		while (!sceneEnd)
		{

			int userInput;
			cout << "Current Health: " << playerPoint->getHealth() << endl;
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
** Description: displays special room text
*********************************************************************/
void TrapRoom::sceneText()
{
	cout << "You managed to survive the trap. Probably best to move on." << endl;
}
