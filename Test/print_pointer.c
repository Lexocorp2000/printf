#include "main.h"

/**
 * print_pointer - Prints pointer
 * @val: Value
 * Return: integer
 */

int print_pointer(va_list val)
{
	void *p;
	char *s = "(nil)";
	int i, b;
	long int a;

	p = va_arg(val, void *);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
			_putchar(s[i]);
		return (i);
	}
	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	b = print_hex_extra(a);
	return (b + 2);
}
