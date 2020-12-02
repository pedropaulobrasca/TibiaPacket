#include "PacketSend.h"


void PacketSend::Attack(int creatureId)
{
	reinterpret_cast<void(__fastcall*)(int)>(moduleBase + packetStart)(0xa1);
	reinterpret_cast<void(__fastcall*)(int)>(moduleBase + packetItem)(creatureId);
	reinterpret_cast<void(__fastcall*)(int)>(moduleBase + packetThreeFunc)(10);
	reinterpret_cast<void(__fastcall*)(BYTE)>(moduleBase + packetEndFunc)(1);
}

void PacketSend::Follow(int creatureId)
{
	reinterpret_cast<void(__fastcall*)(int)>(moduleBase + packetStart)(0xa2);
	reinterpret_cast<void(__fastcall*)(int)>(moduleBase + packetItem)(creatureId);
	reinterpret_cast<void(__fastcall*)(int)>(moduleBase + packetThreeFunc)(10);
	reinterpret_cast<void(__fastcall*)(BYTE)>(moduleBase + packetEndFunc)(1);
}

void PacketSend::Say(int chatId, const char* msgToSay)
{
	reinterpret_cast<void(__fastcall*)(int)>(moduleBase + packetStart)(0x96);
	reinterpret_cast<void(__fastcall*)(int)>(moduleBase + packetChannelId)(chatId);
	reinterpret_cast<void(__fastcall*)(const char*)>(moduleBase + packetMsgFunc)(msgToSay);
	reinterpret_cast<void(__fastcall*)(BYTE)>(moduleBase + packetEndFunc)(1);
}

void PacketSend::PrintWhiteMsg(const char* msg)
{
	reinterpret_cast<void(__fastcall*)(const char*)>(moduleBase + printConsole)(msg);
}