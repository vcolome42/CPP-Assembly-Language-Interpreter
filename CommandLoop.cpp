/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This file serves as the cpp file for CommandLoop.h.
    It contains the implementation of the CommandLoop class, which handles user input and executes commands.
    It provides methods to run the entire program, step through each instruction, and halt/quit the program.
*/

#include "CommandLoop.h"
#include <iostream>

using namespace std;


CommandLoop::CommandLoop(Hardware& hw)
    : hardware(hw),
    inLoop(true),
    printStats(true),
    runInProgress(false) {}

void CommandLoop::runLoop(int programLength) {
    while (inLoop) {
        // Check if the program counter has reached the program length
        if (hardware.program_counter == programLength) {
            cout << "Program has finished executing. Enter q to quit. ";
            string exitProgram;
            cin >> exitProgram;

            while (exitProgram != "q") {
                cout << "Invalid input. Please enter q to quit. ";
                cin >> exitProgram;
            }
            inLoop = false;
            break;
        }

        string input;
        cout << "Please enter a character (a, s, or q): ";
        cin >> input;

        if (input.length() != 1) {
            cout << "Invalid input. Please enter a character (a, s, or q)." << endl;
            continue;
        }

        char loopCommand = input[0];
        switch (loopCommand) {
            case 'a':
                runProgram(programLength);
                printStats = false;
                break;
            case 's':
                runInstruction(programLength);
                break;
            case 'q':
                inLoop = false;
                break;
            default:
                cout << "Invalid input. Please enter a character (a, s, or q)." << endl;
        }
    }
}

void CommandLoop::runProgram(int programLength) {
    runInProgress = true;
    int instructionsExecuted = 0;  // Counter to track the number of instructions

    while (runInProgress && hardware.program_counter != programLength) {
        hardware.runNextInstruction(*this);
        instructionsExecuted++;  // Increment the instruction counter

        // Check if 1000 instructions have been executed
        if (instructionsExecuted >= 1000) {
            char loopCheck;
            cout << "Your program is in an infinite loop. Would you like to continue? (Y/N): ";
            cin >> loopCheck;

            if (loopCheck == 'N' || loopCheck == 'n') {
                runInProgress = false;  // Stop the program if the user chooses not to continue
                break;
            }
            else if (loopCheck == 'Y' || loopCheck == 'y') {
                continue;
            }

            // Reset the counter to avoid prompting every 1000 instructions
            instructionsExecuted = 0;
        }
    }

    // Print stats after the program finishes (only once)
    if (printStats) {
        hardware.printAll();
    }
}

void CommandLoop::runInstruction(int programLength) {
    if (hardware.program_counter != programLength) {
        hardware.runNextInstruction(*this);
        hardware.printAll();
    }
}

void CommandLoop::haltProgram() {
    runInProgress = false;
}