#include "main.h"

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @buffer: the buffer to store the data
 * @n: the unsigned int to print
 * @upper: flag for uppercase or lowercase letters
 * @flags: the flags to apply
 *
 * Return: the number of characters printed
 */
int print_hex(char *buffer, unsigned int n, int upper, int flags)
{
	int count = 0;
	char digit;

	if (flags & HASH_FLAG && n != 0)
	{
		buffer[count++] = '0';
		buffer[count++] = upper ? 'X' : 'x';
	}

	if (n / 16)
		count += print_hex(buffer + count, n / 16, upper, 0);

	digit = n % 16;

	if (digit < 10)
		buffer[count] = digit + '0';
	else
	{
		if (upper)
			buffer[count] = digit - 10 + 'A';
		else
			buffer[count] = digit - 10 + 'a';
	}

	count++;

	return (count);
}
