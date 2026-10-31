#include "vex/network.hpp"
#include "vex/terminal.hpp"

#include <windows.h>
#include <iphlpapi.h>
#include <iostream>
#include <iomanip>
#include <cstring>

#pragma comment(lib, "iphlpapi.lib")

namespace Network
{
    void show()
    {
        Terminal::heading("NETWORK INFORMATION");
        ULONG size = 0;
        GetAdaptersInfo(nullptr, &size);
        IP_ADAPTER_INFO *adapters =
            reinterpret_cast<IP_ADAPTER_INFO *>(new BYTE[size]);
        if (GetAdaptersInfo(adapters, &size) == NO_ERROR)
        {
            IP_ADAPTER_INFO *adapter = adapters;
            while (adapter)
            {
                if (strcmp(adapter->IpAddressList.IpAddress.String, "0.0.0.0") == 0)
                {
                    adapter = adapter->Next;
                    continue;
                }
                std::cout << "\n  Adapter : " << adapter->Description << '\n';
                std::cout << "  IP      : "
                          << adapter->IpAddressList.IpAddress.String << '\n';
                std::cout << "  Gateway : "
                          << adapter->GatewayList.IpAddress.String << '\n';
                std::cout << "  MAC     : ";
                for (UINT i = 0; i < adapter->AddressLength; i++)
                {
                    if (i)
                        std::cout << "-";
                    std::cout << std::hex << std::uppercase
                              << std::setw(2) << std::setfill('0')
                              << static_cast<int>(adapter->Address[i]);
                }
                std::cout << std::dec << '\n';
                adapter = adapter->Next;
            }
        }
        else
        {
            Terminal::error("Unable to retrieve network information.");
        }
        delete[] reinterpret_cast<BYTE *>(adapters);
    }

}