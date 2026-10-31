#include "vex/terminal.hpp"
#include <iostream>
#include <windows.h>

namespace Terminal
{

    const std::string RESET = "\033[0m";
    const std::string CYAN = "\033[96m";
    const std::string GREEN = "\033[92m";
    const std::string YELLOW = "\033[93m";
    const std::string RED = "\033[91m";
    const std::string WHITE = "\033[97m";

    void initialize()
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode = 0;

        if (GetConsoleMode(console, &mode))
        {
            SetConsoleMode(console, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        }
    }

    void reset()
    {
        std::cout << RESET;
    }

    void print(const std::string &text)
    {
        std::cout << WHITE << text << RESET;
    }

    void success(const std::string &text)
    {
        std::cout << GREEN << "[+] " << text << RESET << '\n';
    }

    void warning(const std::string &text)
    {
        std::cout << YELLOW << "[!] " << text << RESET << '\n';
    }

    void error(const std::string &text)
    {
        std::cout << RED << "[-] " << text << RESET << '\n';
    }

    void heading(const std::string &text)
    {
        std::cout << '\n'
                  << CYAN << "  " << text << RESET << '\n';
        std::cout << CYAN << "  --------------------------------" << RESET << '\n';
    }

}