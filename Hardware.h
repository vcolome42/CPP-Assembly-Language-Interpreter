/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This file serves as the header file for Hardware.cpp.
    It defines the Hardware class, which represents the hardware of the ALI.
    It contains methods to execute commands, run the next instruction, and print the current state of the hardware.
*/

#ifndef HARDWARE_H
#define HARDWARE_H

#include "MemoryType.h"
#include "CommandLoop.h"
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class CommandLoop;
enum Opcode {
    DEC,
    LDA,
    LDI,
    STR,
    XCH,
    JMP,
    JZS,
    ADD,
    SUB,
    HLT,
    UNKNOWN
};

class Hardware {
public:
    Hardware();
    ~Hardware();
    MemoryType* memory[256];
    unordered_map<int, string> symbol_table;
    int accumulator;
    int data_register;
    int program_counter;
    int zero_bit;
    void addVariable(string variable);
    void storeAt(string varName);
    void loadFrom(string varName);
    Opcode getOpcode(string& opcode);
    void executeCommand(string& opcode, string& arg, CommandLoop& commandLoop);
    void runNextInstruction(CommandLoop& commandLoop);
    void printAll();
};




#endif //HARDWARE_H
