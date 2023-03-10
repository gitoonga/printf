#include "main.h"

/**
 *print_hex_lo - takes in an unsigned int from a va_list and converts it to its
 *hexadecimal representation. It then writes the hexadecimal representation to
 *stdout.
 * 
 *@param arg_list: va_list containing the unsigned int to be converted
 *@return: length of the hexadecimal representation on success, -1 on failure
 */
int print_hex_lo(va_list arg_list)
{
	unsigned int decimal_num;
	int len;
	int remainder;
	char *hex_representation;
	char *reversed_hex;

	decimal_num = va_arg(arg_list, unsigned int);

	if (decimal_num == 0)
	{
		/*write '0' to stdout and return 1 (length of '0')*/
		return (_writechar('0'));
	}

	if (decimal_num < 1)
	{
		/*Return -1 indicating failure*/
		return (-1);
	}

	/*Get the length of the hex representation*/
	len = base_length(decimal_num, 16);

	/*Allocate memory for the hex representation*/
	hex_representation = malloc(sizeof(char) *len + 1);
	if (hex_representation == NULL)
	{
		/*Return -1 indicating failure*/
		return (-1);
	}

	/*Convert decimal number to hex representation*/
	for (len = 0; decimal_num > 0; len++)
	{
		remainder = decimal_num % 16;
		if (remainder > 9)
		{
			remainder = hex_check(remainder, 'x');
			hex_representation[len] = remainder;
		}
		else
		{
			hex_representation[len] = remainder + 48;
		}

		decimal_num = decimal_num / 16;
	}

	hex_representation[len] = '\0';

	/*Reverse the hex representation*/
	reversed_hex = reverse_string(hex_representation);
	if (reversed_hex == NULL)
	{
		return (-1);
	}

	/*Write the reversed hex representation to stdout*/
	write_string(reversed_hex);

	/*Free the allocated memory*/
	free(hex_representation);
	free(reversed_hex);

	/*Return the length of the hex representation*/
	return (len);
}

/**
 *print_hex_cap - converts the first argument of the va_list to an uppercase hexadecimal representation
 *and writes it to the standard output
 *@list: va_list containing the argument to be converted
 *
 *Return: the length of the hexadecimal representation
 *-1 if the decimal number is less than 1
 *-1 if memory allocation fails
 */

int print_hex_cap(va_list list)
{
	/*variable to hold the decimal number*/
	unsigned int decimal_num;
	/*variable to hold the length of the hexadecimal representation*/
	int rep_len;
	/*variable to hold the remainder when the decimal number is divided by 16*/
	int remainder;
	/*variable to hold the hexadecimal representation*/
	char *hex_rep;
	/*variable to hold the reversed hexadecimal representation*/
	char *reversed_hex;

	/*get the decimal number from the va_list*/
	decimal_num = va_arg(list, unsigned int);

	/*if the decimal number is 0, print 0 and return 1*/
	if (decimal_num == 0)
		return (_writechar('0'));

	/*if the decimal number is less than 1, return -1*/
	if (decimal_num < 1)
		return (-1);
	/*get the length of the hexadecimal representation*/

	rep_len = base_length(decimal_num, 16);

	/*allocate memory for the hexadecimal representation*/
	hex_rep = malloc(sizeof(char) *rep_len + 1);

	/*if memory allocation fails, return -1*/
	if (hex_rep == NULL)
		return (-1);

	/*convert the decimal number to hexadecimal representation*/
	for (rep_len = 0; decimal_num > 0; rep_len++)
	{
		remainder = decimal_num % 16;
		if (remainder > 9)
		{ /*convert the remainder to its corresponding uppercase hex character*/
			remainder = hex_check(remainder, 'X');
			hex_rep[rep_len] = remainder;
		}
		else
		{ /*convert the remainder to its corresponding ASCII character*/
			hex_rep[rep_len] = remainder + 48;
		}

		decimal_num = decimal_num / 16;
	}

	hex_rep[rep_len] = '\0';
	/*reverse the hexadecimal representation*/
	reversed_hex = reverse_string(hex_rep);
	/*if reversing the string fails, return -1*/
	if (reversed_hex == NULL)
		return (-1);
	/*write the reversed hexadecimal representation to the standard output*/
	write_string(reversed_hex);
	/*release the memory allocated for the hexadecimal representation*/
	free(hex_rep);
	/*release the memory allocated for the reversed hexadecimal representation*/
	free(reversed_hex);
	/*return the length of the hexadecimal representation*/
	return (rep_len);
}

/**
 *hex_check - Checks which hex function is calling it
 *@num: Number to convert into letter
 *@x: Tells which hex function is calling it
 *Return: Ascii value for a letter
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
	return (0);
}