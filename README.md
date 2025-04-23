# atlas-printf
# _printf

## Overview
A custom implementation of the C standard library `printf` function. This project recreates the functionality of the standard `printf` function, supporting various format specifiers and conversion modifiers.

## Description
The `_printf` function writes output to the standard output stream (stdout) under the control of a format string. The format string specifies how subsequent arguments are converted for output. This implementation supports a subset of the standard `printf` functionality.

## Supported Format Specifiers
- `%c`: Character
- `%s`: String
- `%d`, `%i`: Signed decimal integer
- `%u`: Unsigned decimal integer
- `%o`: Unsigned octal
- `%x`, `%X`: Unsigned hexadecimal integer (lowercase/uppercase)
- `%%`: Percent sign

## Prototype
```c
int _printf(const char *format, ...);
```

## Return Value
- On success: The number of characters printed (excluding the null byte used to end strings)
- On error: -1

## Repository Files
- `main.h`: Header file containing function prototypes and struct definitions
- `_printf.c`: Main function implementation
- `handlers/`: Directory containing format specifier handler functions
- `utils/`: Directory containing utility functions
- `man_3_printf`: Custom man page for the _printf function

## Compilation
All files are compiled on Ubuntu 20.04 LTS using:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

## Example Usage
```c
#include "main.h"
#include <limits.h>

int main(void)
{
    int len;
    
    len = _printf("Hello, %s!\n", "world");
    _printf("Length: %d\n", len);
    
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "This is a string");
    _printf("Decimal: %d\n", 1234);
    _printf("Negative: %d\n", -5678);
    _printf("Unsigned: %u\n", UINT_MAX);
    _printf("Octal: %o\n", 9876);
    _printf("Hexadecimal: %x\n", 255);
    
    return (0);
}
```

## Authors
- Abigail Aleman (https://github.com/aallm004)
- Jeremy Mitts (https://github.com/jerm014)
