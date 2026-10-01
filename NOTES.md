# C++ & Database Study Notes (Cheat Sheet)

These notes explain every new term and concept we encounter as we build our database.

---

## 1. C++ Keywords & Concepts

### Line-by-Line Breakdown: `prepare_statement`

```cpp
bool prepare_statement(const string& input, Statement& statement) {
```

1. **`bool` (Return Type):**
   - The function finishes by reporting **`true`** (Success: command understood) or **`false`** (Failure: unrecognized command).
2. **`const string& input`:**
   - **`string input`:** The text the user typed into the terminal.
   - **`const` (Constant / Read-Only):** A safety promise that this function will only *read* the user's text, never alter or delete it.
   - **`&` (Reference / No-Copy):** Tells C++ not to waste time duplicating the string in RAM. It looks directly at the original variable.
3. **`Statement& statement`:**
   - **Why NO `const`?** Because the function's entire job is to **fill in and modify** the `statement` box!
   - **Why `&`?** Ensures the changes are made directly to the original `statement` ticket in `main()`, not a temporary copy.

---

### How to Check if a String Starts with a Word: `.rfind("insert", 0) == 0`
- **Why can't we use `input == "insert"`?**
  Because the user types arguments after it, like `"insert 1 milk"`. `"insert 1 milk"` does **not** equal `"insert"`.
- **What `.rfind(text, 0)` does:**
  Searches if the string starts with `text` at position `0` (the very beginning).
  - If it starts with `"insert"` at position 0 $\rightarrow$ returns `0`.
  - If it does NOT start with `"insert"` $\rightarrow$ returns a huge error number (`string::npos`).
- **Meaning of `input.rfind("insert", 0) == 0`:**
  *"Does this sentence start with the word 'insert' at position 0?"*

---

### The Golden Definition of a `struct`:
> **"A `struct` creates a brand new data type that can hold other data types inside it (like `int`, `string`, `double`, `bool`, or even other custom types!)."**

Look at how custom structs follow the exact same rule as built-in types:
```cpp
DataType variableName;
```

| DataType (The Kind of Box) | variableName (Your Custom Name) | What it creates |
| :--- | :--- | :--- |
| `int` | `x;` | Creates an integer box named `x` |
| `double` | `price;` | Creates a decimal box named `price` |
| `string` | `name;` | Creates a text box named `name` |
| **`Player`** | **`p1;`** | **Creates a Player box named `p1`** |
| **`Statement`** | **`statement;`** | **Creates a Statement box named `statement`** |

- **`p1` is NOT a value!** `p1` is the **name of the variable** (just like `x` or `name`).
- The keyword `struct` **itself** defines this new type. No `enum` needed!

---

### Deep Dive: `struct` (Custom Data Boxes)
- **What is it?** A `struct` bundles multiple variables together into one custom box.
- **The Dot `.` Operator:** Used to reach inside a struct box to read or write a value (e.g., `p1.health = 100;`).

#### Easy Example (Game Character):
```cpp
// 1. The Blueprint (Defines the new type 'Player')
struct Player {
    string name;   // Holds a string inside
    int health;    // Holds an int inside
    double speed;  // Holds a double inside
};

// 2. Creating an actual player box:
Player p1;         // DataType is Player, variable name is p1
p1.name = "Mario"; // Reach inside p1 and set name
p1.health = 100;   // Reach inside p1 and set health
```

#### Our Database Example (`struct Statement`):
```cpp
// 1. The Ticket Blueprint
struct Statement {
    StatementType type; // Holds our custom StatementType inside!
};

// 2. Creating and filling the ticket:
Statement statement;               // DataType is Statement, variable name is statement
statement.type = STATEMENT_INSERT; // Reach inside and stamp the ticket!
```

---

### Type vs. Variable Name (Capital vs. Lowercase)
C++ is strictly **case-sensitive** (`Statement` and `statement` are two different things!).
- **Capital `Statement` (The Type / Blueprint):**
  Defines what the data looks like. Just like `int` or `string`.
- **Lowercase `statement` (The Actual Variable / Object):**
  The actual instance created from that blueprint.

---

### `enum` (Enumeration)
- **What it does:** A list of named options/choices.
- **Why we use it:** When a variable can only be **one choice from a fixed list of words**:
  ```cpp
  enum StatementType {
      STATEMENT_INSERT,
      STATEMENT_SELECT
  };
  ```

---

### `continue;`
- **What it does:** Skips the rest of the current loop round and immediately jumps back to the top of the loop.
- **Difference from `break;`:**
  - `break;`: Exits and stops the loop permanently.
  - `continue;`: Jumps straight back to `cout << "db > "` for the next command.

---

### `using namespace std;`
- **What it does:** Saves you from typing `std::` over and over again.

---

### `while (true)`
- **What it does:** An **infinite loop** that runs forever without stopping.

---

### `break;`
- **What it does:** The **emergency exit** for a loop.

---

### The `!` (Logical NOT) Operator
- **What it means:** "NOT" or "Opposite of".

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
