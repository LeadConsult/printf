#include "main.h"


/**
 * * write_base - sends characters to be written on standard output
 * * @string: String to parse
 */
void write_base(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);
}

/**
 * * base_len - Calculates the length for an octal number.
 * * @num: The number for which the length is being calculated
 * * @base: Base to be calculated by
 * * Return: An integer representing the length of a number
 */
unsigned int base_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}

/**
 * * _memcpy - copy memory area
 * * @dest: Destination for copying
 * * @src: Source to copy from
 * * @n: The number of bytes to copy
 * * Return: The _memcpy() function returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

