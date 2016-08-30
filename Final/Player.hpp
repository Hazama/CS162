/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: Player.hpp
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <cstdlib>

class Player
{
protected:
	std::string arr[5];
	int arrNum;
	bool pendant;
	bool finSword;
	int health;
	bool dead;
public:
	Player();
	~Player();
	int attack();
	void useItem(std::string s);
	void addItem(std::string s);
	void removeItem(std::string s);
	void setHealth(int n);
	int getHealth();
	bool getPendant();
	void setPendant(bool b);
	void setSword(bool b);
	bool getSword();
	void displayInv();
	int getarrNum();
	void calcDamage(int i);
	bool getDead();

};

#endif