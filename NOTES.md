# C++ & Database Study Notes (Cheat Sheet)

These notes explain every new term and concept we encounter as we build our database.

---

## 1. C++ Keywords & Concepts

### How Variables are Created in C++: `DataType variableName;`
In C++, every variable is created using the exact same two-word pattern:
```cpp
DataType variableName;
```

Look at how custom structs follow the exact same rule as built-in types:

| DataType (The Kind of Box) | variableName (Your Custom Name) | What it creates |
| :--- | :--- | :--- |
| `int` | `x;` | Creates an integer box named `x` |
| `double` | `price;` | Creates a decimal box named `price` |
| `string` | `name;` | Creates a text box named `name` |
| **`Player`** | **`p1;`** | **Creates a Player box named `p1`** |
| **`Statement`** | **`statement;`** | **Creates a Statement box named `statement`** |

- **`p1` is NOT a value!** `p1` is the **name of the variable** (just like `x` or `name`).
- You could name it anything: `Player y;`, `Player hero;`, or `Player mario;`.

---

### Does a `struct` need an `enum` first?
- **NO!** The keyword `struct` **itself** defines a brand new data type.
- Once you write `struct Player { ... };`, the word `Player` becomes a real, valid data type in C++, just like `int` or `string`.
- **Difference between `enum` and `struct`:**
  - **`enum`**: Used when a variable can only be **one single choice from a list of words** (e.g. `RED`, `YELLOW`, `GREEN`).
  - **`struct`**: Used when you want to **bundle multiple variables together** into a single container (e.g. `name` + `health`).

---

### Deep Dive: `struct` (Custom Data Boxes)
- **What is it?** A `struct` is a blueprint to bundle multiple variables together into one custom box.
- **Why do we need it?** Without a `struct`, variables float around loosely. With a `struct`, related variables are kept together in a single package.
- **The Dot `.` Operator:** Used to reach inside a struct box to read or write a value (e.g., `p1.health = 100;`).

#### Easy Example (Game Character):
```cpp
// 1. The Blueprint (Defines the new type 'Player')
struct Player {
    string name;
    int health;
};

// 2. Creating an actual player box:
Player p1;         // DataType is Player, variable name is p1
p1.name = "Mario"; // Reach inside p1 and set name
p1.health = 100;   // Reach inside p1 and set health
```

#### Our Database Example (`struct Statement`):
- **Analogy:** A Restaurant Order Ticket.
  - The waiter (`prepare_statement`) writes the order on the ticket.
  - The kitchen (`execute_statement`) reads the ticket and cooks the meal.
```cpp
// 1. The Ticket Blueprint
struct Statement {
    StatementType type; // What kind of order is it? (INSERT or SELECT)
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
- **Why we use it:** Instead of using numbers like `0` or `1` for commands, we give them human names:
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
