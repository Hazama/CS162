/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: StartingRoom.cpp file. Player spawns in this room.
*********************************************************************/

#include "StartRoom.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** Function: StartRoom
** Description: Constructor
*********************************************************************/
StartRoom::StartRoom()
{
	bool premEnd = false; 
	north = NULL;
	west = NULL;
	south = NULL;
	east = NULL;
	playerPoint = NULL;

}

/*********************************************************************
** Function: ~StartRoom
** Description: Destructor
*********************************************************************/
StartRoom::~StartRoom()
{
}

/*********************************************************************
** Function: scene
** Description: Plays special room scenario
*********************************************************************/
direction StartRoom::scene()
{
	sceneText();

	bool sceneEnd = false;

	//prompts user for input
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

		else if (userInput == 3) //user tries to leave cave before defeating boss
		{
				
				std::string userChoice;
				cout << "Do you truly wish to leave the cave?" << endl;
				cout << "yes/no" << endl;
				cin >> userChoice;
				
				if (userChoice == "yes" || userChoice == "y")
				{
					premEnd = true; 
					sceneEnd = true;
					return SOUTH;
				}

				else
				{
					cout << "Find the courage to march on" << endl; 
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
** Function: sceneText
** Description: Displays special scene text if applicable. 
*********************************************************************/
void StartRoom::sceneText()
{
	cout << "This is the entrance to the cave. To the south lies the exit." << endl;
}

bool StartRoom::getpremEnd()
{
	return premEnd;
}
