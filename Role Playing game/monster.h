#ifndef __RPG_MONSTER_H__
#define __RPG_MONSTER_H__
#include "weapon.h"
//#include "player.h"
// this is a forward class declaration
// it allows us to use the CPlayer without having defined it
// similiar to the way we use FUNCTION DECLARATIONS above main()
// then define it after main. ( Trick the compiler )
//Forward Declaration

class CPlayer;

class CMonster
{
public:
	CMonster(const char* _pcName, int _iHitPoints, int _iAcc,
		int _iXpReward, int _iArmor, const char* _pcWeaponName,
		int _iLowDamage, int _iHighDamage);

	bool IsDead();

	int GetXPReward();
	const char* GetName();		//spits out an array 
	int GetArmor();
	void Attack(CPlayer & _rPlayer);		//takes in a reference of object of cplayer type
	void TakeDamage(int _iDamage);
	void DisplayHitPoints();
private:
	char m_pcName[20];
	int m_iHitPoints;
	int m_iAccuracy;
	int m_iExpReward;
	int m_iArmor;
	TWeapon m_Weapon;
};
#endif