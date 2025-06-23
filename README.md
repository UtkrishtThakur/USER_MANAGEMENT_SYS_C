A simple console-based user management system written in C that supports basic user registration and login functionality. This project demonstrates how to handle user input securely (including masked password entry) and use structures to manage user credentials in memory.

📌 Features
Register up to 10 users

Login with a registered username and password

Password input is masked (hidden with *)

Uses C structures and basic I/O functions

Simple command-line interface

🛠️ Technologies Used
Language: C

Compiler: GCC / MinGW (for Windows)

Header Files: stdio.h, string.h, conio.h

🚀 How to Run
Compile the Code:

bash
Copy code
gcc user_management.c -o user_management
Run the Executable:

bash
Copy code
./user_management
📄 Program Structure
user: Struct to store username and password.

registration(): Registers a new user by storing their credentials.

login(): Authenticates users by checking stored credentials.

input_password(): Securely takes masked password input using getch().

fix_fgetsprob(): Cleans newline character from fgets() input.

🧠 Sample Usage
markdown
Copy code
Welcome to the user management system!
1. Register
2. Login
3. Exit
Select your choice:
If you choose 1, you can create a new account.

If you choose 2, you can login using your credentials.

On successful login, you will see:

pgsql
Copy code
Login successful! Welcome <username>
You can now access the system
⚠️ Limitations
Only stores up to 10 users.

Credentials are stored in memory only (not saved to file).

No encryption for passwords (for educational use only).

🧪 Future Improvements
Store credentials in a file for persistence.

Add password rules (length, symbols, etc.).

Encrypt passwords using hashing.

Implement account deletion or update features.

🙌 Author
Made by Utkrisht Thakur as a simple C practice project.

Let me know if you'd like this README in a downloadabl
