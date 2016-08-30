/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: Room.cpp file. Base class for Room objects. All Rooms inherit from this.
*********************************************************************/

#include "Room.hpp"
#include "Player.hpp"
using std::cout;
using std::endl;
using std::cin;

/*********************************************************************
** Function: Room
** Description: Constructor
*********************************************************************/
Room::Room()
{
	north = NULL;
	south = NULL;
	west = NULL;
	east = NULL;
	playerPoint = NULL;
}

/*********************************************************************
** Function: ~Room
** Description: Destructor
*********************************************************************/
Room::~Room()
{
}

void Room::setNorth(Room *p)
{
	north = p;
}

void Room::setSouth(Room *p)
{
	south = p;
}

void Room::setWest(Room *p)
{
	west = p;
}

void Room::setEast(Room *p)
{
	east = p;
}

Room* Room::getNorth()
{
	return north;
}

Room* Room::getSouth()
{
	return south;
}

Room* Room::getEast()
{
	return east;
}

Room* Room::getWest()
{
	return west; 
}

/*********************************************************************
** Function: sceneText
** Description: displays special text
*********************************************************************/
void Room::sceneText()
{
	cout << "Default scene text" << endl;
}

void Room::setPlayerPoint(Player *p)
{
	playerPoint = p;
}

Player Room::getPlayer()
{
	return *playerPoint;
}

/*********************************************************************
** Function: gatherArtwork
** Description: Builds the artwork by reading it from a file. 
** Source: Method taken from: http://www.cplusplus.com/forum/general/58945/
*********************************************************************/
std::string Room::gatherArtwork(std::ifstream& File)
{
	std::string Artwork = "";        //line of the ascii art file

	if (File)                      //If the file was successfully opened
	{
		while (File.good()) //read until end of file
		{
			std::string temp;                  //temporary line of artwork
			std::getline(File, temp);        //Get temp line
			temp += "\n";                      //Add newline character after the end of the line

			Artwork += temp;                     //Add line to overall artwork
		}
		return Artwork;
	}
	else                           //Return error
	{
		return "File did not exist.";
	}
}

/*********************************************************************
** Function: printArt
** Description: Prints the artwork associated with the file, if any.
*********************************************************************/
void Room::printArt(std::string filename)
{
	std::ifstream File(filename.c_str());             //Open file

	std::string Art = gatherArtwork(File);       //Get file artwork

	std::cout << Art << std::endl;               //Print it to the screen

	File.close();                           //Close file
}

