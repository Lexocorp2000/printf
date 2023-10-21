#include "main.h"


/****************** PRINT CHAR *******************/

/**
 * print_char - Prints a char
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get Width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_char(va_list args, char buffer[],
	int flag, int width, int s, int precision)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}




/***************** PRINT A STRING ********************/


/**
 * print_string - Prints a string
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_string(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(s);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}




/******************** PRINT PERCENTAGE SIGN **********************/



/**
 * print_percent - Prints a percentage sign
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_percent(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(s);

	return (write(1, "%%", 1));
}




/******************* PRINT INTEGER *********************/


/**
 * print_int - Print integer
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_int(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_s_number(n, s);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flag, width, precision, s));
}




/******************* PRINT BINARY **********************/


/**
 * print_binary - Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	unsigned int n, m, o, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(s);

	n = va_arg(args, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (o = 1; o < 32; o++)
	{
		m /= 2;
		a[o] = (n / m) % 2;
	}
	for (o = 0, sum = 0, count = 0; o < 32; o++)
	{
		sum += a[o];
		if (sum || o == 31)
		{
			char z = '0' + a[o];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
