#include "main.h"

/**
 * print_STRING - Print upper string
 * @val: Value
 * Return: len
 */

int print_STRING(va_list val)
{
	char *s;
	int i, len = 0;
	int v;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			v = s[i];
			if (v < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_HEX_extra(v);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}
