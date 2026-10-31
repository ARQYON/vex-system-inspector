#include "vex/banner.hpp"
#include "vex/terminal.hpp"

namespace Banner {

    void show() {
        Terminal::print(R"(
 __      _______  __
 \ \    / / ____| \ \
  \ \  / /| |__    \ \
   \ \/ / |  __|    > >
    \  /  | |____  / /
     \/   |______|/_/

)");

        Terminal::heading("VEX SYSTEM INSPECTOR");
        Terminal::print("  Engineered by ARQYON\n");
        Terminal::print("  Version 1.0.0\n\n");
    }

}