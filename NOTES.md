# C++ & Database Study Notes (Cheat Sheet)

These notes explain every new term and concept we encounter as we build our database.

---

## 1. C++ Keywords & Concepts

### Why combine `const` and `&`? (`const string&`)
- **Isn't `const` the opposite of `&`?**
  - `&` has TWO superpowers:
    1. It allows changing the original variable.
    2. **It skips copying! (Super fast performance).**
- **The 1,000-Page Book Analogy:**
  1. `string text` (Pass-by-Value): Photocopies all 1,000 pages. (Safe, but slow and wastes RAM).
  2. `string& text` (Pass-by-Reference): Hands over the original book with a pen. (Fast, but the function might scribble on it).
  3. **`const string& text` (The Glass Case):** Hands over the original book inside a glass display case!
     - **`&`** means: Zero photocopying (instant speed).
     - **`const`** means: Glass case lock (read-only, 100% safe).

---

### Scope: Why do we only need `&` in functions?
- **Inside `main()`:** If you write `score = score + 10;`, it changes to 60 immediately. You don't need `&` because you are in the same room as your variable!
- **Inside another function:** A separate function lives in a different "room" (called a **different scope**).
  - Without `&`: The function creates a temporary local copy in its room, changes the copy to 60, and throws it away. The original in `main()` stays 50!
  - With `&`: A wire connects the function directly to the variable in `main()`.

---

### Where does the `&` symbol go?
It always goes **between the DataType and the variableName**:
```cpp
DataType& variableName
```
Examples:
- `int& score`
- `string& text`
- `Statement& statement`

---

### The 2-Second Rule: When should YOU use `&`?

Ask yourself these two questions whenever you write a function:

| Question | What to write | Example |
| :--- | :--- | :--- |
| **1. Does the function need to MODIFY the original variable?** | Use **`Type&`** | `void fillTicket(Statement& statement)` |
| **2. Is it BIG (like a `string` or `struct`) that we only want to READ?** | Use **`const Type&`** | `bool checkWord(const string& input)` |
| **3. Is it small (like an `int` or `bool`) that we only want to READ?** | Normal (no `&`) | `bool isAdult(int age)` |

---

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

### The Golden Definition of a `struct`:
> **"A `struct` creates a brand new data type that can hold other data types inside it (like `int`, `string`, `double`, `bool`, or even other custom types!)."**

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
