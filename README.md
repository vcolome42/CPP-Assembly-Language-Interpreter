# CPP-Assembly-Language-Interpreter
An assembly language interpreter (ALI) for the Simple Assembly Language (SAL)

This ALI project was created for my Object-Oriented Languages and Environments class, with a primary focus on exploring multiple inheritance and other features of object-oriented programming.

To use the program, simply follow these steps:

### STEP 1: Executing the program

- Ensure the Instructions folder contains a .txt file with instructions written in the SAL. The program will only read .txt files from this folder. Three .txt files are present in the folder by default. The simple.txt file runs a basic set of instructions to add 10 and 20 together to get a result of 30. The input.txt file runs a slightly more advanced set of instructions to create a loop where the value 3 is added for a total of four times to get a result of 12. The infinite.txt file is exactly the same as input.txt except that JZS 23 has been changed to JZS 21, resulting in an infinite loop. 

  <img width="520" alt="image" src="https://github.com/user-attachments/assets/687645db-e80b-49b2-bb0b-4c8c072b303d" />

- Double-click on ALI.exe in the directory

![image](https://github.com/user-attachments/assets/a40a6cf3-0b1b-4360-9772-551f9cd061d8)

- Upon executing the program, a command prompt window should appear

<img width="629" alt="image" src="https://github.com/user-attachments/assets/e1a6cc11-c761-4654-a9ac-ffedaf8996a9" />

### STEP 2: Navigating the program

- The program should display a short guide on how to use the program. Enter the name of the .txt file you would like to use from the Instructions folder. In this case, we will use simple.txt. After entering our chosen filename, we have the option of executing all instructions from the file with 'a', executing instructions one by one by pressing 's' until we have reached the end of the program, or quitting the program and closing the window with 'q'. Choosing either 'a' or 's' will also output the state of the ALI's data memory, including variable names (shown as Symbols), values, and their location in memory.  In this program, the ALI's memory is divided into two parts: Program Memory, which occupies memory cells 0-127 and is reserved for storing instructions derived from the .txt files, and Data Memory, located within memory cells 128-255, which holds variables and their respective values. For ease of viewing and simplicity, only the Data Memory is output to the console.

<img width="370" alt="image" src="https://github.com/user-attachments/assets/bae80609-5cc8-4999-8e82-368490993b49" />

- When the program has finished executing all instructions, simply enter 'q' to exit the program.

### STEP 3 (Optional): Viewing the Program Memory

- In the event that you'd actually like to have the Program Memory output to the console, you can find the code for that section at the end of Hardware.cpp in the "printAll()" method. Simply uncomment the code there and rebuild the program.

<img width="421" alt="image" src="https://github.com/user-attachments/assets/b9a95318-21aa-47f4-8d57-171c3c681b69" />
<img width="402" alt="image" src="https://github.com/user-attachments/assets/b1054c51-4fba-4bcd-ab02-cf0782ea0a2b" />











