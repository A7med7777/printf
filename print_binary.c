#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @buffer: the buffer to store the data
 * @n: the unsigned int to print
 *
 * Return: the number of characters printed
 */
int print_binary(char *buffer, unsigned int n)
{
        int count = 0;

        if (n / 2)
                count += print_binary(buffer + count, n / 2);

        buffer[count] = (n % 2) + '0';
        count++;

        return (count);
}
