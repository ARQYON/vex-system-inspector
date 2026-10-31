#include "vex/storage.hpp"
#include "vex/terminal.hpp"

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <string>

namespace Storage
{

    void show()
    {
        Terminal::heading("STORAGE INFORMATION");

        DWORD drives = GetLogicalDrives();

        if (drives == 0)
        {
            Terminal::error("Unable to detect storage drives.");
            return;
        }

        for (char drive = 'A'; drive <= 'Z'; drive++)
        {
            if (!(drives & (1 << (drive - 'A'))))
                continue;

            std::string root = std::string(1, drive) + ":\\";

            if (GetDriveTypeA(root.c_str()) != DRIVE_FIXED)
                continue;

            ULARGE_INTEGER freeBytesAvailable;
            ULARGE_INTEGER totalBytes;
            ULARGE_INTEGER totalFreeBytes;

            if (!GetDiskFreeSpaceExA(
                    root.c_str(),
                    &freeBytesAvailable,
                    &totalBytes,
                    &totalFreeBytes))
            {
                continue;
            }

            double total = totalBytes.QuadPart / (1024.0 * 1024 * 1024);
            double free = totalFreeBytes.QuadPart / (1024.0 * 1024 * 1024);
            double used = total - free;

            double usage = total > 0
                               ? (used / total) * 100
                               : 0;

            std::cout << std::fixed << std::setprecision(2);

            std::cout << "\n  Drive          : " << drive << ":\n";
            std::cout << "  Total          : " << total << " GB\n";
            std::cout << "  Used           : " << used << " GB\n";
            std::cout << "  Free           : " << free << " GB\n";
            std::cout << "  Usage          : " << usage << "%\n";
        }
    }

}