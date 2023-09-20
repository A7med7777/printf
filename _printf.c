#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, n = 0;
	char buffer[BUF_SIZE];
	int flags = 0;
	int length = 0;
	int width = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			{
				if (format[i] == '+')
					flags |= PLUS_FLAG;
				else if (format[i] == ' ')
					flags |= SPACE_FLAG;
				else if (format[i] == '#')
					flags |= HASH_FLAG;
				i++;
			}
			if (format[i] == '*')
			{
				width = va_arg(args, int);
				i++;
			}
			else
				width = 0;
			if (format[i] == 'l')
				length = 1;
			else if (format[i] == 'h')
				length = -1;
			else
				length = 0;
			if (length != 0)
				i++;
			switch (format[i])
			{
				case 'c':
					n = sprintf(buffer + count, "%*c", width, va_arg(args, int));
					count += n;
					break;
				case 's':
					n = sprintf(buffer + count, "%*s", width, va_arg(args, char *));
					count += n;
					break;
				case '%':
					n = sprintf(buffer + count, "%*s", width, "%");
					count += n;
					break;
				case 'd':
				case 'i':
					if (length == 1)
						n = print_unsigned_int(buffer + count, va_arg(args, long int), flags);
					else if (length == -1)
						n = print_unsigned_int(buffer + count, va_arg(args, int), flags);
					else
						n = print_unsigned_int(buffer + count, va_arg(args, int), flags);
					while (n < width)
					{
						buffer[count + n] = ' ';
						n++;
					}
					count += n;
					break;
				case 'b':
					if (length == 1)
						n = print_binary(buffer + count, va_arg(args, long unsigned int));
					else if (length == -1)
						n = print_binary(buffer + count, va_arg(args, unsigned int));
					else
						n = print_binary(buffer + count, va_arg(args, unsigned int));
					while (n < width)
					{
						buffer[count + n] = ' ';
						n++;
					}
					count += n;
					break;
				case 'u':
					if (length == 1)
						n = print_unsigned_int(buffer + count, va_arg(args, long unsigned int), flags);
					else if (length == -1)
						n = print_unsigned_int(buffer + count, va_arg(args, unsigned int), flags);
					else
						n = print_unsigned_int(buffer + count, va_arg(args, unsigned int), flags);
					while (n < width)
					{
						buffer[count + n] = ' ';
						n++;
					}
					count += n;
					break;
				case 'o':
					if (length == 1)
						n = print_octal(buffer + count, va_arg(args, long unsigned int), flags);
					else if (length == -1)
						n = print_octal(buffer + count, va_arg(args, unsigned int), flags);
					else
						n = print_octal(buffer + count, va_arg(args, unsigned int), flags);
					while (n < width)
					{
						buffer[count + n] = ' ';
						n++;
					}
					count += n;
					break;
				case 'x':
					if (length == 1)
						n = print_hex(buffer + count, va_arg(args, long unsigned int), 0, flags);
					else if (length == -1)
						n = print_hex(buffer + count, va_arg(args, unsigned int), 0, flags);
					else
						n = print_hex(buffer + count, va_arg(args, unsigned int), 0, flags);
					while (n < width)
					{
						buffer[count + n] = ' ';
						n++;
					}
					count += n;
					break;
				case 'X':
					if (length == 1)
						n = print_hex(buffer + count, va_arg(args, long unsigned int), 1, flags);
					else if (length == -1)
						n = print_hex(buffer + count, va_arg(args, unsigned int), 1, flags);
					else
						n = print_hex(buffer + count, va_arg(args, unsigned int), 1, flags);
					while (n < width)
					{
						buffer[count + n] = ' ';
						n++;
					}
					count += n;
					break;
				case 'S':
					n = print_string_S(buffer + count, va_arg(args, char *));
					while (n < width)
					{
						buffer[count + n] = ' ';
						n++;
					}
					count += n;
					break;
				case 'p':
					n = sprintf(buffer + count, "%*p", width, va_arg(args, void *));
					count += n;
					break;
				default:
					buffer[count++] = '%';
					if (width != 0)
						count += sprintf(buffer + count, "%d", width);
					if (length == 1)
						buffer[count++] = 'l';
					else if (length == -1)
						buffer[count++] = 'h';
					buffer[count++] = format[i];
					break;
			}
			flags = 0;
			length = 0;
		}
		else
		{
			buffer[count++] = format[i];
		}
		i++;
	}

	va_end(args);

	write(1, buffer, count);

	return (count);
}
