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

### The `!` (Logical NOT) Operator
- **What it means:** "NOT" or "Opposite of".
- **How it works:**
  - `!true` becomes `false`
  - `!false` becomes `true`
- **Example:**
  ```cpp
  bool is_raining = false;
  if (!is_raining) {
      cout << "It is NOT raining!";
  }
  ```

---

### `if (!getline(cin, input))`
- **What it means:** *"If reading input did NOT succeed, then stop."*
- **Why it's there:**
  - `getline(cin, input)` returns `true` when it successfully reads a line you typed.
  - It returns `false` if the input stream suddenly ends (for example, if you press **Ctrl + D** in the terminal to close the program, or if commands are fed from a file that ended).
- **What happens without it?**
  - If you hit **Ctrl + D** without this check, your program gets stuck in a crazy infinite loop printing `db > db > db > ...` millions of times per second.
  - Putting `!` before `getline` is a **safety net** so the program shuts down gracefully if input stops.

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
