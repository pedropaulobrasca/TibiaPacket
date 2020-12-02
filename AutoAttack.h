#pragma once
#include "Includes.h"
class AutoAttack
{
public:
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"Tibia.exe");
	Entity* ent;
	Self* player = (Self*)(moduleBase + addresses.selfPlayer);

	uint32_t getTargetId();
};

