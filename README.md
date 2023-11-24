# ICS_CS_Infinite-Loopers.
# ATM Machine

This simple C program is a console-based ATM machine application. It allows users to perform basic banking operations such as checking balance, depositing money, withdrawing money, changing PIN, and viewing the last three transactions.
## Dependencies

To run this program, ensure that you have the following dependencies installed on your system:

1. **C Compiler:**
   - You need a C compiler installed on your system. If you don't have one, you can use GCC (GNU Compiler Collection). For Windows users, MinGW-w64 or a similar tool can provide the GCC compiler.

2. **Operating System:**
   - This code is platform-independent and should work on various operating systems like Windows, Linux, and macOS.

3. **Standard Input/Output:**
   - The program uses standard input and output functions (`printf`, `scanf`). Ensure that you have access to a console or terminal for input and output.

4. **File System Access:**
   - The program reads and writes files to simulate an account system. Make sure you have permission to read and write files in the directory where the program is executed.

## Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/damanish/ICS_CS_Infinite-Loopers.git
2. **Compile the Code:**
   
   gcc b23cs1057_b23me1040_b23cm1023_b23mt1009.c -o ATM_machine
3. **Run the program:**
   
   ./ATM_machine
Features
1. Create a New Account
If no existing account is found, the program prompts the user to create a new account by providing a username, PIN(make sure that pin is 4 digits), and initial balance.
2. Login to Existing Account:
Users can log in to their existing account by entering their username and PIN.
3. Operations Menu:
After successful login, users are presented with a menu to choose from various banking operations.
4. Check Balance:
Users can check their account balance.
5. Deposit Money:
Users can deposit money into their account.
6. Withdraw Money:
Users can withdraw money from their account, provided they have sufficient balance.
7. Change PIN:
Users can change their PIN after successful verification.
8. View Last Three Transactions:
Users can view the details of their last three transactions.
9. Exit
Users can exit the program.
How to Use
Run the program and enter your username.
If an existing account is found, enter your PIN to access the main menu.
Choose an option from the menu by entering the corresponding number.
Follow the prompts to complete each operation.
