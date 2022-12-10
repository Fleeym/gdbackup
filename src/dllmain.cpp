#include "includes.hpp"
#include "MenuLayer.hpp"

/**
 * Notes to self
 * 
 * When hooking, we need void* only if function has parameters.
*/

DWORD WINAPI thread_func(void* hModule) {
    MH_Initialize();
    MH_CreateHook(
        reinterpret_cast<void*>(gd::base + 0x1907b0),
        reinterpret_cast<void*>(MenuLayer::init_hook),
        reinterpret_cast<void**>(&MenuLayer::init)
    );

    MH_EnableHook(MH_ALL_HOOKS);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        auto h = CreateThread(0, 0, thread_func, handle, 0, 0);
        if (h)
            CloseHandle(h);
        else
            return FALSE;
    }
    return TRUE;
}