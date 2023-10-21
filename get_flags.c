#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @p: take a parameter.
 * Return: Flag:
 */

int get_flags(const char *format, int *p)
{
	int j, i;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (i = *p + 1; format[i] != '\0'; i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[i] == FLAGS_CH[j])
			{
				flag |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*p = i - 1;

	return (flag);
}
