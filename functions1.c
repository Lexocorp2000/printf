#include "main.h"

/********************* PRINT UNSIGNED INTEGER ***********************/

/**
 * print_unsigned - Prints an unsigned integer
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculate active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */

int print_unsigned(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_s_unsgnd(num, s);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, precision, s));
}



/************* PRINT UNSIGNED INTEGER IN OCTAL  ***************/


/**
 * print_octal - Prints an unsigned integer in octal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculate active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_octal(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_s_unsgnd(num, s);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, precision, s));
}



/************ PRINT UNSIGNED INTEGER IN HEXADECIMAL *************/


/**
 * print_hexadecimal - Prints an unsigned integer in hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_hexadecimal(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
		flag, 'x', width, precision, s));
}




/*********** PRINT UNSIGNED INTEGER IN UPPER HEXADECIMAL ************/


/**
 * print_hexa_upper - Prints an unsigned integer in upper hexadecimal notation
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_hexa_upper(va_list args, char buffer[],
	int flag, int width, int precision, int s)
{
	return (print_hexa(args, "0123456789ABCDEF", buffer,
		flag, 'X', width, precision, s));
}



/************ PRINT HEXX INTEGER IN LOWER OR UPPER ************/


/**
 * print_hexa - Prints a hexadecimal integer in lower or upper
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */

int print_hexa(va_list args, char map_to[], char buffer[],
	int flag, char flag_ch, int width, int precision, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_s_unsgnd(num, s);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flag, width, precision, s));
}
