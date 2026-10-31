#include "vex/system.hpp"
#include "vex/terminal.hpp"

#include <iostream>
#include <windows.h>
#include <string>

namespace WindowsInfo
{
    std::string getComputerName();
    std::string getUsername();
    std::string getArchitecture();
    std::string getWindowsVersion();
}

namespace System
{

    void show()
    {
        Terminal::heading("SYSTEM INFORMATION");

        std::cout << "  Computer        : "
                  << WindowsInfo::getComputerName() << '\n';

        std::cout << "  Username        : "
                  << WindowsInfo::getUsername() << '\n';

        std::cout << "  Architecture    : "
                  << WindowsInfo::getArchitecture() << '\n';

        std::cout << "  Windows Version : "
                  << WindowsInfo::getWindowsVersion() << '\n';

        std::cout << "  Platform        : Windows\n";
    }

}