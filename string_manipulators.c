#include "main.h"

/**
 * * print_reversed - Calls a function to reverse and print a string
 * * @arg: Argument passed to the function
 * * Return: The amount of characters printed
 */
int print_reversed(va_list arg)
{
	int lenght;
	char *string;
	char *ptr;

	string = va_arg(arg, char *);
	if (string == NULL)
		return (-1);
	ptr = rev_string(string);
	if (ptr == NULL)
		return (-1);
	for (lenght = 0; ptr[lenght] != '\0'; lenght++)
		_putchar(ptr[lenght]);
	free(ptr);
	return (lenght);
}

/**
 * * rot13 - Convert string to rot13
 * * @list: string to convert.
 * * Return: converted string
 */
int rot13(va_list list)
{
	int i;
	int x;
	char *string;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(list, char *);
	if (string == NULL)
		return (-1);
	for (i = 0; string[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (string[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(string[i]);
	}
	return (i);
}

/**
 * * rev_string - reverses a string in place
 * * @s: string to reverse
 * * Return: A pointer to a character.
 */
char *rev_string(char *s)
{
	int lenght;
	int head;
	char tmp;
	char *dest;

	for (lenght = 0; s[lenght] != '\0'; lenght++)
	{}

	dest = malloc(sizeof(char) * lenght + 1);
	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, lenght);
	for (head = 0; head < lenght; head++, lenght--)
	{
		tmp = dest[lenght - 1];
		dest[lenght - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}


/**
 * * formated_string - Receives the main string and all the necessary
 * * parameters to print a formated string.
 * * @format: A string containing all the desired characters.
 * * @f_list: A list of all the posible functions.
 * * @arg_list: A list containing all the argumentents passed to the program.
 * * Return: A total count of the characters printed.
 */
int formated_string(const char *format, conver_t f_list[], va_list arg_list)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	for (i = 0; format[i] != '\0'; i++)/* Iterates through the main string*/
	{
		if (format[i] == '%') /*Checks for format specifiers*/
		{
			/*Iterates through struct to find the right func*/
			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1; /*Updating i to skip format symbols*/
		}
		else
		{
			_putchar(format[i]); /*call the write function*/
			printed_chars++;
		}
	}
	return (printed_chars);
}

