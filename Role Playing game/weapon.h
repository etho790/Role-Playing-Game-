#ifndef __RPG_WEAPON_H__
#define __RPG_WEAPON_H__
#include "Range.h"



struct TWeapon
{
	char pcName[20];
	TRange DamageRange;		//every weopon will have a name and a new object from the class TRange called damagerange
};
#endif
