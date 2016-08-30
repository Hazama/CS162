/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: WeakRoom.cpp file. Room that holds small monsters
*********************************************************************/

#include "WeakRoom.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** Function: WeakRoom
** Description: Constructor
*********************************************************************/
WeakRoom::WeakRoom()
{
	artFile = "weakmon.txt"; //http://www.ascii-code.com/ascii-art/animals/bats.php
	battleDone = false;
	north = NULL;
	west = NULL;
	south = NULL;
	east = NULL;
	playerPoint = NULL;
	run = false;
}

/*********************************************************************
** Function: ~WeakRoom
** Description: Destructor
*********************************************************************/
WeakRoom::~WeakRoom()
{
}

/*********************************************************************
** Function: battleScene
** Description: Runs combat between player and monster
*********************************************************************/
void WeakRoom::battleScene()
{

	printArt(artFile);
	cout << "You stumble into a room with a small monster!" << endl;

	int x = rand() % 2; //0 or 1 //monsters may attack first

	if (x == 0)
	{
		cout << "The monster jumps you before you can react" << endl;

		playerPoint->calcDamage(s1.attack());
	}

	while (s1.getDead() == false && playerPoint->getDead() == false && run == false) //battle until player runs or someone dies. battle ends if player runs
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
			s1.calcDamage(playerPoint->attack()); //player attacks
			playerPoint->calcDamage(s1.attack()); //monster fights back
		}

		else if (userInput == 2)
		{
			playerPoint->displayInv();
		}

		else if (userInput == 3)
		{
			cout << "You flee!" << endl;
			run = true;
			
		}

		else if (userInput == 4)
		{
			cout << "The monster laughs at you. And then strikes." << endl;
			playerPoint->calcDamage(s1.attack());
		}

		else
		{
			cout << "That isn't a valid option." << endl;
		}

		if (s1.getDead())
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
** Description: runs room's special scenario
*********************************************************************/
direction WeakRoom::scene()
{
	if (!battleDone)
	{
		battleScene();
	}

	if (run) //if player ran
	{
		run = false; //reset run to false for the future
		return NONE; //return special flag for when the player flees
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
** Function: sceneText()
** Description: displays special scene text
*********************************************************************/
void WeakRoom::sceneText()
{
	cout << "The smell of dead monster fills the room. There's nothing left here for you to do." << endl;
}
