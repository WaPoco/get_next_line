## get_next_line
This project is about implementing a function in C that reads a file line by line using a descriptor.
Our challanges were handling error management, memory allocation, static variables and buffer management efficiently in C.
The function reads one line per call and is designed to work correctly across multiple calls.

## 🧠 Core Functionality

- read different BUFFER_SIZEs
- returns NULL if empty
- handles files and the standard input
- 
## 📁 File Structure
[**get_next_line.c**](get_next_line.c)

 Contains the main logic of the function, reading from the file descriptor and returning lines one at a time.

[**get_next_line_utilis.c**](get_next_line_utilis.c)

  Contains all the necessary helper functions (string operations, memory handling, etc.).
[**get_next_line.h**](get_next_line.h)

  Header file that declares the function prototype and any required includes/macros.
## Functions
