#include "main.h"

/**
 * get_precision - The precision for printing
 * @format: Formatted string in which to print the arguments
 * @arg: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */

int get_precision(const char *format, int *arg, va_list list)
{
	int i = *arg + 1;
	int precision = -1;

	if (format[i] != '.')
		return (precision);

	precision = 0;

	for (i += 1; format[i] != '\0'; i++)
	{
		if (is_digit(format[i]))
		{
			precision *= 10;
			precision += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*arg = i - 1;

	return (precision);
}
