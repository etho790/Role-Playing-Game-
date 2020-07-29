#include <cstdlib>
#include <ctime>
#include <iostream>
#include "map.h"
#include "player.h"
#include "monster.h"
using namespace std;

int main()
{
	srand(static_cast<int>(time(0)));

	CMap gameMap;
	CPlayer mainPlayer;

	mainPlayer.CreateClass();
	bool bDone = false;

	while (!bDone)
	{
		// Each loop cycle we output the player position and a selection menu.
		gameMap.PrintPlayerPos();
		int iSelection = 1;
		cout << "----------------" << endl;
		cout << " MAIN MENU " << endl;
		cout << "----------------" << endl;
		cout << "1) Move, 2) Rest, 3) View Stats, 4) Quit: ";
		cout << endl << "choice: ";
		cin >> iSelection;
		CMonster* pMonster = 0;		
		switch (iSelection)
		{
		case 1:
			gameMap.MovePlayer();
			// Check for a random encounter. This function
			// returns a null pointer if no monsters are
			// encountered.
			pMonster = gameMap.CheckRandomEncounter();	//the monster pointer points to a new pointer
			// 'monster' not null, run combat simulation.
			if (pMonster != 0)
			{
				// Loop until a 'break' statement.
				while (true)
				{
					mainPlayer.DisplayHitPoints();
					pMonster->DisplayHitPoints();
					cout << endl;

					// Player's turn to attack first.
					bool bRunAway = mainPlayer.Attack(*pMonster);		//makes the player face the monster thats encountered
					if (bRunAway)
					{
						break;
					}

					if (pMonster->IsDead())
					{
						mainPlayer.Victory(pMonster->GetXPReward());
						mainPlayer.LevelUp();
						break;
					}
					pMonster->Attack(mainPlayer);
					if (mainPlayer.IsDead())
					{
						mainPlayer.Gameover();
						bDone = true;		//loop is broken
						break;
					}
				}
				break;
		case 2:
			mainPlayer.Rest();
			break;
		case 3:
			mainPlayer.ViewStats();
			break;
		case 4:
			bDone = true;
			break;
			}
		}
		
	}

	int iTemp = 0;
	cin >> iTemp;
	return (0);
}


