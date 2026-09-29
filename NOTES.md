# C++ & Database Study Notes (Cheat Sheet)

These notes explain every new term and concept we encounter as we build our database.

---

## 1. C++ Keywords & Concepts

### `using namespace std;`
- **What it does:** Saves you from typing `std::` over and over again.
- **Why it exists:** In C++, standard tools like `cout`, `cin`, and `string` are stored in a toolbox called `std` (standard).
- **Without it:** You must write `std::cout`, `std::cin`, `std::string`.
- **With it:** You can simply write `cout`, `cin`, `string`.

---

### `while (true)`
- **What it does:** An **infinite loop** that runs forever without stopping.
- **Why we use it:** Programs like databases, games, or calculators need to stay open and keep listening for user input continuously.
- **How it stops:** It only stops when you trigger a `break;` statement or exit the program.

---

### `break;`
- **What it does:** The **emergency exit** for a loop.
- **How it works:** When C++ hits `break;`, it instantly terminates the loop and jumps to the code below the closing curly brace `}`.
- **Example:**
  ```cpp
  if (input == ".exit") {
      break; // Stops the while(true) loop immediately!
  }
  ```

---

### `getline(cin, input)`
- **What it does:** Reads an entire line of text typed by the user until they press **Enter**.
- **Difference from `cin >> input`:**
  - `cin >> input` stops at the first space (so typing `"Buy milk"` only captures `"Buy"`).
  - `getline(cin, input)` captures the full sentence with spaces (`"Buy milk"`).

---

## 2. Database Concepts (Module 1)

### REPL (Read-Eval-Print Loop)
The standard way command-line databases work:
1. **Read:** Wait for user to type a command (`getline`).
2. **Eval:** Figure out what the command means.
3. **Print:** Output the result or error.
4. **Loop:** Return to the prompt (`db > `) and wait for the next command.

### Meta-Commands vs SQL Statements
- **Meta-Commands:** Commands for the database program itself. They **always start with a dot `.`** (e.g. `.exit`).
- **SQL Statements:** Commands that read or write your data (e.g. `insert`, `select`).
