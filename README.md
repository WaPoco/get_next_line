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
## 🔧 Main Function

### ```get_next_line()```

Validates a file descriptor and returns the next full line (including a new line if it occurs).

Parameters:

- ```int fd```: File descriptor to read from file

Returns:
- `NULL` if:
  - End-of-file is reached
  - An error occurs (e.g., invalid `fd`, `read` failure, or memory allocation error)
- a dynamically allocated string containing the next line (including `\n` if it exists)

##  🔧🔧 Helper Functions

### ```buffer_check()```

Determines the end of a line, appends buffer content to the current line with the function ```new_line()``` and shifts remaining content with the function ```buffer_change()``` for future calls.

Parameters:

- ```char *buffer```: Buffer containing the input from fd
- ```char *line```: A dynamically allocated string containing the next line (including `\n` if it exists)

Returns:
- line with ```\n```
  
---
### ```new_line()```

Appends one element from the buffer content to the current line.

Parameters:

- ```char *line```: the next line
- ```char c```: one element from the buffer

Returns:
- line with one char from buffer

---

### ```change_buffer()```

Shifts remaining content for future calls.

Parameters:

- ```char *buffer```: old buffer
- ```size_t start```: starting index of new buffer from old buffer

Returns:
- shifted buffer

---
### Further Functions


| Function Name    | Category              | Parameters                                                 | Return                                  |
|------------------|------------------------|------------------------------------------------------------|-----------------------------------------|
| `ft_strlen`      | String Utility         | `const char *s`                                            | Length of the string (`size_t`)         |
| `free_mem`       | Memory/Error Handling  | `char *line`, `int bytesRead`                              | Always returns `NULL` (after free line) |
---
## 💡 Example Usage
You can use get_next_line in your source file.
```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("test", O_RDONLY);
	char *line;
	line = get_next_line(fd);
	printf("1.line: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("2.line: %s", line);
	free(line);
	line = get_next_line(fd);
	printf("3.line: %s", line);
	free(line);
	close(fd);
	return (1);
}
```
## Testing
I tested the fet_next_line funtion with different sizes.
-different BUFFER_SIZE values
