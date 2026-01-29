*This project has been created as part of the 42 curriculum by jgodino-.*

# Libft

## Description

**Libft** is the first project in the 42 curriculum. Its main goal is to create a C library from scratch that will be used in future projects throughout the course.

The project involves rewriting a set of standard C library functions (`libc`) to understand their underlying behavior, memory management, and low-level algorithms. Additionally, it includes a set of utility functions for string manipulation and linked lists that are not present in the standard library but are highly useful for C programming.

### Objectives
* To deepen the understanding of standard C functions.
* To master memory allocation (`malloc`, `free`) and manipulation.
* To learn how to create and manage a static library (`.a`).
* To get familiar with `Makefile` creation and project structure.

---

## The Library

The library is organized into three main sections based on the nature of the functions.

### 1. Libc Functions
Standard C functions re-implemented with the same prototype and behavior as the originals.

| Character Checks | String Ops | Memory Ops | Conversion/Output |
| :--- | :--- | :--- | :--- |
| `ft_isalpha` | `ft_strlen` | `ft_memset` | `ft_atoi` |
| `ft_isdigit` | `ft_strlcpy` | `ft_bzero` | `ft_calloc` |
| `ft_isalnum` | `ft_strlcat` | `ft_memcpy` | `ft_strdup` |
| `ft_isascii` | `ft_strchr` | `ft_memmove` | `ft_toupper` |
| `ft_isprint` | `ft_strrchr` | `ft_memchr` | `ft_tolower` |
| | `ft_strnstr` | `ft_memcmp` | |
| | `ft_strncmp` | | |

### 2. Additional Functions
Utility functions that are indispensable for string manipulation and memory management in C.

* **`ft_substr`**: Allocates and returns a substring from a string.
* **`ft_strjoin`**: Allocates and returns a new string, result of the concatenation of two strings.
* **`ft_strtrim`**: Allocates and returns a copy of a string with specified characters removed from the beginning and end.
* **`ft_split`**: Allocates and returns an array of strings obtained by splitting a string using a delimiter.
* **`ft_itoa`**: Converts an integer to an ASCII string.
* **`ft_strmapi`**: Applies a function to each character of a string to create a new string.
* **`ft_striteri`**: Applies a function to each character of a string by address.
* **`ft_putchar_fd`**: Outputs a character to a file descriptor.
* **`ft_putstr_fd`**: Outputs a string to a file descriptor.
* **`ft_putendl_fd`**: Outputs a string followed by a newline to a file descriptor.
* **`ft_putnbr_fd`**: Outputs an integer to a file descriptor.

### 3. Bonus Functions (Linked Lists)
Functions to manipulate the `t_list` structure (linked lists).

* **`ft_lstnew`**: Creates a new list element.
* **`ft_lstadd_front`**: Adds an element at the beginning of the list.
* **`ft_lstsize`**: Counts the number of elements in a list.
* **`ft_lstlast`**: Returns the last element of the list.
* **`ft_lstadd_back`**: Adds an element at the end of the list.
* **`ft_lstdelone`**: Deletes and frees a single element.
* **`ft_lstclear`**: Deletes and frees a list.
* **`ft_lstiter`**: Iterates the list and applies a function to the content.
* **`ft_lstmap`**: Iterates the list and applies a function to create a new list.

---

## Instructions

### Requirements
* **OS**: Linux or macOS.
* **Compiler**: `gcc` or `clang`.
* **Build Tool**: `make`.

### Compilation

To compile the library, navigate to the project root directory in your terminal and run:

```bash
make
```

This command will compile the mandatory functions and generate the `libft.a` archive file.

**Available Makefile commands:**

* `make` or `make all`: Compiles the library (mandatory part).
* `make bonus`: Compiles the library including the linked list functions (bonus part).
* `make clean`: Removes the object files (`.o`) generated during compilation.
* `make fclean`: Removes the object files and the `libft.a` library file.
* `make re`: Performs a `fclean` followed by a `make` to recompile the project from scratch.

### Usage

To use this library in your own C projects:

1.  **Include the header:** Add the header file to your source code.
    ```c
    #include "libft.h"
    ```

2.  **Compile with the library:** When compiling your project, link against `libft.a`.
    ```bash
    gcc main.c -L. -lft -o my_program
    ```
    *(Note: `-L.` tells the compiler to look in the current directory for the library, and `-lft` links against `libft.a`)*.

---

## Resources

### References
* **Man pages**: The primary source of truth for the behavior of libc functions (e.g., `man 3 memset`).
* **C Library Documentation**: [cppreference.com](https://en.cppreference.com/w/c/header) or [cplusplus.com](https://cplusplus.com/reference/clibrary/).
* **GNU Make Manual**: For understanding the Makefile structure.

### Use of AI
*The following section details the use of Artificial Intelligence tools during the development of this project.*

**Tools Used:**
* Google Gemini

**Specific Applications:**
1.  **Test Generation**: Creation of `main` files for execution and verification.
2.  **Robustness**: Generating robust test cases to cover edge cases and ensure error handling coverage.

*Note: All code implementation and logic understanding were verified manually to ensure strict adherence to 42's coding standards (The Norm) and learning objectives.*
