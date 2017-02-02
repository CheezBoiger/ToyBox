# ToyBox Compiler
ToyBox is a compiler for a toy programming language, created out of the blues by Dr. Dominick Atansio for
CS411 - Compilers and Interpreters. This is actually for our project 1, and soon to follow others.


# To Setup
Setting up Toybox is relatively simple, however you will need the following build tool in order to successfully
build this project:

  - CMake (the latest version)

What's convenient about CMake is that it builds our C (or C++) project into the build script depending on the compiler, whether it
be gcc, g++, clang, mingw, and/or visual C. Not only this, but CMake is widely compatible and supported by many popular IDEs. 

Simply go to cmake.org and click on download on the top right of your browser window. Select the appropriate binary installer
on your specified operating system (cmake is cross compatible). install cmake once ready.

After installation, cmake should be set in your PATH set for your command line/terminal, so all you simply need to do is type the
command:

```
cmake path/to/CMakeLists.txt/dir
```
where "cmake" is the command to run the CMake build script, and the path is the directory of where the CMakeLists.txt file is at, that
you wish to build. This **CMakeLists.txt** file is the main build script that CMake needs to use in order to build the project into the
right build script (for linux, cmake builds Toybox using Unix (or GNU depending on your distro) Makefiles, and for Windows, cmake builds into visual studio .sln).

**Keep in mind, cmake will build in the current directory that the user is in prior to executing the tool!**

Once you know this much about CMake, you are ready to build Toybox!

# To Build This Project
Navigate to the Toybox root directory "which is basically the Toybox directory" and create a new folder called "build".
```
path/to/Toybox/ [user]~$ mkdir build
```
Finally traverse into the "build" folder and use the command:
```
cmake ../
```
since cmake will build the project in the directory of where the user is currently at, and our CMakeLists.txt target is in the root directory, we need to
tell cmake to navigate back to find the build script. This will then build Toybox into a Makefiles script for linux, or .sln file for Windows.**IF** on linux,
after you have executed cmake command, simply type:
```
make
```
and Toybox will compile! After successful compilation, to Run a test, type the command
```
./toybox <../config.in
```
to run the sample file into the Toybox Compiler.