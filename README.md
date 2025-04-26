# _printf: Building a Custom Print Function from Scratch

## Project Overview
- Variadic functions in C
- Memory management and string manipulation
- Complex parsing algorithms
- Modular code design

Created by:
- Abigail Aleman: [LinkedIn](https://www.linkedin.com/in/abigailraleman/)
- Jeremy Mitts: [LinkedIn](https://www.linkedin.com/in/jeremy-mitts/)

## The Journey of Building _printf

###Development process:
1. **Research Phase**: Spent days reading the actual `printf` man pages, GNU C Library source code, and various articles to understand how the original function works
2. **Planning**: Carefully mapped out the architecture, deciding on a modular approach with function pointers
3. **Core Implementation**: Built the basic parsing engine that identifies format specifiers
4. **Handler Development**: Created individual handlers for each format specifier
5. **Edge Case Hunting**: Rigorously tested with unusual inputs to ensure robustness
6. **Optimization**: Refined the buffer management to minimize system calls


## Implemented Features

- **Basic Format Specifiers**:
  - `%c`: Character output
  - `%s`: String output
  - `%d` & `%i`: Signed decimal integers
  - `%u`: Unsigned decimal integers
  - `%o`: Octal number output
  - `%x` & `%X`: Hexadecimal output (lowercase/uppercase)
  - `%%`: Percent sign output

- **Advanced Features**:
  - Custom buffer implementation to minimize `write` calls
  - Proper handling of NULL string arguments
  - Comprehensive error checking 

## Technical Details

### Prototype
```c
int _printf(const char *format, ...);
```

### Return Value
- **Success**: Returns the number of characters printed (excluding the null byte)
- **Error**: Returns -1

### Key Files
- `main.h`: Header containing all prototypes and struct definitions
- `_printf.c`: Core function implementation
- `handlers/`: Directory with specialized format handlers
- `buffer.c`: Custom buffer implementation for output efficiency
- `utils/`: Utility functions for string manipulation
- `man_3_printf`: Custom man page for the _printf function

### Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

## Sample Usage

```c
#include "main.h"
#include <limits.h>

int main(void)
{
    int len;
    void *addr = (void *)0x7ffe637541f0;
    
    /* Basic Output */
    len = _printf("Hello, %s!\n", "world");
    _printf("Characters printed: %d\n", len);
    
    /* Various Format Specifiers */
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Custom printf in action");
    _printf("Decimal: %d\n", 12345);
    _printf("Negative: %i\n", -9876);
    _printf("Unsigned: %u\n", UINT_MAX);
    _printf("Octal: %o\n", 8421);
    _printf("Hex (lower): %x\n", 255);
    _printf("Hex (upper): %X\n", 255);
    _printf("Pointer address: %p\n", addr);
    
    /* Edge Cases */
    _printf("Percent sign: %%\n");
    _printf("Empty string: '%s'\n", "");
    _printf("NULL string: %s\n", NULL);
    
    return (0);
}
```
