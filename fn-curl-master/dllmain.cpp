#include <Windows.h>
#include "curl.h"

BOOL APIENTRY DllMain(HMODULE module, DWORD call_reason, LPVOID reserved) {

    if (call_reason != 1) // 1 is dll attach
        return 1;

    hookCurl();
    //CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hookCurl, 0, 0, 0);

    return 1;
}

