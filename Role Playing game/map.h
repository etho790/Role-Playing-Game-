#ifndef __RPG_MAP_H__
#define __RPG_MAP_H__
#include "weapon.h"
#include "monster.h"
class CMap
{
public:
	// Constructor.
	CMap();
	// Methods
	int GetPlayerXPos();
	int GetPlayerYPos();
	void MovePlayer();
	CMonster* CheckRandomEncounter();
	void PrintPlayerPos();
private:
	// Data members.
	int m_iPlayerXPos;
	int m_iPlayerYPos;
};
#endif