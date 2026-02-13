# Bank Management System in C

A simple yet comprehensive console-based Bank Management System built using C. This project demonstrates modular programming, file handling, and basic data structure management.

## 🚀 Features

The system supports the following banking operations:

- **Create Account**: Open a new account with Name, Mobile Number, and Aadhaar Number.
- **Deposit Money**: Add funds to an existing account.
- **Withdraw Money**: Withdraw funds from an account (checks for sufficient balance).
- **Check Balance**: View the current balance of an account.
- **Transfer Money**: Transfer funds between two accounts.
- **Display Accounts**: List all accounts with their details.
- **Search Account**: Find an account by the account holder's name.
- **Delete Account**: Remove an account from the system.
- **Update Account**: Modify account details (Name, Mobile, Aadhaar, Balance).
- **Data Persistence**: All data is saved to `accounts.dat` file, ensuring data is not lost when the program closes.

## 📂 Project Structure

The project is organized into a modular structure for better maintainability:

```
Bank-Management-System/
├── include/
│   └── bank.h        # Header file containing structure definitions and function prototypes
├── src/
│   ├── bank.c        # Source file containing the implementation of all banking functions
│   └── main.c        # Main entry point with the menu-driven interface
├── accounts.dat      # Binary file where account data is stored (created automatically)
└── README.md         # Project documentation (this file)
```

## 🛠️ How to Compile and Run

To run this project, you need a C compiler like GCC installed on your system.

### 1. Compile the Project

Open your terminal or command prompt, navigate to the project directory, and run the following command to compile the source files:

```bash
gcc src/main.c src/bank.c -I include -o BankSystem
```

- `src/main.c`: The main file.
- `src/bank.c`: The implementation file.
- `-I include`: Tells the compiler to look for header files in the `include` folder.
- `-o BankSystem`: Names the output executable `BankSystem` (or `BankSystem.exe` on Windows).

### 2. Run the Application

After successful compilation, run the executable:

**On Windows:**
```bash
BankSystem.exe
```

**On Linux/macOS:**
```bash
./BankSystem
```

## 📚 Learning Objectives

This project is great for learning:
- **Modular C Programming**: Separating code into header (`.h`) and source (`.c`) files.
- **File I/O**: Reading from and writing to binary files (`fread`, `fwrite`).
- **Structs**: Managing complex data (Account details) using structures.
- **Pointers**: Passing data by reference for updates.
- **Input Validation**: Ensuring correct data entry (e.g., 10-digit mobile number).

## 🤝 Contributing

Feel free to fork this repository and submit pull requests. You can add features like:
- Password protection for accounts.
- Transaction history logs.
- Interest calculation.

## 📜 License

This project is open-source and free to use for educational purposes.
