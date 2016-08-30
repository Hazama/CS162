/*********************************************************************
** Author: Jeffery Goss
** Date: 03/10/16
** Description: Monster.hpp file
*********************************************************************/

#ifndef MONSTER_HPP
#define MONSTER_HPP
class Monster
{
protected:
	int health;
	bool dead;
public:
	Monster();
	~Monster();
	virtual int attack();
	void setHealth(int i);
	void calcDamage(int i);
	bool getDead();
};
#endif
