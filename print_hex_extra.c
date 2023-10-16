#include "main.h"

/**
 * print_hex_extra - Print hexa
 * @num: Number
 * Return: count
 */

int print_hex_extra(unsigned long int num)
{
	long int i, *a, count = 0;
	unsigned long int tem = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		count++;
	}
	count++;
	a = malloc(sizeof(long int) * count);

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
