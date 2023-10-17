#include "main.h"

/**
 * print_HEX_extra - Print hexa
 * @num: Variable
 * Return: count
 */

int print_HEX_extra(unsigned int num)
{
	int i, *a, count = 0;
	unsigned int tem = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		count++;
	}
	count++;
	a = malloc(sizeof(int) * count);

	for (i = 0; i < count; i++)
	{
		a[i] = tem % 16;
		tem = tem / 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (a[i] > 9)
			a[i] = a[i] + 7;
		_putchar(a[i] + '0');
	}
	free(a);
	return (count);
}
