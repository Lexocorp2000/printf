#include "main.h"

/**
 * print_hex - Print hexa
 * @val: Variable
 * Return: count
 */

int print_hex(va_list val)
{
	int i, *a, count = 0;
	unsigned int num = va_arg(val, unsigned int);

	while (num / 16 != 0)
	{
		num = num / 16;
		count++;
	}
	count++;
	a = malloc(sizeof(int) * count);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < count; i++)
	{
		a[i] = tem % 16;
		tem = tem / 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (a[i] > 9)
			a[i] = a[i] + 39;
		_putchar(a[i] + '0');
	}
	free(a);
	return (count);
}
