#include "main.h"

/*************** PRINT POINTER ****************/


/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */

int print_pointer(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(args, void *);

	UNUSED(width);
	UNUSED(s);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_c = '+', length++;
	else if (flag & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flag, padd, extra_c, padd_start));
}




/********************** PRINT NON PRINTABLE ***********************/


/**
 * print_non_printable - Prints ASCII codes in hexa of non printable chars
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_non_printable(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}




/********************* PRINT REVERSE ***********************/


/**
 * print_reverse - Prints reverse string.
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(s);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}




/****************** PRINT A STRING IN ROT13 **********************/


/**
 * print_rot13string - Print a string in rot13.
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	char i;
	char *str;
	unsigned int k, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(args, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (j = 0; str[j]; j++)
	{
		for (k = 0; in[k]; k++)
		{
			if (in[k] == str[j])
			{
				i = out[k];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[k])
		{
			i = str[j];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
