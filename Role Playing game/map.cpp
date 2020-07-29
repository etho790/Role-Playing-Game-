#include <iostream>
#include "map.h"
#include "random.h"
using namespace std;

CMap::CMap()
{

	// Player starts at origin (0, 0)
	m_iPlayerXPos = 0;
	m_iPlayerYPos = 0;
}

int CMap::GetPlayerXPos()
{
	return (m_iPlayerXPos);
}

int CMap::GetPlayerYPos()
{
	return (m_iPlayerYPos);
}

void CMap::MovePlayer()
{

	int iSelection = 1;
	cout << "-----------------" << endl;
	cout << " MOVE PLAYER " << endl;
	cout << "-----------------" << endl;
	cout << "1) North, 2) East, 3) South, 4) West: ";
	cout << endl << "choice: ";
	cin >> iSelection;
	switch (iSelection)
	{
	case 1: // North
		m_iPlayerYPos++;
		break;
	case 2: // East
		m_iPlayerXPos++;
		break;
	case 3: // South
		m_iPlayerYPos--;
		break;
	default: // West
		m_iPlayerXPos--;
		break;
	}
	cout << endl;
}

CMonster * CMap::CheckRandomEncounter()
{
	int iRoll = Random(0, 20);
	CMonster* pMonster = 0;
	if (iRoll <= 5)
	{
		// No encounter, return a null pointer.
		return (0);
	}
	else if (iRoll >= 6 && iRoll <= 10)
	{
		pMonster = new CMonster("Orc", 10, 8, 200, 1,
			"Short Sword", 2, 7);
		cout << "You encountered a " << pMonster->GetName()
			<< "!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if (iRoll >= 11 && iRoll <= 15)
	{
		pMonster = new CMonster("Goblin", 6, 6, 100, 0,
			"Dagger", 1, 5);
		cout << "You encountered a " << pMonster->GetName()
			<< "!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if (iRoll >= 16 && iRoll <= 19)
	{
		pMonster = new CMonster("Ogre", 20, 12, 500, 2,
			"Club", 3, 8);
		cout << "You encountered a " << pMonster->GetName()
			<< "!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	else if (iRoll == 20)
	{
		pMonster = new CMonster("Orc Lord", 25, 15, 2000, 5,
			"Two Handed Sword", 5, 20);
		cout << "You encountered a " << pMonster->GetName()
			<< "!" << endl;
		cout << "Prepare for battle!" << endl;
		cout << endl;
	}
	return (pMonster);		//returns whatever the Cmonster object was pointing to
}

void CMap::PrintPlayerPos()
{
	cout << "Player Position = (" << m_iPlayerXPos <<", "<< m_iPlayerYPos << ")" << endl << endl;
}
