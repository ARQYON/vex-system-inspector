# VEX - System Inspector

**A developer-oriented system inspection and diagnostics tool built with C++.**

Developed by **ARQYON**.

> Think Beyond. Engineer Everything. ⚡

## Overview

VEX is a lightweight Windows command-line utility that collects system information, inspects hardware resources, detects installed development tools, and performs basic environment diagnostics.

## Features

* **System Information:** Windows version, hostname, username, and architecture.
* **CPU Information:** Processor name and logical processor count.
* **Memory Information:** Total, used, and available RAM.
* **Storage Information:** Drive capacity, used space, and free space.
* **Network Information:** Network adapters, IP addresses, gateways, and MAC addresses.
* **Developer Environment:** Detects GCC, G++, Python, Node.js, PHP, Ruby, Rust, Git, CMake, and Java.
* **Diagnostics:** Checks developer tool availability.
* **CLI Options:** Run individual inspection modules.

## Technology Stack

* C++17
* CMake
* Windows API
* Windows Registry API
* IP Helper API

## Requirements

* Windows 10 or later
* C++17-compatible compiler
* CMake 3.16 or later
* Visual Studio Build Tools or MinGW

## Installation

Clone the repository:

```bash
git clone https://github.com/ARQYON/vex-system-inspector.git
cd vex-system-inspector
```

Configure:

```bash
cmake -S . -B build
```

Build:

```bash
cmake --build build --config Release
```

Run:

```powershell
.\build\Release\vex.exe
```

## Commands

| Command         | Description                |
| --------------- | -------------------------- |
| `--all`         | Complete system inspection |
| `--system`      | System information         |
| `--cpu`         | CPU information            |
| `--memory`      | RAM information            |
| `--disk`        | Storage information        |
| `--network`     | Network information        |
| `--dev`         | Developer environment      |
| `--diagnostics` | System diagnostics         |
| `--help`        | Display help               |
| `--version`     | Display version            |

## Project Structure

```text
vex-system-inspector/
├── include/
│   └── vex/
├── src/
│   ├── core/
│   ├── system/
│   ├── developer/
│   └── diagnostics/
├── platform/
│   └── windows/
├── docs/
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## Platform Support

| Platform      | Status    |
| ------------- | --------- |
| Windows 10/11 | Supported |
| Linux         | Planned   |
| macOS         | Planned   |

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE).

## Developer

**ARQYON**

Building the future through code, intelligence, and innovation.

Think Beyond. ⚡
