/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: BossRoom.cpp file. Holds the boss monster. Final room of the game.
*********************************************************************/

#include "BossRoom.hpp"
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
** Function: BossRoom
** Description: Constructor
*********************************************************************/
BossRoom::BossRoom()
{
	artFile = "asciiDragon.txt"; //http://www.asciiworld.com/-Dragons,108-.html
	bossDead = false;
}

/*********************************************************************
** Function: ~BossRoom
** Description: Destructor
*********************************************************************/
BossRoom::~BossRoom()
{
}

/*********************************************************************
** Function: scene
** Description: Plays the room's special scene
*********************************************************************/
direction BossRoom::scene()
{

	if (playerPoint->getPendant() == false) //if the player lacks the pendant
	{
		cout << "You cannot enter the dragon's lair without the mystic pendant." << endl;
		return NONE; 
	}

	if (!bossDead) //if the boss is alive
	{
		printArt(artFile);
		cout << endl;

		cout << "YOU DARE ENTER MY LAIR? YOU SHALL NOT ESCAPE!" << endl;	

		battleScene();
	}

	if (playerPoint->getDead() == true)
	{
		return NONE;
	}

	sceneText(); //boss will be dead at this point in the function
	bossDead = true;
}

void BossRoom::sceneText()
{
	cout << "You have defeated the dragon and won the game. Congratulations!" << endl;
}

bool BossRoom::getbossDead()
{
	return bossDead;
}
/*********************************************************************
** Function: battleScene
** Description: Has the player and monster do battle
*********************************************************************/
void BossRoom::battleScene()
{
	while (boss.getDead() == false && playerPoint->getDead() == false) //battle until player or boss dies
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
			boss.calcDamage(playerPoint->attack()); //player attacks
			playerPoint->calcDamage(boss.attack()); //monster fights back
		}

		else if (userInput == 2)
		{
			playerPoint->displayInv();
		}

		else if (userInput == 3)
		{
			cout << "You cannot run from a boss battle!" << endl;

		}

		else if (userInput == 4)
		{
			cout << "The dragon laughs at you. And then strikes." << endl;
			playerPoint->calcDamage(boss.attack());
		}

		else
		{
			cout << "That isn't a valid option." << endl;
		}

	}
}
