# C++ Module 00

## Overview
This module introduces you to Object-Oriented Programming in C++. You'll learn about namespaces, classes, member functions, stdio streams, initialization lists, static, const, and other basic C++ concepts.

## Compilation
All exercises must be compiled with:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Exercises

### Exercise 00: Megaphone
**Files:** `ex00/megaphone.cpp`, `ex00/Makefile`

A simple program that converts command line arguments to uppercase.

**Usage:**
```bash
cd ex00
make
./megaphone "hello world"
# Output: HELLO WORLD

./megaphone
# Output: * LOUD AND UNBEARABLE FEEDBACK NOISE *
```

**Features:**
- Converts all command line arguments to uppercase
- Displays feedback noise if no arguments provided
- Uses C++ string manipulation

### Exercise 01: My Awesome PhoneBook
**Files:** `ex01/Contact.hpp`, `ex01/Contact.cpp`, `ex01/PhoneBook.hpp`, `ex01/PhoneBook.cpp`, `ex01/main.cpp`, `ex01/Makefile`

An interactive phonebook application with a maximum of 8 contacts.

**Usage:**
```bash
cd ex01
make
./phonebook
```

**Commands:**
- `ADD`: Add a new contact (first name, last name, nickname, phone number, darkest secret)
- `SEARCH`: Display all contacts and select one to view details
- `EXIT`: Quit the program

**Features:**
- Object-oriented design with Contact and PhoneBook classes
- Circular buffer for contacts (replaces oldest when full)
- Formatted display with truncation for long fields
- Input validation and error handling

### Exercise 02: The Job Of Your Dreams
**Files:** `ex02/Account.hpp`, `ex02/Account.cpp`, `ex02/tests.cpp`, `ex02/Makefile`

A banking system simulation with static member variables and timestamps.

**Usage:**
```bash
cd ex02
make
./account
```

**Features:**
- Static member variables to track global account statistics
- Timestamp logging for all operations
- Deposit and withdrawal functionality with validation
- Account creation and destruction tracking

## Key Concepts Learned

### Classes and Objects
- **Class Definition**: Creating classes with private and public members
- **Constructors/Destructors**: Object lifecycle management
- **Member Functions**: Methods that operate on class data
- **Encapsulation**: Private data with public interfaces

### Static Members
- **Static Variables**: Shared across all instances of a class
- **Static Functions**: Functions that don't require an instance
- **Global State Management**: Tracking statistics across objects

### C++ Features
- **Namespaces**: Avoiding naming conflicts
- **Const Correctness**: Immutable data and functions
- **References**: Efficient parameter passing
- **Streams**: Input/output operations
- **String Manipulation**: Working with std::string

### Memory Management
- **Stack Allocation**: Automatic memory management
- **No Dynamic Allocation**: Using fixed-size arrays
- **RAII**: Resource Acquisition Is Initialization

## Coding Standards
- **Naming**: UpperCamelCase for classes, camelCase for functions
- **File Naming**: ClassName.hpp, ClassName.cpp
- **Include Guards**: Preventing double inclusion
- **C++98 Standard**: Using legacy C++ features
- **No STL Containers**: Manual array management (until Module 08)

## Testing
Each exercise includes comprehensive testing:
- **Exercise 00**: Command line argument testing
- **Exercise 01**: Interactive testing with user input
- **Exercise 02**: Automated test suite with expected output
