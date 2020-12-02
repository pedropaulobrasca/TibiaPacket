#pragma once
#include "Includes.h"


struct {
	uintptr_t redSquareAddy = 0x570488;
	uintptr_t entityListStart = 0x76A0B0;
	uintptr_t offsetToAnotherEnttiy = 0xDC;
	uintptr_t selfPlayer = 0x70E050;
}addresses;



class Entity
{
public:
	uint32_t Id; //0x0000
	char name[32]; //0x0004
	int32_t zPos; //0x0024
	int32_t yPos; //0x0028
	int32_t xPos; //0x002C
	char pad_0030[92]; //0x0030
	int32_t hpPerc; //0x008C
}; //Size: 0x0090
static_assert(sizeof(Entity) == 0x90);


class Self
{
public:
	uint32_t Id; //0x0000
	int32_t xPos; //0x0004
	int32_t yPos; //0x0008
	int32_t zPos; //0x000C
}; //Size: 0x0010
static_assert(sizeof(Self) == 0x10);