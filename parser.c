#include "main.h"
/**
 * parser - Receives the main string and all the necessary parameters to
 * print a formatted string.
 * @main_string: A string containing all the desired characters.
 * @function_list: A list of all the possible functions.
 * @arg_list: A list containing all the arguments passed to the program.
 * Return: A total count of the characters printed.
 */
int parser(const char *main_string, conver_t function_list[], va_list arg_list)
{
	int i, j, _return_val, printed_chars;

	printed_chars = 0;/* Iterates through the main string */
	for (i = 0; main_string[i] != '\0'; i++)
	{/* Check if current character is a format specifier */
		if (main_string[i] == '%')
		{/* Iterate through the list of possible functions to find the correct one */
			for (j = 0; function_list[j].symbol != NULL; j++)
			{/* If a matching function is found, call it and...*/
				/*...increment the printed character count */
				if (main_string[i + 1] == function_list[j].symbol[0])
				{
					_return_val = (function_list[j].func(arg_list));
					if (_return_val == (-1))
						return (-1);

					printed_chars += _return_val;
					break;
				}
			} /* If no matching function is found */
			if (function_list[j].symbol == NULL && main_string[i + 1] != ' ')
			{
				if (main_string[i + 1] != '\0')
				{
					_writechar(main_string[i]);
					_writechar(main_string[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			} /* Update loop variable to skip format symbolbols */
			i = i + 1;
		}
		else
		{
			_writechar(main_string[i]); /* call the write function */
			printed_chars++;
		}
	}
	return (printed_chars);
}
