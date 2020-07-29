#ifndef __RPG_PLAYER_H__
#define __RPG_PLAYER_H__
#include "weapon.h"
#include "monster.h"
class CPlayer
{
public:
	// Constructor.
	CPlayer();
	// Methods
	bool IsDead();
	int GetArmor();
	void TakeDamage(int _iDamage);
	void CreateClass();
	bool Attack(CMonster& _rMonster);
	void LevelUp();
	void Rest();
	void ViewStats();
	void Victory(int _iXp);
	void Gameover();
	void DisplayHitPoints();
private:
	// Data members.
	char m_pcName[20];
	char m_pcClassName[20];
	int m_iAccuracy;
	int m_iHitPoints;
	int m_iMaxHitPoints;
	int m_iExpPoints;
	int m_iNextLevelExp;
	int m_iLevel;
	int m_iArmor;
	TWeapon m_Weapon;
};
#endif
