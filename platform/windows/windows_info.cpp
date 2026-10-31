
#include <windows.h>
#include <lmcons.h>
#include <string>

namespace WindowsInfo
{
    std::string getWindowsVersion()
    {
        HKEY key;

        if (RegOpenKeyExA(
                HKEY_LOCAL_MACHINE,
                "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
                0,
                KEY_READ,
                &key) != ERROR_SUCCESS)
        {
            return "Unknown";
        }

        char productName[256] = {};
        char displayVersion[100] = {};

        DWORD size = sizeof(productName);

        RegQueryValueExA(
            key,
            "ProductName",
            nullptr,
            nullptr,
            reinterpret_cast<LPBYTE>(productName),
            &size);

        size = sizeof(displayVersion);

        RegQueryValueExA(
            key,
            "DisplayVersion",
            nullptr,
            nullptr,
            reinterpret_cast<LPBYTE>(displayVersion),
            &size);

        RegCloseKey(key);

        return std::string(productName) + " " + displayVersion;
    }

    std::string getComputerName()
    {
        char name[MAX_COMPUTERNAME_LENGTH + 1] = {};
        DWORD size = sizeof(name);

        if (GetComputerNameA(name, &size))
            return name;

        return "Unknown";
    }

    std::string getUsername()
    {
        char username[256] = {};
        DWORD size = sizeof(username);

        if (GetUserNameA(username, &size))
            return username;

        return "Unknown";
    }

    std::string getArchitecture()
    {
        SYSTEM_INFO info;
        GetNativeSystemInfo(&info);

        switch (info.wProcessorArchitecture)
        {
        case PROCESSOR_ARCHITECTURE_AMD64:
            return "x64";

        case PROCESSOR_ARCHITECTURE_ARM64:
            return "ARM64";

        case PROCESSOR_ARCHITECTURE_INTEL:
            return "x86";

        default:
            return "Unknown";
        }
    }
}
