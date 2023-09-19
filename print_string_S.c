#include "main.h"

/**
 * print_string_S - prints a string with non printable characters escaped
 * @buffer: the buffer to store the data
 * @s: the string to print
 *
 * Return: the number of characters printed
 */
int print_string_S(char *buffer, char *s)
{
        int i = 0, count = 0;

        if (s == NULL)
                s = "(null)";

        while (s[i])
        {
                if (isprint(s[i]))
                        buffer[count++] = s[i];
                else
                        count += sprintf(buffer + count, "\\x%02X", s[i]);
                i++;
        }

        return (count);
}
