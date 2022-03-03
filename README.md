# InChI API Complilation 

This repository contains source files from the [InChI Trust](https://www.inchi-trust.org/), which can be used to build the InChI API. 

This API consists of static and shared libraries. The tools provided here should work on Unix/macOS and Windows Platforms subject to some requirements. 

# Requirements

- [CMake](https://cmake.org/) v3.0 or later

- C++ compiler requirements
    - MacOS/Unix: g++ v9 or later
    - Windows: Visual Studio 2019 or Later

You should make sure that both CMake and a C++ compiler installed an added to your environment PATH. If you do not know how to do this, google it or ask someone who does. 

# Usage

## Unix/macOS
Make a new directory inside the repo folder and navigate into it using:

`$ mkdir build_unix` 

`$ cd build_unix` 

Run cmake using the following command to point the source (`-S`) in the top level directory and the build location (`-B`) in your current one

`$ cmake -S .. -B .`

This will generate a Makefile that you can use to build the api using 

`make` 

If that works successfully you'll have an `inchi.a` file in your build directory. 

## Windows 
Make a new directory inside the repo folder and navigate into it using:

`> mkdir build_win` 

`> cd build_win` 

Run cmake using the following command to point the source (`-S`) in the top level directory and the build location (`-B`) in your current one

`> cmake -S .. -B .`

This will generate the Visual Studio Solution Files you need too build the api. You can open the file `inchi.sln` using Visual Studio and build the solution  

If that works successfully you'll have an `inchi.lib` file in your build directory (probably under `Release/`, or `Debug/` if you didn't change to the build target to Release).

## Shared Libraries

If you run `cmake` with a flag `-DBUILD_DYNAMIC=YES` you will build both the shared and static libraries (`inchi.dll` for Windows, or `inchi.so` for Unix)