#include "vex/cpu.hpp"
#include "vex/terminal.hpp"

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

namespace CPU
{

    void show()
    {
        Terminal::heading("PROCESSOR INFORMATION");

        SYSTEM_INFO info;
        GetSystemInfo(&info);

        char processorName[256] = "Unknown";
        DWORD bufferSize = sizeof(processorName);

        HKEY hKey;

        if (RegOpenKeyExA(
                HKEY_LOCAL_MACHINE,
                "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                0,
                KEY_READ | KEY_WOW64_64KEY,
                &hKey) == ERROR_SUCCESS)
        {

            RegQueryValueExA(
                hKey,
                "ProcessorNameString",
                nullptr,
                nullptr,
                reinterpret_cast<LPBYTE>(processorName),
                &bufferSize);

            RegCloseKey(hKey);
        }

        std::cout << "  Processor      : " << processorName << '\n';
        std::cout << "  Logical Cores  : "
                  << info.dwNumberOfProcessors << '\n';
    }

}