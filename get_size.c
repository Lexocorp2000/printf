#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @arg: List of arguments to be printed.
 * Return: Precision.
 */

int get_size(const char *format, int *arg)
{
	int i = *arg + 1;
	int size = 0;

	if (format[i] == 'l')
		size = S_LONG;
	else if (format[i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*arg = i - 1;
	else
		*arg = i;

	return (precision);
}
