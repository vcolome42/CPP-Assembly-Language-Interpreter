/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This file serves as the header file for MemoryType.cpp.
    It defines the MemoryType class, which is a base class for both Instruction and DataMem classes.
    Instruction objects represent instructions with an opcode and an optional argument, while DataMem objects represent data with a symbol and a value.
    It provides the implementation of the print function for both classes.
*/

#ifndef MEMORYTYPE_H
#define MEMORYTYPE_H

#include <iostream>
#include <string>

using namespace std;

// Base class to wrap different data types for use in vector
class MemoryType {
public:
    virtual ~MemoryType() = default;
    virtual void print() const = 0;  // Pure virtual function
};

// Wrapper class for ALI program memory instruction type
class Instruction : public MemoryType {
public:
    string opcode;
    string argument;
    Instruction(const string& op = "", const string& arg = "");
    void print() const override;
};

// Wrapper class for ALI data memory type
class DataMem : public MemoryType {
public:
    string symbol;
    int data;

    DataMem(const string& sym = "", int value = 0);

    void print() const override;
};

#endif  // MEMORYTYPE_H

