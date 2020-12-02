#include "AutoAttack.h"

uint32_t AutoAttack::getTargetId()
{
	for (int i = 0; i < 1300; i++)
	{
		ent = (Entity*)(moduleBase + addresses.entityListStart + (addresses.offsetToAnotherEnttiy * i));
		if (ent->Id > 0)
		{
			if ((ent->zPos == player->zPos) && (abs(ent->xPos - player->xPos) <= 7) && (abs(ent->yPos - player->yPos) <= 5) && (ent->Id != player->Id) && (ent->hpPerc > 0) && (ent->Id > 0x40000000))
			{
				return ent->Id;
			}
		}
	}
}