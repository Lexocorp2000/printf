#include "main.h"

/**
 * print_oct - Print octa
 * @val: Variable
 * Return: count
 */

int print_oct(va_list val)
{
	int i, *a, count = 0;
	unsigned int num = va_arg(val, unsigned int);

	while (num / 8 != 0)
	{
		num = num / 8;
		count++;
	}
	count++;
	a = malloc(sizeof(int) * count);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
	{
		a[i] = tem % 8;
		tem = tem / 8;
	}
	for (i = count - 1; i >= 0; i--)
		_putchar(a[i] + '0');
	free(a);
	return (count);
}
