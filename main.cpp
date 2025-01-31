/*
    Created by Victor Colome on 11/27/2024.
    Operating System: Windows 11
    IDE Used: Developed in CLion 2024.2.1, modified in VSCode

    This file serves as the main entry point for the Assembly Language Interpreter (ALI).
    It initializes the hardware, reads the program from a file, stores instructions from the file into memory, and starts the command loop.
*/

#include "MemoryType.h"
#include "Hardware.h"
#include "CommandLoop.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int readFile(const string& filename, Hardware& hardware) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file!" << endl;
        return 0;
    }

    string line;
    int count = 0;

    // Iterate through each line of the file and process it
    while (getline(file, line) && count < 128) {  // Limit to 128 entries
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string opcode, argument;
        ss >> opcode;  // Read the opcode

        // If there's an argument, read it as well
        if (ss >> argument) {
            // Create Instruction with both opcode and argument
            hardware.memory[count] = new Instruction(opcode, argument);
        } else {
            // Create Instruction with just the opcode
            hardware.memory[count] = new Instruction(opcode, "");
        }

        count++;
    }

    file.close();
    return count;
}


int main() {
    Hardware hardware;
    CommandLoop commandLoop(hardware);
    string filename;
    int programLength = 0;
    cout << "Welcome the Assembly Language Interpreter!\n" 
    "After entering your filename from the Instructions folder,\n"
    "- type 'a' + ENTER to execute all instructions\n" 
    "- type 's' + ENTER to step through each instruction\n"
    "- or type 'q' to quit the program.\n" << endl;

    // Loop until a valid file is provided
    while (programLength == 0) {
        cout << "Enter the name of the file to read: ";
        cin >> filename;
        string filepath = "Instructions/" + filename;
        programLength = readFile(filepath, hardware);
        if (programLength == 0) {
            cout << "Invalid file. Please try again." << endl;
        }
    }

    commandLoop.runLoop(programLength);

    return 0;
}
