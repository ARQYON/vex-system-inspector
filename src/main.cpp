#include "vex/banner.hpp"
#include "vex/terminal.hpp"
#include "vex/system.hpp"
#include "vex/cpu.hpp"
#include "vex/memory.hpp"
#include "vex/storage.hpp"
#include "vex/developer.hpp"
#include "vex/diagnostics.hpp"
#include "vex/network.hpp"

#include <iostream>
#include <string>

void showHelp()
{
    std::cout << "\nVEX SYSTEM INSPECTOR\n\n"
                 "Usage: vex [option]\n\n"
                 "  --all          Complete system inspection\n"
                 "  --system       System information\n"
                 "  --cpu          CPU information\n"
                 "  --memory       Memory information\n"
                 "  --disk         Storage information\n"
                 "  --dev          Developer environment\n"
                 "  --diagnostics  System diagnostics\n"
                 "  --help         Show help\n"
                 "  --version      Show version\n\n";
}

int main(int argc, char *argv[])
{
    Terminal::initialize();
    std::string option = argc > 1 ? argv[1] : "--all";
    if (option == "--help")
    {
        showHelp();
        return 0;
    }

    if (option == "--version")
    {
        std::cout << "VEX System Inspector v1.0.0\n";
        return 0;
    }

    Banner::show();
    if (option == "--all")
    {
        System::show();
        CPU::show();
        Memory::show();
        Storage::show();
        Developer::show();
        Diagnostics::show();
        Network::show();
    }
    else if (option == "--system")
        System::show();
    else if (option == "--cpu")
        CPU::show();
    else if (option == "--memory")
        Memory::show();
    else if (option == "--disk")
        Storage::show();
    else if (option == "--dev")
        Developer::show();
    else if (option == "--diagnostics")
        Diagnostics::show();
    else if (option == "--network")
        Network::show();
    else
    {
        Terminal::error("Unknown option: " + option);
        showHelp();
        return 1;
    }

    return 0;
}