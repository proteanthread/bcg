# BASIC Computer Games - C89 Port

This repository contains a C89 (ANSI C) port of the classic GW-BASIC games from **David Ahl's "BASIC Computer Games"** and **"More BASIC Computer Games"** originally published by Creative Computing.

The original games were written in BASIC and have been ported over to strictly compliant C89, ensuring they compile and run on a variety of platforms including Linux (GCC), Windows (MSVC), and FreeDOS (Open Watcom).

## Background & History

* [BASIC Computer Games on Archive.org](https://archive.org/details/ahl-1978-basic-computer-games)
* [BASIC Computer Games Wikipedia Page](https://en.wikipedia.org/wiki/BASIC_Computer_Games)
* [YouTube Video Documentary](https://www.youtube.com/watch?v=Qd9wpeFa3Kk)

## Build Instructions

The repository includes build scripts for multiple environments:

* **Linux (GCC)**: Run `./build_lx.sh`
* **Windows 11 (MSVC)**: Run `build_win.bat`
* **FreeDOS (Watcom)**: Run `build_fd.bat`

The source files for the C ports are located in the `src/` directory. The original GW-BASIC code is retained in the `.bas` files in the root directory and as comments directly inside the ported `.c` source files for easy reference.

## License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.
