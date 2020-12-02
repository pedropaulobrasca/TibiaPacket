#pragma once
#include "Includes.h"
class PacketSend
{
public:
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(nullptr);
	uintptr_t printConsole = 0x214540;
	uintptr_t packetStart = 0x1B5C10;
	uintptr_t packetItem = 0x1B6330;
	uintptr_t packetChannelId = 0x1B5FD0;
	uintptr_t packetMsgFunc = 0x1B6510;
	uintptr_t packetThreeFunc = 0x1B6330;
	uintptr_t packetEndFunc = 0x1B6B10;
	
	void Attack(int creatureId);
	void Follow(int creatureId);
	void Say(int chatId, const char* msgToSay);
	void PrintWhiteMsg(const char* msg);

};

