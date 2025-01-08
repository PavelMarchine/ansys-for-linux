# Ansys for Linux

## Overview

Ansys for Linux is a project dedicated to adapting Ansys, the renowned engineering simulation software, to run natively on Linux systems. This project ensures that engineers and researchers can utilize the power of Ansys directly on Linux, taking advantage of the platform's performance, stability, and flexibility.

## Key Features

- **Native Execution on Linux:** Fully adapted to run on Linux without the need for compatibility layers like Wine or virtual machines.
- **Optimized Performance:** Leverages Linux's efficiency for faster computation and simulation processes.
- **Seamless Integration:** Works well with popular Linux distributions such as Ubuntu, Fedora, and CentOS.
- **OpenGL Support:** Utilizes Linux's graphics capabilities for high-quality simulation visualizations.
- **Command-Line and GUI Options:** Offers both terminal-based and graphical user interfaces for user flexibility.

## Supported Distributions

The following Linux distributions are officially supported:

- Ubuntu 20.04 and later
- Fedora 35 and later
- CentOS 8 and later
- Debian 11 and later

Other distributions may work but are not officially tested.

## Prerequisites

Before installing Ansys for Linux, ensure you have the following:

- A 64-bit Linux operating system
- At least 16 GB of RAM (32 GB or more recommended for large simulations)
- A multi-core CPU (Intel or AMD, supporting SSE2 or later instructions)
- An OpenGL-compatible GPU for graphical simulations
- Dependencies: 
  - GCC/G++ (version 9 or later)
  - Python 3.8 or later
  - OpenSSL libraries

## Installation

```bash
bash build.sh
make 
make install
```

Verify installation
   
```bash
ansys -version
```

## Usage

### Command-Line Interface (CLI)

Run simulations directly from the terminal:
```bash
ansys -input simulation_file.inp -output results.out
```

### Graphical User Interface (GUI)

Start the GUI:
```bash
ansys -gui
```


## Troubleshooting


- **Graphics Issues:**
  Ensure your GPU drivers are up-to-date and OpenGL is enabled.

- **Performance Problems:**
  Use `htop` or `top` to monitor system resources and ensure adequate memory and CPU cores are available.



## Acknowledgments

- The Ansys development team for creating such powerful engineering tools.
- The open-source community for their invaluable resources and support.

## Contact

For support or inquiries, please email kernel at firemail.cc.

---

Enjoy seamless simulations on Linux with Ansys for Linux!
