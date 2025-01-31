/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode.

    This file serves as the cpp file for Hardware.h.
    It contains the implementation of the Hardware class, which represents the hardware of the ALI.
    It provides methods to execute commands, run the next instruction, and print the current state of the hardware.
*/

#include "Hardware.h"
#include "MemoryType.h"
#include "Command.h"
#include <string>

Hardware::Hardware()
    : accumulator(0), // REGISTER A
    data_register(0), // REGISTER B
    program_counter(0),
    zero_bit(0) {
    for (int i = 0; i < 256; ++i) {
        memory[i] = nullptr;
    }
}

Hardware::~Hardware() {
    for (int i = 0; i < 256; ++i) {
        delete memory[i];
    }
}

/*
 * Called by STRCommand to store accumulator to data in memory
 */
void Hardware::storeAt(string symbol) {
    for (int i = 128; i < 256; ++i) {
        if (memory[i] != nullptr) {
            DataMem* dataMem = dynamic_cast<DataMem*>(memory[i]);
            if (dataMem != nullptr && dataMem->symbol == symbol) {
                dataMem->data = accumulator;
                return;
            }
        }
    }
}

/*
 * Called by LDACommand to retrieve data to accumulator
 */
void Hardware::loadFrom(string symbol) {
    for (int i = 128; i < 256; ++i) {
        if (memory[i] != nullptr) {
            DataMem* dataMem = dynamic_cast<DataMem*>(memory[i]);
            if (dataMem != nullptr && dataMem->symbol == symbol) {
                accumulator = dataMem->data;
                return;
            }
        }
    }
}

Opcode Hardware::getOpcode(string& strOpcode) {
    if (strOpcode == "DEC") return DEC;
    if (strOpcode == "LDA") return LDA;
    if (strOpcode == "LDI") return LDI;
    if (strOpcode == "STR") return STR;
    if (strOpcode == "XCH") return XCH;
    if (strOpcode == "JMP") return JMP;
    if (strOpcode == "JZS") return JZS;
    if (strOpcode == "ADD") return ADD;
    if (strOpcode == "SUB") return SUB;
    if (strOpcode == "HLT") return HLT;
    return UNKNOWN;
}

void Hardware::executeCommand(string& strOpcode, string& arg, CommandLoop& commandLoop) {
    switch (getOpcode(strOpcode)) {
        case DEC: {
            DECCommand decCommand;
            decCommand.execute(*this, arg);
            break;
        }
        case LDA: {
            LDACommand ldaCommand;
            ldaCommand.execute(*this, arg);
            break;
        }
        case LDI: {
            LDICommand ldiCommand;
            ldiCommand.execute(*this, arg);
            break;
        }
        case STR: {
            STRCommand strCommand;
            strCommand.execute(*this, arg);
            break;
        }
        case XCH: {
            XCHCommand xchCommand;
            xchCommand.execute(*this, arg);
            break;
        }
        case JMP: {
            JMPCommand jmpCommand;
            jmpCommand.execute(*this, arg);
            break;
        }
        case JZS: {
            JZSCommand jzsCommand;
            jzsCommand.execute(*this, arg);
            break;
        }
        case ADD: {
            ADDCommand addCommand;
            addCommand.execute(*this, arg);
            break;
        }
        case SUB: {
            SUBCommand subCommand;
            subCommand.execute(*this, arg);
            break;
        }
        case HLT: {
            commandLoop.haltProgram();
            break;
        }
        default:
            cout << "Error: Unknown opcode '" << strOpcode << "' encountered." << endl;
        break;
    }
}

void Hardware::runNextInstruction(CommandLoop& commandLoop) {
    if (program_counter >= 128) {
        cout << "Error: Program counter out of bounds." << endl;
        return;
    }
    if (memory[program_counter] != nullptr) {
        // Check if the current memory entry is of type Instruction
        Instruction* instr = dynamic_cast<Instruction*>(memory[program_counter]);

        if (instr != nullptr) {
            string strOpcode = instr->opcode;
            string argument = instr->argument;
            // cout << "Executing " << strOpcode << " with argument " << argument << endl;
            executeCommand(strOpcode, argument, commandLoop);
            program_counter++;
        }
    }
}

void Hardware::printAll() {
    cout<< endl;
    cout << "Program memory" << endl;
    cout << "--------------" << endl;

    // Only print non-null entries in the first 128 memory locations
    // for (int i = 0; i < 128; ++i) {
    //     if (memory[i] != nullptr) {
    //         cout << i << ": ";
    //         memory[i]->print();
    //     }
    // }
    // cout<< endl;

    cout<< endl;
    cout << "Data memory" << endl;
    cout << "--------------" << endl;

    // Only print non-null entries in the last 128 memory locations
    for (int i = 128; i < 256; ++i) {
        if (memory[i] != nullptr) {
            cout << i << ") ";
            memory[i]->print();
        }
    }
    cout<< endl;

    cout << "Accumulator: " << accumulator << endl;
    cout << "Data register: " << data_register << endl;
    cout << "Program counter: " << program_counter << endl;
    cout << "Zero bit: " << zero_bit << endl;
    cout << endl;
}
