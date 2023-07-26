// TargetApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <windows.h>

int main()
{
    std::cout << "PID is " << GetCurrentProcessId() << "\n";
    std::cout << "Press ENTER to exit\n";
    _getch();
}
