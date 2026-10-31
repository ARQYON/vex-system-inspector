#include "vex/diagnostics.hpp"
#include "vex/terminal.hpp"

#include <iostream>
#include <array>
#include <string>
#include <cstdlib>

namespace Diagnostics
{

    bool isAvailable(const std::string &command)
    {
        std::string check = "where " + command + " >nul 2>&1";
        return system(check.c_str()) == 0;
    }

    void show()
    {
        Terminal::heading("SYSTEM DIAGNOSTICS");

        struct Tool
        {
            std::string name;
            std::string command;
        };

        const std::array<Tool, 10> tools = {{{"GCC", "gcc"},
                                             {"G++", "g++"},
                                             {"Python", "python"},
                                             {"Node.js", "node"},
                                             {"PHP", "php"},
                                             {"Ruby", "ruby"},
                                             {"Rust", "rustc"},
                                             {"Git", "git"},
                                             {"CMake", "cmake"},
                                             {"Java", "java"}}};

        int passed = 0;

        for (const auto &tool : tools)
        {
            if (isAvailable(tool.command))
            {
                Terminal::success(tool.name + " available");
                passed++;
            }
            else
            {
                Terminal::warning(tool.name + " not found");
            }
        }

        int total = static_cast<int>(tools.size());

        std::cout << "\n  --------------------------------\n";
        std::cout << "  Total Checks : " << total << '\n';
        std::cout << "  Passed       : " << passed << '\n';
        std::cout << "  Missing      : " << total - passed << '\n';

        std::cout << "\n  RESULT: "
                  << passed << "/" << total
                  << " CHECKS PASSED\n";
    }

}