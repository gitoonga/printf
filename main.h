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
int print_unsigned_integer(va_list arg_list);

#endif
