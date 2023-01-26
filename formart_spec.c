#include "main.h"

/**
 * print_character - Prints a single character
 * @arg_list: list of arguments, containing the character to be printed
 * 
 * Return: Will return the number of characters printed (1)
 */
int print_character(va_list arg_list)
{
    _writechar(va_arg(arg_list, int));
    return (1);
}

/**
 * print_string - Prints a string
 * @arg_list: list of arguments, containing the string to be printed
 * 
 * Return: Will return the number of characters printed
 */
int print_string(va_list arg_list)
{
    int i;
    char *string;

    string = va_arg(arg_list, char *);
    if (string == NULL)
        string = "(null)";
    for (i = 0; string[i] != '\0'; i++)
        _writechar(string[i]);
    return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @arg_list: list of arguments, not used in this function
 * 
 * Return - Will return the number of characters printed (1)
 */
int print_percent(__attribute__((unused))va_list arg_list)
{
    _writechar('%');
    return (1);
}

/**
 * print_integer - Prints an integer
 * @arg_list: list of arguments, containing the integer to be printed
 * 
 * Return: Will return the number of characters printed
 */
int print_integer(va_list arg_list)
{
    return (print_number(arg_list));
}

/**
 * print_unsigned_integer - Prints an unsigned integer
 * @arg_list: list of arguments, containing the unsigned integer to be printed
 * 
 * Return: Will return the number of characters printed
 */
int print_unsigned_integer(va_list arg_list)
{
    unsigned int number;

    number = va_arg(arg_list, unsigned int);

    if (number == 0)
        return (print_unsigned_number(number));

    if (number < 1)
        return (-1);
    return (print_unsigned_number(number));
}
