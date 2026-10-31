#pragma once

#include <string>

namespace Terminal
{
    void initialize();
    void reset();

    void print(const std::string &text);
    void success(const std::string &text);
    void warning(const std::string &text);
    void error(const std::string &text);
    void heading(const std::string &text);
}