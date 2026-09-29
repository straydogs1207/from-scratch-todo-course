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

---

### What does "Reading Succeeded or Failed" Mean? (`!getline`)
Think of `cin` like a **straw** connected to your keyboard:
- **Normal typing (Success):** You type `hello` and press Enter. Letters flow through the straw. `getline` drinks the letters and reports **Success** (`true`).
- **End of Input / EOF (Failure):** What if someone cuts the straw or there is nothing left to read? `getline` reports **Failure** (`false`).
- **When does reading fail?**
  1. **When reading from a file:** If your database reads commands from a file, once it reaches the last line of the file, there is nothing left. `getline` fails, telling the program to stop.
  2. **When user presses Ctrl + D:** In Linux/Mac terminals, pressing **Ctrl + D** means: *"I am hanging up the phone, no more input is coming."*

### Difference Between `Ctrl + C` and `Ctrl + D`:
- **`Ctrl + C` (Force Kill):** Like pulling the power cord out of the wall. The operating system forcefully kills your program instantly.
- **`Ctrl + D` (Polite Hangup / EOF):** Closes the input straw. `if (!getline(...))` catches this polite hangup and allows the program to exit cleanly on its own!

---

### Common C++ Syntax Rules (Braces & Semicolons)
1. **Matching Braces:** Every opening `{` MUST have a matching closing `}`. A parenthesis `)` cannot close a `{`.
2. **Every Statement Needs a Semicolon `;`:** After `cout << ... \n"`, always end with a semicolon `;` before the closing brace `}`.
3. **Handling Folders with Spaces in Terminal:** When a folder name has spaces (e.g. `important coding files`), always wrap the path in quotes `"..."` in the terminal:
   ```bash
   cd "/home/ashutosh-goyal/important coding files"
   ```

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
