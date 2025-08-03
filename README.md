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
## Main Function
### ```get_next_line()```

Validates a file descriptor and returns the next full line (including a new line if it occurs).

Parameters:

- ```int fd```: File descriptor to read from file

Returns:
- NULL if error or EOF
- a string and maybe with the ```\n```

## 🔧 Helper Functions

### ```buffer_check()```

Determines the end of a line, appends buffer content to the current line with the function ```new_line()``` and shifts remaining content with the function ```buffer_change()``` for future calls.

Parameters:

- ```int fd```: File descriptor to read from file

Returns:
- NULL if error or EOF
- a string and maybe with the ```\n```
---
### ```new_line()```

Appends one element from the buffer content to the current line.

Parameters:

- ```char *line```: old line
- ```char c```: new char

Returns:
- line
---
### ```change_buffer()```

Shifts remaining content with the function ```buffer_change()``` for future calls.

Parameters:

- ```char *buffer```: old line
- ```size_t start```: new char

Returns:
- line

---
### Further Functions


| Function Name    | Category              | Parameters                                                 | Return                                  |
|------------------|------------------------|------------------------------------------------------------|-----------------------------------------|
| `ft_strjoin`     | Line Construction      | `char *s1`, `char *s2`                                     | New string (`s1 + s2`) in allocated memory |
| `ft_strlen`      | String Utility         | `const char *s`                                            | Length of the string (`size_t`)         |
| `free_mem`       | Memory/Error Handling  | `char *line`, `int status`                                 | Always returns `NULL` (after free)      |
| `ft_strdup`      | String Utility | `const char *s`                                            | Duplicate of `s` in new memory          |
| `ft_strchr`      | String Utility | `const char *s`, `int c`                                   | Pointer to `c` in `s` or `NULL`         |

##💡 Example Usage
...
## Testing
I tested the fet_next_line funtion with different sizes.
-different BUFFER_SIZE values
