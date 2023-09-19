#include "main.h"

/**
 * print_octal - prints an unsigned int in octal
 * @buffer: the buffer to store the data
 * @n: the unsigned int to print
 * @flags: the flags to apply
 *
 * Return: the number of characters printed
 */
int print_octal(char *buffer, unsigned int n, int flags)
{
	int count = 0;

	if (flags & HASH_FLAG && n != 0)
		buffer[count++] = '0';

	if (n / 8)
		count += print_octal(buffer + count, n / 8, 0);

	buffer[count] = (n % 8) + '0';
	count++;

	return (count);
}
