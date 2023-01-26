# _printf
## _A custom implementation of the printf function in C._

[![ALX](https://images.squarespace-cdn.com/content/v1/5f064fad5065bf4b98603cbe/f8ed951c-c3fd-40d6-9876-14f9ecb19ecb/African%2BLeadership%2BGroup%2BLogo.png)](https://www.alxafrica.com/)

The _printf library is a simple implementation of the printf function in C. It is designed to provide a similar functionality to the standard printf function, with the added ability to handle custom conversion specifiers.

##  ✨ How to use ✨
```c
int _printf(const char *format, ...);
```
In addition to the standard conversion specifiers (e.g. %c, %s, %d, etc.), the library also supports the following custom conversion specifiers:
   - > %r: prints a string in reverse
   - > %R: applies the ROT13 encryption to a string
   - > %b: prints an integer in binary format
   - > %o: prints an integer in octal format
   - > %x: prints an integer in lowercase hexadecimal format
   - > %X: prints an integer in uppercase hexadecimal format

## Elements

This file contains the following elements:
    struct conversion_specifier: This struct contains two fields, symbol and func. symbol is a string that represents a specific conversion specifier (e.g. 'c' for character, 's' for string, etc.) and func is a pointer to a function that takes in a va_list as an argument and handles the corresponding conversion specifier. This struct is then given an alias conver_t for easier reference throughout the rest of the code.
    _printf: This function takes in a format string as its first argument and produces output according to the format provided. It takes in a variable number of arguments and returns the number of characters printed.
    _writechar: This function takes in a character as its argument and writes it to stdout. It returns the number of characters printed (1 for success, -1 for failure).
    parser: This function takes in the format string, an array of conversion functions, and a variable argument list as its arguments. It parses the format string and calls the appropriate conversion function. It returns the number of characters printed.
    ```
    print_character, print_string, print_percent, print_integer, print_u_number, print_s_int, print_unsigned_integer, print_reversed, rot13, print_binary, print_octal, print_hex_cap, print_hex_lo
    ```
    : These are the conversion functions that handle the corresponding conversion specifiers.