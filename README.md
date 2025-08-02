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
Checks if the file descriptor is valid and links to the function create_new_line().
Arguments:
int fd

Return:
line

```create_new_line(int fd, char *buffer)```

Arguments:
int fd, char *buffer
Return:

