## get_next_line
This project is about implementing a function in C that reads a file line by line using a file descriptor.
The function reads one line per call and preserves the input between calls using a static buffer. Our challanges were handling error management, memory allocation, static variables and buffer management efficiently in C.

## 🧠 Core Functionality

- Reads one line including the newline ```\n```
- Works with different ```BUFFER_SIZE```values
- Returns ```NULL``` if no more lines to read or on error 
- Handles different file descriptors (stdin, file descriptor, ...)
- Manages memory safely between successive calls
---

## 📁 File Structure
[**get_next_line.c**](get_next_line.c)

 Contains the main logic. The function reads from the file descriptor and returns one line at a time.

[**get_next_line_utilis.c**](get_next_line_utilis.c)

  Contains all the necessary helper functions (string operations, memory handling, etc.).
  
[**get_next_line.h**](get_next_line.h)

  Header file that declares the function prototype and any required includes/macros.
## Functions
```get_next_line()```

Validates the file descriptor and returns the next full (including a new line if it occurs).

Parameters:

- ```int fd```: File descriptor to read from file

Returns:
- NULL if error or EOF
- a string line with the ```\n```
- 

## 🔧 Helper Functions Overview

char *buffer_check(char *buffer, char *line);
Appends buffer content to the current line and shifts remaining content for future calls.

size_t ft_strlen(const char *s);
Custom implementation of strlen() to calculate string length.

char *ft_strjoin(char *s1, char *s2);
Concatenates two strings into a new one. Frees the first string to manage memory safely.

char *free_mem(char *str, int code);
Handles memory freeing and error signaling (e.g., freeing line on error and returning NULL).
