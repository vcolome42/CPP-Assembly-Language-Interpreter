/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This file serves as the cpp file for MemoryType.h.
    It contains the implementation of the MemoryType class, which is a base class for both Instruction and DataMem classes.
    Instruction objects represent instructions with an opcode and an optional argument, while DataMem objects represent data with a symbol and a value.
    It provides the implementation of the print function for both classes.

*/
#include "MemoryType.h"

// Constructor for Instruction class
Instruction::Instruction(const string& op, const string& arg)
    : opcode(op), argument(arg) {}

// Print function for Instruction class
void Instruction::print() const {
    cout << "Opcode: " << opcode;
    if (!argument.empty()) {
        cout << ", Argument: " << argument;
    }
    cout << endl;
}

// Constructor for DataMem class
DataMem::DataMem(const string& sym, int value) : symbol(sym), data(value) {}

// Print function for DataMem class
void DataMem::print() const {
    cout << "Symbol: " << symbol << ", Data: " << data << endl;
}

