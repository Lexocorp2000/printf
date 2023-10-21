#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @i: individual arg.
 * @buffer: Buffer array to handle print.
 * @flag: Calculates active flags
 * @width: Get width.
 * @precision: Precision of specification
 * @s: Size of specifier
 * Return: 1
 */

int handle_print(const char *format, int *i, va_list list, char buffer[],
	int flag, int width, int precision, int s)
{
	int j, unknow_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (j = 0; format_types[j].format != '\0'; j++)
		if (format[*i] == format_types[j].format)
			return (format_types[j].fn(list, buffer, flag, width, precision, s));

	if (format_types[j].format == '\0')
	{
		if (format[*i] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*i - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (format[*i] != ' ' && format[*i] != '%')
				--(*i);
			if (format[*i] == ' ')
				--(*i);
			return (1);
		}
		unknow_len += write(1, &format[*i], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
