# 🛠️ **MiniLibC - Custom C Library in Assembly** 🛠️

Welcome to **MiniLibC**, my project where I dive into low-level programming by recoding essential functions from the C standard library using **x86-64 Assembly**. This is my journey to better understand how these functions work at a machine level and to create my own version of the standard library.

## Table of Contents 📍

1. [Project Overview 💡](#project-overview-💡)
2. [Objective 🎯](#objective-🎯)
3. [Functions Implemented 📝](#functions-implemented-📝)
4. [Bonus Features 🌟](#bonus-features-🌟)
5. [Compilation ⚙️](#compilation-⚙️)
6. [Contributors 👥](#contributors-👥)

## Project Overview 💡

This project aims to recode several essential functions from the C standard library using **assembly language**. By implementing these functions in assembly, I can better understand the inner workings of low-level system programming and how compilers and CPUs interact with code at the instruction level.

## Objective 🎯

The main goal is to replace standard C functions with my own **x86-64 Assembly** versions, wrapped in a dynamic library (`libasm.so`). It deepens my understanding of memory management, string manipulation, and system calls, while ensuring the custom library works seamlessly as a drop-in replacement for the standard C library.

## Functions Implemented 📝

Here’s a list of the core functions I've successfully recoded in assembly:

- [x] `strlen` – Calculate the length of a string.
- [x] `strchr` – Locate the first occurrence of a character in a string.
- [x] `strrchr` – Locate the last occurrence of a character in a string.
- [x] `memset` – Fill a block of memory with a specific byte.
- [x] `memcpy` – Copy memory from one location to another.
- [x] `strcmp` – Compare two strings lexicographically.
- [x] `memmove` – Safely move memory blocks, even if they overlap.
- [x] `strncmp` – Compare two strings up to a specified number of characters.
- [x] `strcasecmp` – Compare two strings without considering case.
- [x] `strstr` – Locate a substring within another string.
- [x] `strpbrk` – Find the first occurrence of any of a set of characters in a string.
- [x] `strcspn` – Get the length of a segment that doesn't contain certain characters.

## Bonus Features 🌟

In addition to the core functions, I’ve implemented a few bonus features, and there are more I’m aiming to tackle:

- [x] `index` – Alias for `strchr`.
- [x] `rindex` – Alias for `strrchr`.
- [x] `memfrob` – XORs a memory block with the value `42` (just for fun!).
- [x] `atoi` – Converts a string to an integer.

## Compilation ⚙️

The build system is handled with a **Makefile** that includes several useful targets for compiling and testing the project:

- `make` : Compiles all source files and builds the dynamic library `libasm.so`.
- `make clean` : Removes the object files created during compilation.
- `make fclean` : Cleans up all the compiled files, including `libasm.so`.
- `make tests_run` : Runs unit tests to compare the output of my assembly functions with the standard C library implementations.

## Contributors 👥

- **Main Contributor**: [MARQUES Esteban](https://github.com/Estebanmrq)
