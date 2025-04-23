# _printf: Building a Custom Print Function from Scratch

## Project Overview
**_printf** is not just another school project—it's a deep dive into the inner workings of one of C's most powerful and complex functions. By recreating `printf` from scratch, this project demonstrates advanced understanding of:
- Variadic functions in C
- Memory management and string manipulation
- Complex parsing algorithms
- Modular code design

## About the Developers

Hello! We're Abigail Allman and Jeremy Mitts, a team of passionate software engineers with a love for low-level programming and systems design. This project represents our journey into understanding how fundamental C library functions actually work under the hood.

Connect with us:
- Abigail Aleman: [LinkedIn](https://www.linkedin.com/in/abigailraleman/)
- Jeremy Mitts: [LinkedIn](https://www.linkedin.com/in/jeremy-mitts/)

## The Journey of Building _printf

What started as a straightforward assignment quickly evolved into a fascinating exploration of C's capabilities. The development process followed these stages:

1. **Research Phase**: Spent days reading the actual `printf` man pages, GNU C Library source code, and various articles to understand how the original function works
2. **Planning**: Carefully mapped out the architecture, deciding on a modular approach with function pointers
3. **Core Implementation**: Built the basic parsing engine that identifies format specifiers
4. **Handler Development**: Created individual handlers for each format specifier
5. **Edge Case Hunting**: Rigorously tested with unusual inputs to ensure robustness
6. **Optimization**: Refined the buffer management to minimize system calls

Each step presented unique challenges that pushed my understanding of C programming to new levels.

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

## Future Enhancements

- **Field Width Specifiers**: Support for controlling output width (in progress)
- **Precision Specifiers**: For controlling decimal precision
- **Length Modifiers**: Support for `l`, `h`, etc.
- **Flag Characters**: Implementing `-`, `+`, `0`, ` `, and `#` flags
- **Binary Specifier**: Adding a custom `%b` for binary output
- **Floating Point Support**: Implementing `%f` and related specifiers

## Most Challenging Aspects

### 1. The Variadic Function Rabbit Hole
Working with C's va_list and variadic functions proved more complex than anticipated. Ensuring type safety while handling unknown argument counts required careful design and testing.

### 2. Buffer Management Nightmare
Implementing an efficient buffer system that minimizes system calls while correctly handling all edge cases (especially around buffer boundaries) was surprisingly difficult.

### 3. The Pointer Format Specifier
Implementing `%p` for pointer output required deep understanding of memory representation and platform-specific considerations.

### 4. The Great Segfault Hunt of 2025
Tracking down memory access violations and segmentation faults taught me more about debugging than any other project. One particularly elusive bug took three days to track down to an off-by-one error in the buffer management.

## 🛠️ Technical Details

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
