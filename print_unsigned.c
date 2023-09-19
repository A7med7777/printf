#include "main.h"

/**
 * print_unsigned - prints an unsigned int in decimal
 * @buffer: the buffer to store the data
 * @n: the unsigned int to print
 * @flags: the flags to apply
 *
 * Return: the number of characters printed
 */
int print_unsigned(char *buffer, unsigned int n, int flags)
{
	int count = 0;

	if (flags & PLUS_FLAG)
		buffer[count++] = '+';
	else if (flags & SPACE_FLAG)
		buffer[count++] = ' ';

	if (n / 10)
		count += print_unsigned(buffer + count, n / 10, 0);

	buffer[count] = (n % 10) + '0';
	count++;

	return (count);
}
