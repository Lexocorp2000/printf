#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Copy printf
 * @format: look for identifier
 * Return: int
 */

int _printf(const char *format, ...)
{
	match m[] = {
		{"%c", print_char}, {"%s", print_string}, {"%%", print_37},
		{"%d", print_dec}, {"%i", print_int}, {"%r", print_revs},
		{"%R", print_rot13}, {"%b", print_bin}, {"%u", print_unsigned},
		{"%o", print_oct}, {"%x", print_hex}, {"%X", print_HEX},
		{"%S", print_STRING}, {"%p", print_pointer}
	};

	va_list args;
	int j, i = 0, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 14;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len = len + m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		len++;
	}
	va_end(args);
	return (len);
}
