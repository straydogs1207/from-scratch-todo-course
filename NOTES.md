# C++ & Database Study Notes (Cheat Sheet)

These notes explain every new term and concept we encounter as we build our database.

---

## 1. C++ Keywords & Concepts

### What is a `bool` Function?
- **Concept:** Think of a `bool` function as a **question** your program asks. The answer is always **`true`** (yes) or **`false`** (no).
- **Format:**
  ```cpp
  bool functionName(input) {
      return true_or_false_answer;
  }
  ```
- **Simple Example:**
  ```cpp
  bool isAdult(int age) {
      return age >= 18;
  }
  ```

---

### What is Pass-by-Value vs. Pass-by-Reference (`&`)?
When you pass a variable into a function, C++ has two ways to do it:

#### 1. Pass-by-Value (Default - The "Photocopy"):
```cpp
void addTen(int score) {
    score = score + 10; // Only changes the photocopy!
}
```
C++ makes a temporary copy. The original variable in `main()` never changes.

#### 2. Pass-by-Reference (Using `&` - The "Original"):
```cpp
void addTen(int& score) {
    score = score + 10; // Changes the REAL original variable!
}
```
The **`&`** means: *"Do NOT make a copy. Work directly on the real variable."*

---

### What does `const string& input` mean?
- **Format:** `const DataType& variableName`
- **Meaning:** *"Look at the original variable (no slow copying), but **DO NOT CHANGE IT** (read-only)."*
- **Why we use it:** To safely read text without wasting computer memory copying it.

---

### Why does `Statement& statement` NOT have `const`?
- Because the entire job of `prepare_statement` is to **fill in and change** the ticket!
- Without `&`, it would fill in a photocopy and throw it away.
- With `&`, it writes directly onto the real `statement` ticket in `main()`.

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
