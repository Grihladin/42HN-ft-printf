<div align="center">

# <img src="https://github.com/Grihladin/42-project-badges/blob/main/badges/ft_printfe.png" width="150" height="150"> 

</div>

ft_printf is a [42Heilbronn](https://www.42heilbronn.de/en/) project that recreates the standard C library printf function. This implementation demonstrates understanding of variadic functions, string formatting, and low-level output operations using only the write system call.

## Project Overview

The ft_printf function mimics the behavior of the original printf function, handling various format specifiers and returning the number of characters printed. This project reinforces fundamental concepts in C programming including variadic functions, string manipulation, and memory management.

## Implementation Features

- **Variadic Functions**: Uses `va_list`, `va_start`, `va_arg`, and `va_end` for handling variable arguments
- **Modular Design**: Each format specifier is implemented in its own function
- **Error Handling**: Returns -1 on write errors, character count on success
- **Memory Efficient**: Uses only write system call, no malloc for basic functionality

## Supported Format Specifiers

- **%c**: Single character
- **%s**: String of characters  
- **%p**: Pointer address in hexadecimal format
- **%d**: Signed decimal integer
- **%i**: Signed integer (same as %d)
- **%u**: Unsigned decimal integer
- **%x**: Unsigned hexadecimal integer (lowercase)
- **%X**: Unsigned hexadecimal integer (uppercase)
- **%%**: Literal percent sign

## Installation

**Requirements:**
- macOS or Linux
- Make

```bash
git clone https://github.com/Grihladin/42HN-ft_printf.git
cd 42HN-ft_printf
make
```

## Usage

Include the header in your C files and link the compiled library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You have %d new messages.\n", "World", 5);
    ft_printf("Pointer address: %p\n", &main);
    ft_printf("Hexadecimal: %x (lowercase) %X (uppercase)\n", 255, 255);
    return (0);
}
```

## Project Structure

```
ft_printf/
├── ft_printf.h              # Header file with function declarations
├── ft_printf.c              # Main ft_printf function and format parsing
├── ft_printf_char.c         # Character format (%c) implementation
├── ft_printf_str.c          # String format (%s) implementation  
├── ft_printf_int.c          # Integer formats (%d, %i) implementation
├── ft_printf_uint.c         # Unsigned integer format (%u) implementation
├── ft_printf_hexadecimal.c  # Hexadecimal formats (%x, %X) implementation
├── ft_printf_ptr.c          # Pointer format (%p) implementation
├── ft_printf_percent.c      # Percent literal (%%) implementation
├── Makefile                 # Build configuration
└── README.md                # Project documentation
```

---

Made with ❤️ by **[mratke](https://github.com/Grihladin)** - 42 Heilbronn
