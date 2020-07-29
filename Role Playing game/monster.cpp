#include <iostream>
#include "monster.h"
#include "player.h"
#include "random.h"

using namespace std;

CMonster::CMonster(const char* _pcName, int _iHitPoints, int _iAcc,
	int _iXpReward, int _iArmor, const char* _pcWeaponName,
	int _iLowDamage, int _iHighDamage)
{
	strncpy_s(m_pcName, _pcName, 19);		//copies the first 19 characters of _pcName inputted
	m_iHitPoints = _iHitPoints;
	m_iAccuracy = _iAcc;
	m_iExpReward = _iXpReward;
	m_iArmor = _iArmor;
	strncpy_s(m_Weapon.pcName, _pcWeaponName, 19);		//copies the first 19 characters of _pcweaponName inputted into m_Weapon.pcName
	m_Weapon.DamageRange.iLow = _iLowDamage;	//sets the damage range varaibles of the object of weapon
	m_Weapon.DamageRange.iHigh = _iHighDamage;

}

bool CMonster::IsDead()
{
	return (m_iHitPoints <= 0);

}

int CMonster::GetXPReward()
{
	return (m_iExpReward);
}

const char * CMonster::GetName()		//spits out a char pointer, which is an arraythat is returned
{
	return (m_pcName);
}

int CMonster::GetArmor()
{
	return (m_iArmor);
}

void CMonster::Attack(CPlayer & _rPlayer)
{
	cout << "A " << m_pcName << " attacks you with a "
		<< m_Weapon.pcName << endl;
	// Test to see if the monster hit the player.
	if (Random(0, 20) < m_iAccuracy)
	{
		// Generate a damage value based on the weapons range.
		int iDamage = Random(m_Weapon.DamageRange);
		int iTotalDamage = iDamage - _rPlayer.GetArmor();
		// If totalDamage <= 0, then we say that, although
		// the attack hit, it did not penetrate the armor.
		
		if( iTotalDamage<=0)
		{ 
			cout << "The monster's attack failed to "
				<< "penetrate your armor." << endl;
		}
		else
		{
			cout << "You are hit for " << iTotalDamage
				<< " damage!" << endl;
			_rPlayer.TakeDamage(iTotalDamage);


		}

	}

	else
	{
		cout << "The " << m_pcName << " missed!" << endl;
	}
	cout << endl;

}

void CMonster::TakeDamage(int _iDamage)
{

	m_iHitPoints = m_iHitPoints- _iDamage;
}

void CMonster::DisplayHitPoints()
{
	cout << m_pcName << "'s hitpoints = " << m_iHitPoints << endl;
}
