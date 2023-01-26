#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...) {

    int printed_chars;
    /*list of functions for different format specifiers*/
    conver_t function_list[] = {
        {"c", print_char},
        {"s", print_string},
        {"%", print_percent},
        {"d", print_integer},
        {"i", print_integer},
        {"b", print_binary},
        {"r", print_reversed},
        {"R", rot13},
        {"u", print_unsigned_integer},
        {"o", print_octal},
        {"x", print_hex},
        {"X", print_heX},
        {NULL, NULL}
    };

    va_list arg_list;

    /*checking if format string is null*/
    if (format == NULL)
        return (-1);

    /*initializing the list of arguments*/
    va_start(arg_list, format);
    
    /*Calling parser function to parse the format string and arguments*/
    printed_chars = parser(format, function_list, arg_list);
    
    /*ending the list of arguments*/
    va_end(arg_list);
    return (printed_chars);
}
