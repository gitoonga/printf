#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct conversion_specifier - contains two fields: symbol, a string that represents a specific conversion specifier 
 * and func a pointer to a function that takes in a va_list as an 
 * argument and handles the corresponding conversion specifier.
 * The struct is then given an alias conver_t for easier reference throughout the rest of the code.
 * @symbol: A string containing the symbol that represents a specific conversion specifier (e.g. 'c' for character, 's' for string, etc.)
 * @func: A pointer to a function that takes in a va_list as an argument and handles the corresponding conversion specifier
*/
struct conversion_specifier
{
    char *symbol;
    
    int (*func)(va_list);
};

/* Define an alias for the struct conversion_specifier */
typedef struct conversion_specifier conver_t;

int _printf(const char *format, ...);
int _writechar(char c);
int parser(const char *main_string, conver_t function_list[], va_list arg_list);

int print_character(va_list arg_list);
int print_string(va_list arg_list);
int print_percent(__attribute__((unused))va_list arg_list);
int print_integer(va_list arg_list);
int print_u_number(unsigned int n);
int print_s_int(va_list args);
int print_unsigned_integer(va_list arg_list);

int print_reversed(va_list arg);
int _isalpha(char c);
int rot13(va_list list);
char *reverse_string(char *original_string);
void write_string(char *input_string);
unsigned int base_length(unsigned int number, int base);
char *memory_copy(char *destination, char *source, unsigned int num_bytes);
int print_binary(va_list list);
int print_octal(va_list arg_list);
int hex_check(int, char);
int print_hex_cap(va_list list);
int print_hex_lo(va_list arg_list);

#endif
