/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This file serves as the cpp file for Command.h.
    It contains the implementation of the Command class and its derived classes,
    including DEC, LDA, LDI, STR, XCH, JMP, JZS, ADD, SUB, and HLT commands.
    Each command contains an execute method that takes a Hardware object and an argument string.
    Descriptions of each command are provided in the comments above each class.
*/

#include "Command.h"
#include "Hardware.h"


/* DECcommand Class
 * Declares a symbolic variable consisting of a sequence of letters (e.g., sum).
 * The variable is stored at an available location in data memory.
 */
void DECCommand::execute(Hardware& hardware, string symbol) {
    for (int i = 128; i < 256; ++i) {
        if (hardware.memory[i] == nullptr) {
            hardware.memory[i] = new DataMem(symbol, 0);
            return;
        }
    }
}

/* LDACommand Class
 * Loads word at data memory address of symbol into the accumulator.
 */
void LDACommand::execute(Hardware& hardware, string symbol)  {
    hardware.loadFrom(symbol);
}

/* LDICommand Class
 * Loads the integer value into the accumulator register. The value could be a negative number/
 */
void LDICommand::execute(Hardware& hardware, string value)  {
    hardware.accumulator = stoi(value);
}

/* STRCommand Class
 * Stores content of accumulator into data memory at address of symbol.
 */
void STRCommand::execute(Hardware& hardware, string symbol)  {
    hardware.storeAt(symbol);
}

/* XCHCommand Class
 * Exchanges the content registers A and B
 */
void XCHCommand::execute(Hardware& hardware, string argument) {
    int temp = hardware.accumulator;
    hardware.accumulator = hardware.data_register;
    hardware.data_register = temp;
}

/* JMPCommand Class
 * Transfers control to instruction at address number in program memory
 */
void JMPCommand::execute(Hardware& hardware, string number)  {
    hardware.program_counter = stoi(number)-1;
}

/* JZSCommand Class
 * Transfers control to instruction at address number if the zero-result bit is set
 */
void JZSCommand::execute(Hardware& hardware, string number)  {
    if (hardware.zero_bit == 0) {
        hardware.program_counter = stoi(number)-1;
    }
}

/* AddCommand Class
 * Adds the content of registers A and B. The sum is stored in A.
 * The overflow bit is set or cleared as needed.
 * However, if the sum out of range for 16-bit numbers, this operation has no effect
*/
void ADDCommand::execute(Hardware& hardware, string argument)  {
    int sum = hardware.accumulator + hardware.data_register;
    if (sum >= -32768 && sum <= 32767) {
        hardware.accumulator = sum;
    }
    if (sum == 0) {
        hardware.zero_bit = 0;
    }
    else {
        hardware.zero_bit = 1;
    }
}

/* SUBCommand Class
 * The content of register B is subtracted from A.
 * The difference is stored in A.
 * The overflow bit is set or cleared as needed.
 * If the sum out of range for 16-bit numbers, this operation has no effect
 */
void SUBCommand::execute(Hardware& hardware, string argument)  {
    int result = hardware.accumulator - hardware.data_register;
    if (result >= -32768 && result <= 32767) {
        hardware.accumulator = result;
    }
    if (result == 0) {
        hardware.zero_bit = 0;
    }
    else {
        hardware.zero_bit = 1;
    }
}