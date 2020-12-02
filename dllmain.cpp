// dllmain.cpp : Defines the entry point for the DLL application.
#include "Includes.h"
#include "PacketSend.h"
#include "AutoAttack.h"

DWORD WINAPI HackThread(HMODULE hModule)
{
    PacketSend sendPacket;
    AutoAttack attacker;
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "Hello there, we are injected!\n";

    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"Tibia.exe");

    bool autoattackerState = false;

    while (true)
    {
        if (GetAsyncKeyState(VK_END) & 1)
        {
            break;
        }
        if (GetAsyncKeyState(VK_NUMPAD1) & 1)
        {
            sendPacket.PrintWhiteMsg("1337 in da house");
        }
        if (GetAsyncKeyState(VK_NUMPAD2) & 1)
        {
            sendPacket.Say(1, "Hello GH");
        }
        if (GetAsyncKeyState(VK_NUMPAD3) & 1)
        {
            sendPacket.Attack(0x80000224);
        }
        if (GetAsyncKeyState(VK_NUMPAD4) & 1)
        {
            sendPacket.Follow(0x80000224);
        }
        if (GetAsyncKeyState(VK_NUMPAD5) & 1)
        {
            autoattackerState = !autoattackerState;
        }
        if (autoattackerState)
        {
            if (*(int*)(moduleBase + addresses.redSquareAddy) == 0)
            {
                uint32_t targetId = attacker.getTargetId();
                if (targetId > 0)
                {
                    sendPacket.Attack(targetId);
                    *(int*)(moduleBase + addresses.redSquareAddy) = targetId;
                }
            }

        }
        Sleep(10);
    }
    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
//https://guidedhacking.com/threads/tibia-ollydbg-reverse-engineering-function-calling.14434/
}