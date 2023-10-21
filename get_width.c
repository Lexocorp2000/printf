#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @arg: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */

int get_width(const char *format, int *arg, va_list list)
{
	int i;
	int width = 0;

	for (i = *arg + 1; format[i] != '\0'; i++)
	{
		if (is_digit(format[i]))
		{
			width *= 10;
			width += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*arg = i - 1;

	return (width);
}
