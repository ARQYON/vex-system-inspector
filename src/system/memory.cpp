#include "vex/memory.hpp"
#include "vex/terminal.hpp"

#include <windows.h>
#include <iostream>
#include <iomanip>

namespace Memory
{

    void show()
    {
        Terminal::heading("MEMORY INFORMATION");

        MEMORYSTATUSEX memory;
        memory.dwLength = sizeof(memory);

        if (!GlobalMemoryStatusEx(&memory))
        {
            Terminal::error("Unable to retrieve memory information.");
            return;
        }

        double total = memory.ullTotalPhys / (1024.0 * 1024 * 1024);
        double available = memory.ullAvailPhys / (1024.0 * 1024 * 1024);
        double used = total - available;

        std::cout << std::fixed << std::setprecision(2);

        std::cout << "  Total RAM      : " << total << " GB\n";
        std::cout << "  Used RAM       : " << used << " GB\n";
        std::cout << "  Available RAM  : " << available << " GB\n";
        std::cout << "  RAM Usage      : " << memory.dwMemoryLoad << "%\n";
    }

}