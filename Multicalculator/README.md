# 🧮 Multi Calculator (C++)

A feature-rich **Console-Based Multi Calculator** built using **C++**. This project combines multiple calculators into one application, allowing users to perform mathematical calculations, evaluate expressions, convert units, and calculate basic statistical values through a simple menu-driven interface.

---

## 📌 Features

The application provides four different modules:

### 1️⃣ Expression Calculator
Evaluate complete mathematical expressions with operator precedence and parentheses support.

#### Supported Operations
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)
- Modulus (`%`)
- Parentheses `()`

### Example

Input:
```
(12+8)*5-10/2
```

Output:
```
95
```

---

### 2️⃣ Scientific Calculator

Performs advanced mathematical operations.

#### Supported Operations

- Power (xʸ)
- Square
- Cube
- Square Root
- Cube Root
- Factorial
- Logarithm Base 10
- Natural Log (ln)
- Exponential Function (eˣ)

---

### 3️⃣ Statistics Calculator

Calculates basic statistical values from user input.

#### Supported Operations

- Mean
- Maximum
- Minimum
- Range

Example:

Input:
```
5
12 8 20 15 10
```

Output:
```
Mean = 13
Maximum = 20
Minimum = 8
Range = 12
```

---

### 4️⃣ Unit Converter

Convert between commonly used units.

#### Supported Conversions

### Temperature
- Celsius → Fahrenheit
- Fahrenheit → Celsius

### Length
- Meter → Kilometer
- Kilometer → Meter
- Inch → Centimeter
- Centimeter → Inch

### Weight
- Gram → Kilogram
- Kilogram → Gram

---

# 🛠 Technologies Used

- C++
- Standard Template Library (STL)

---

# 📚 Header Files Used

| Header | Purpose |
|---------|----------|
| `iostream` | Input and Output |
| `cmath` | Mathematical functions like `sqrt()`, `pow()`, `log()`, `exp()` |
| `vector` | Store multiple values dynamically |
| `algorithm` | Find maximum and minimum values |
| `stack` | Expression evaluation using stacks |
| `string` | Handle mathematical expressions |
| `limits` | Clear input buffer |
| `stdexcept` | Exception handling (e.g., divide by zero) |

---

# ⚙️ How It Works

When the program starts, a main menu is displayed.

```
========== MULTI CALCULATOR ==========

1. Expression Calculator
2. Scientific Calculator
3. Statistics Calculator
4. Unit Converter
5. Exit
```

The user selects a module.

Each module contains its own submenu and performs the requested calculation.

After completing an operation, the program returns to the menu until the user chooses **Exit**.

---

# 🧠 Working of Expression Calculator

The Expression Calculator evaluates complete mathematical expressions using the **Stack Data Structure**.

It follows these steps:

1. Read the expression.
2. Store numbers in a **value stack**.
3. Store operators in an **operator stack**.
4. Apply **operator precedence**:
   - `*`, `/`, `%` have higher priority.
   - `+`, `-` have lower priority.
5. Handle parentheses correctly.
6. Compute the final result.

This approach is similar to the algorithm used in many real-world calculators.

---

# 🚀 Operations Performed

## Arithmetic Operations

- Addition
- Subtraction
- Multiplication
- Division
- Modulus

## Scientific Operations

- Power
- Square
- Cube
- Square Root
- Cube Root
- Factorial
- Logarithm
- Natural Log
- Exponential

## Statistical Operations

- Mean
- Maximum
- Minimum
- Range

## Unit Conversion

- Temperature
- Length
- Weight

---

# 💡 Concepts Used

This project demonstrates many important C++ concepts:

- Functions
- Switch Statements
- Loops
- Vectors
- Stacks
- Strings
- Mathematical Functions
- Exception Handling
- STL Algorithms
- Menu-Driven Programming
- Operator Precedence
- User Input Validation

---

# 📂 Project Structure

```
MultiCalculator.cpp
│
├── Expression Calculator
├── Scientific Calculator
├── Statistics Calculator
├── Unit Converter
└── Main Menu
```

---

# ▶️ How to Compile

Using **g++**

```bash
g++ MultiCalculator.cpp -o MultiCalculator
```

Run:

```bash
./MultiCalculator
```

---

# 🎯 Learning Outcomes

This project helps in understanding:

- C++ Programming
- STL Containers
- Stack Implementation
- Mathematical Algorithms
- Expression Parsing
- Menu-Driven Applications
- Exception Handling
- Modular Programming

---

# 📈 Future Improvements

Some features that can be added:

- BMI Calculator
- Matrix Calculator
- Currency Converter
- Age Calculator
- Date Calculator
- Trigonometric Functions
- Binary/Decimal/Hex Converter
- GPA Calculator
- Complex Number Calculator
- Graphical User Interface (GUI)

---

# 👨‍💻 Author

**Rudra Sharma**

B.Tech CSE (AI & ML)

---

## ⭐ If you like this project

Give this repository a ⭐ on GitHub and feel free to contribute or suggest improvements.
