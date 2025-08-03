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
## Main Functions
```get_next_line()```

Validates a file descriptor and returns the next full line (including a new line if it occurs).

Parameters:

- ```int fd```: File descriptor to read from file

Returns:
- NULL if error or EOF
- a string and maybe with the ```\n```

## 🔧 Helper Functions

```buffer_check()```

Determines the end of a line, appends buffer content to the current line with the function ```new_line()``` and shifts remaining content with the function ```buffer_change()``` for future calls.

Parameters:

- ```int fd```: File descriptor to read from file

Returns:
- NULL if error or EOF
- a string and maybe with the ```\n```
---
```new_line()```

Appends one element from the buffer content to the current line.

Parameters:

- ```char *line```: old line
- ```char c```: new char

Returns:
- line
---
```change_buffer()```

Shifts remaining content with the function ```buffer_change()``` for future calls.

Parameters:

- ```char *buffer```: old line
- ```size_t start```: new char

Returns:
- line

## Helperfunctions

```ft_strlen()```

Custom implementation of strlen() to calculate string length.

---

```ft_strjoin()```

Concatenates two strings into a new one. Frees the first string to manage memory safely.

---

```free_mem()```

Handles memory freeing and error signaling (e.g., freeing line on error and returning NULL).
