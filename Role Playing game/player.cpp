#include <iostream>
#include "player.h"
#include "random.h"

using namespace std;

CPlayer::CPlayer()
{
	strncpy_s(m_pcName, "Default", 19);
	strncpy_s(m_pcClassName, "Default", 19);
	m_iAccuracy = 0;
	m_iHitPoints = 0;
	m_iMaxHitPoints = 0;
	m_iExpPoints = 0;
	m_iNextLevelExp = 0;
	m_iLevel = 0;
	m_iArmor = 0;
	strncpy_s(m_Weapon.pcName, "Default Weapon Name", 19);
	m_Weapon.DamageRange.iLow = 0;
	m_Weapon.DamageRange.iHigh = 0;

}

bool CPlayer::IsDead()
{
	return (m_iHitPoints <= 0);
}

int CPlayer::GetArmor()
{
	return (m_iArmor);
}

void CPlayer::TakeDamage(int _iDamage)
{
	m_iHitPoints = m_iHitPoints- _iDamage;
}

void CPlayer::CreateClass()
{
	cout << "--------------------------" << endl;
	cout << "CHARACTER CLASS GENERATION" << endl;
	cout << "--------------------------" << endl;

	cout << "Enter your character's name: ";
	scanf_s("%s", m_pcName, 20);

	cout << "Please select a character class number..." << endl;
	cout << "1)Fighter 2)Wizard 3)Cleric 4)Thief : ";
	cout << endl << "choice: ";

	int iCharacterNum = 1;
	cin >> iCharacterNum;

	switch (iCharacterNum)
	{
	case 1: // Fighter
		strncpy_s(m_pcClassName, "Fighter", 19);
		m_iAccuracy = 13;
		m_iHitPoints = 22;
		m_iMaxHitPoints = 25;
		m_iExpPoints = 0;
		m_iNextLevelExp = 1000;
		m_iLevel = 1;
		m_iArmor = 4;
		strncpy_s(m_Weapon.pcName, "Long Sword", 19);
		m_Weapon.DamageRange.iLow = 1;
		m_Weapon.DamageRange.iHigh = 8;
		break;
	case 2: // Wizard
		strncpy_s(m_pcClassName, "Wizard", 19);
		m_iAccuracy = 5;
		m_iHitPoints = 10;
		m_iMaxHitPoints = 10;
		m_iExpPoints = 0;
		m_iNextLevelExp = 1000;
		m_iLevel = 1;
		m_iArmor = 1;
		strncpy_s(m_Weapon.pcName, "Staff", 19);
		m_Weapon.DamageRange.iLow = 1;
		m_Weapon.DamageRange.iHigh = 4;
		break;
	case 3: // Cleric
		strncpy_s(m_pcClassName, "Cleric", 19);
		m_iAccuracy = 8;
		m_iHitPoints = 15;
		m_iMaxHitPoints = 15;
		m_iExpPoints = 0;
		m_iNextLevelExp = 1000;
		m_iLevel = 1;
		m_iArmor = 3;
		strncpy_s(m_Weapon.pcName, "Flail", 19);
		m_Weapon.DamageRange.iLow = 1;
		m_Weapon.DamageRange.iHigh = 6;
		break;
	default: // Thief
		strncpy_s(m_pcClassName, "Thief", 19);
		m_iAccuracy = 7;
		m_iHitPoints = 12;
		m_iMaxHitPoints = 12;
		m_iExpPoints = 0;
		m_iNextLevelExp = 1000;
		m_iLevel = 1;
		m_iArmor = 2;
		strncpy_s(m_Weapon.pcName, "Short Sword", 19);
		m_Weapon.DamageRange.iLow = 1;
		m_Weapon.DamageRange.iHigh = 6;
		break;
	}
}




bool CPlayer::Attack(CMonster & _rMonster)
{
	int iSelection = 1;
	cout << "1) Attack, 2) Run: ";
	cout << endl << endl;
	cin >> iSelection;
	cout << endl;

	switch (iSelection)
	{
	case 1:
		cout << "You attack an " << _rMonster.GetName()
			<< " with a " << m_Weapon.pcName << endl;
		if (Random(0, 20) < m_iAccuracy)
		{
			int iDamage = Random(m_Weapon.DamageRange);
			int iTotalDamage = iDamage - _rMonster.GetArmor();
			if (iTotalDamage <= 0)
			{
				cout << "Your attack failed to penetrate "
					<< "the armor." << endl;
			}
			else
			{
				cout << "You attack for " << iTotalDamage
					<< " damage!" << endl;
				// Subtract from monster's hitpoints.
				_rMonster.TakeDamage(iTotalDamage);
			}
		}
		else
		{
			cout << "You miss!" << endl;
		}
		cout << endl;
		break;
	case 2:
		// 25 % chance of being able to run.
		int iRoll = Random(1, 4);
		if (iRoll == 1)
		{
			cout << "You run away!" << endl;
			return (true);//<--Return out of the function.
		}
		else
		{
			cout << "You could not escape!" << endl;
			break;
		}
	}
	return (false);

}

void CPlayer::LevelUp()
{
	if (m_iExpPoints >= m_iNextLevelExp)
	{
		cout << "You gained a level!" << endl;
		// Increment level.
		m_iLevel++;
		// Set experience points required for next level.
		m_iNextLevelExp = m_iLevel * m_iLevel * 1000;
		// Increase stats randomly.
		m_iAccuracy += Random(1, 3);
		m_iMaxHitPoints += Random(2, 6);
		m_iArmor += Random(1, 2);
		// Give player full hitpoints when they level up.
		m_iHitPoints = m_iMaxHitPoints;
	}
}

void CPlayer::Rest()
{
	cout << "Resting..." << endl;
	m_iHitPoints = m_iMaxHitPoints;
}

void CPlayer::ViewStats()
{
	cout << "------------" << endl;
	cout << "PLAYER STATS" << endl;
	cout << "------------" << endl;
	cout << endl;
	cout << "Name = " << m_pcName << endl;
	cout << "Class = " << m_pcClassName << endl;
	cout << "Accuracy = " << m_iAccuracy << endl;
	cout << "Hitpoints = " << m_iHitPoints << endl;
	cout << "MaxHitpoints = " << m_iMaxHitPoints << endl;
	cout << "XP = " << m_iExpPoints << endl;
	cout << "XP for Next Lvl = " << m_iNextLevelExp << endl;
	cout << "Level = " << m_iLevel << endl;
	cout << "Armor = " << m_iArmor << endl;
	cout << "Weapon Name = " << m_Weapon.pcName << endl;
	cout << "Weapon Damage = " << m_Weapon.DamageRange.iLow
		<< "-" << m_Weapon.DamageRange.iHigh << endl;
	cout << endl;


}

void CPlayer::Victory(int _iXp)
{
	cout << "You won the battle!" << endl;
	cout << "You win " << _iXp
		<< " experience points!" << endl << endl;
	m_iExpPoints = m_iExpPoints+_iXp;

}

void CPlayer::Gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "----------" << endl;
	cout << "GAME OVER!" << endl;
	cout << "----------" << endl;
	cout << "Press 'q' to quit: ";
	char cQ = 'q';
	cin >> cQ;
	cout << endl;
}

void CPlayer::DisplayHitPoints()
{
	cout << m_pcName << "'s hitpoints = " << m_iHitPoints << endl;
	
}
