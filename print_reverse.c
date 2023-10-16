#include "main.h"

/**
 * print_revs - Print string in reverse
 * @val: Argument
 * Return: String
 */

int print_revs(va_list val)
{
	char *s = va_arg(val, char *);
	int i, j = 0;

	if (s == NULL)
		s = "(null)";
	while (s[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(s[i]);
	return (j);
}
