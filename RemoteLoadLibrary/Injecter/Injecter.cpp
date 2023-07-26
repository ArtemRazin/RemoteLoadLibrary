// Injecter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "..\..\BoxedApp\include\BoxedAppSDK.h"

#ifdef _WIN64
#pragma comment(lib, "..\\..\\BoxedApp\\lib\\x64\\bxsdk64.lib")
#else
#pragma comment(lib, "..\\..\\BoxedApp\\lib\\bxsdk32.lib")
#endif // _WIN64

int main()
{
    std::cout << "Enter PID: ";

    DWORD pid;
    std::cin >> pid;

    BoxedAppSDK_Init();

    CloseHandle(BoxedAppSDK_CreateVirtualFile(
        L"1.dll",
        GENERIC_WRITE,
        FILE_SHARE_READ,
        nullptr,
        CREATE_NEW,
        0,
        nullptr));

    if (!::CopyFileW(L"Library.dll", L"1.dll", FALSE))
    {
        auto const lastError = GetLastError();
        std::cout << "CopyFileW() failed, error = " << lastError << std::endl;
    }

    BoxedAppSDK_RemoteProcess_LoadLibraryW(pid, L"1.dll");
}
