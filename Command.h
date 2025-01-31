/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This file serves as the header file for Command.cpp.
    It defines the Command class, which is the base class for all commands as well as its derived classes,
    including DEC, LDA, LDI, STR, XCH, JMP, JZS, ADD, SUB, and HLT commands.
    Each command contains an execute method that takes a Hardware object and an argument string.
*/

#ifndef COMMAND_H
#define COMMAND_H

#include "Hardware.h"
// Base class for commands
class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Hardware& hardware, string argument) = 0;
};

/* DECcommand Class
 * Declares a symbolic variable consisting of a sequence of letters (e.g., sum).
 * The variable is stored at an available location in data memory.
 */
class DECCommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* LDACommand Class
 * Loads word at data memory address of symbol into the accumulator.
 */
class LDACommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* LDICommand Class
 * Loads the integer value into the accumulator register. The value could be a negative number/
 */
class LDICommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* STRCommand Class
 * Stores content of accumulator into data memory at address of symbol.
 */
class STRCommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* XCHCommand Class
 * Exchanges the content registers A and B
 */
class XCHCommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* JMPCommand Class
 * Transfers control to instruction at address number in program memory
 */
class JMPCommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* JZSCommand Class
 * Transfers control to instruction at address number if the zero-result bit is set
 */
class JZSCommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* AddCommand Class
 * Adds the content of registers A and B. The sum is stored in A.
 * The overflow bit is set or cleared as needed.
 * However, if the sum out of range for 16-bit numbers, this operation has no effect
*/
class ADDCommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* SUBCommand Class
 * The content of register B is subtracted from A.
 * The difference is stored in A.
 * The overflow bit is set or cleared as needed.
 * If the sum out of range for 16-bit numbers, this operation has no effect
 */
class SUBCommand : public Command {
public:
    void execute(Hardware& hardware, string argument) override;
};

/* HLTCommand Class
 * Terminates program execution
 * Class not necessary. Program termination is handled in Hardware.cpp
 */



#endif //COMMAND_H
