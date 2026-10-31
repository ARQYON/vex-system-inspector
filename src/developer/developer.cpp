#include "vex/developer.hpp"
#include "vex/terminal.hpp"

#include <iostream>
#include <string>
#include <array>
#include <cstdio>

namespace Developer
{

    std::string getVersion(const std::string &command)
    {
        std::array<char, 256> buffer;
        std::string result;

        FILE *pipe = _popen(command.c_str(), "r");

        if (!pipe)
        {
            return "";
        }

        if (fgets(buffer.data(), buffer.size(), pipe))
        {
            result = buffer.data();
        }

        _pclose(pipe);

        while (!result.empty() &&
               (result.back() == '\n' || result.back() == '\r'))
        {
            result.pop_back();
        }

        return result;
    }

    void checkTool(const std::string &name,
                   const std::string &command)
    {

        std::string version = getVersion(command);

        if (!version.empty())
        {
            Terminal::success(name + " : " + version);
        }
        else
        {
            Terminal::warning(name + " : Not installed");
        }
    }

    void show()
    {
        Terminal::heading("DEVELOPER ENVIRONMENT");

        checkTool("GCC", "gcc --version");
        checkTool("G++", "g++ --version");
        checkTool("Python", "python --version");
        checkTool("Node.js", "node --version");
        checkTool("PHP", "php --version");
        checkTool("Ruby", "ruby --version");
        checkTool("Rust", "rustc --version");
        checkTool("Git", "git --version");
        checkTool("CMake", "cmake --version");
        checkTool("Java", "java --version");
    }

}