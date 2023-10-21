#include "main.h"

/******************* WRITE HANDLE ********************/


/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags.
 * @width: Get width.
 * @precision: precision specifier
 * @s: Size specifier
 * Return: Number of chars printed.
 */

int handle_write_char(char c, char buffer[],
	int flag, int width, int precision, int s)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(s);

	if (flag & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}



/**************** WRITE INTEGER *******************/

/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @i: char types.
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: Get width.
 * @precision: precision specifier
 * @s: Size specifier
 * Return: Number of chars printed.
 */

int write_number(int is_negative, int i, char buffer[],
	int flag, int width, int precision, int s)
{
	int length = BUFF_SIZE - i - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(s);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flag & F_PLUS)
		extra_ch = '+';
	else if (flag & F_SPACE)
		extra_ch = ' ';

	return (write_num(i, buffer, flag, width, precision,
		length, padd, extra_ch));
}


/**
 * write_num - Write a number using a bufffer
 * @i: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: Flags
 * @width: Get width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Number of printed chars.
 */

int write_num(int i, char buffer[],
	int flag, int width, int prec,
	int length, char padd, char extra_c)
{
	int j, padd_start = 1;

	if (prec == 0 && i == BUFF_SIZE - 2 && buffer[i] == '0' && width == 0)
		return (0);
	if (prec == 0 && i == BUFF_SIZE - 2 && buffer[i] == '0')
		buffer[i] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--i] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (j = 1; j < width - length + 1; i++)
			buffer[j] = padd;
		buffer[j] = '\0';
		if (flag & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[i], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[i], length));
		}
		else if (!(flag & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], j - padd_start) +
				write(1, &buffer[i], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--i] = extra_c;
	return (write(1, &buffer[i], length));
}


/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @i: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flag: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @s: Size specifier
 * Return: Number of written chars.
 */

int write_unsgnd(int is_negative, int i,
	char buffer[],
	int flag, int width, int precision, int s)
{
	int length = BUFF_SIZE - i - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(s);

	if (precision == 0 && i == BUFF_SIZE - 2 && buffer[i] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--i] = '0';
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flag & F_MINUS)
		{
			return (write(1, &buffer[i], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[i], length));
		}
	}

	return (write(1, &buffer[ind], length));
}


/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @i: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flag: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 * Return: Number of written chars.
 */

int write_pointer(char buffer[], int i, int length,
	int width, int flag, char padd, char extra_c, int padd_start)
{
	int j;

	if (width > length)
	{
		for (j = 3; j < width - length + 3; j++)
			buffer[j] = padd;
		buffer[j] = '\0';
		if (flag & F_MINUS && padd == ' ')
		{
			buffer[--i] = 'x';
			buffer[--i] = '0';
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && padd == ' ')
		{
			buffer[--i] = 'x';
			buffer[--i] = '0';
			if (extra_c)
				buffer[--i] = extra_c;
			return (write(1, &buffer[3], j - 3) + write(1, &buffer[i], length));
		}
		else if (!(flag & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], j - padd_start) +
				write(1, &buffer[i], length - (1 - padd_start) - 2));
		}
	}
	buffer[--i] = 'x';
	buffer[--i] = '0';
	if (extra_c)
		buffer[--i] = extra_c;
	return (write(1, &buffer[i], BUFF_SIZE - i - 1));
}
