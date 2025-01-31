/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This file serves header file for CommandLoop.cpp.
    It defines the CommandLoop class, which handles user input and executes commands.
    It provides methods to run the entire program, step through each instruction, and halt/quit the program.
*/

#ifndef COMMANDLOOP_H
#define COMMANDLOOP_H
#include "Hardware.h"

class Hardware;
class CommandLoop {
private:
    Hardware& hardware;
    int index;
    bool inLoop;
    bool printStats;
    bool runInProgress;

public:
    CommandLoop(Hardware& h);
    void runLoop(int programLength);
    void runProgram(int programLength);
    void runInstruction(int programLength);
    void haltProgram();
};

#endif //COMMANDLOOP_H
