#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16


#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 * @format: The format.
 * @fn: The function associated.
 */

struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - Struct op
 * @format: The format
 * @format_t: The function associated.
 */

typedef struct format format_t;

int _printf(const char *format, ...);
int handle_print(const char *format, int *i,
va_list list, char buffer[], int flag, int width, int precision, int s);



/************* FUNCTIONS **************/


/* Funtions to print chars and strings */
int print_char(va_list args, char buffer[],
	int flag, int width, int precision, int s);
int print_string(va_list args, char buffer[],
	int flag, int width, int precision, int s);
int print_percent(va_list args, char buffer[],
	int flag, int width, int precision, int s);


/* Functions to print integers */
int print_int(va_list args, char buffer[],
	int flag, int width, int precision, int s);
int print_binary(va_list args, char buffer[],
	int flag, int width, int precision, int s);
int print_unsigned(va_list args, char buffer[],
	int flag, int width, int precision, int s);
int print_octal(va_list args, char buffer[],
	int flag, int width, int precision, int s);
int print_hexadecimal(va_list args, char buffer[],
	int flag, int width, int precision, int s);
int print_hexa_upper(va_list args, char buffer[],
	int flag, int width, int precision, int s);
int print_hexa(va_list args, char map_to[],
char buffer[], int flag, char flag_ch, int width, int precision, int s);


/* Function to print non printable characters */
int print_non_printable(va_list args, char buffer[],
	int flag, int width, int precision, int s);


/* Funcion to print memory address */
int print_pointer(va_list args, char buffer[],
	int flag, int width, int precision, int s);


/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);


/*Function to print string in reverse*/
int print_reverse(va_list args, char buffer[],
	int flag, int width, int precision, int s);


/*Function to print a string in rot13*/
int print_rot13string(va_list args, char buffer[],
	int flag, int width, int precision, int s);


/* width handler */
int handle_write_char(char c, char buffer[],
	int flag, int width, int precision, int s);
int write_number(int is_positive, int i, char buffer[],
	int flag, int width, int precision, int s);
int write_num(int i, char bff[], int flag, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int i, int length,
	int width, int flag, char padd, char extra_c, int padd_start);

int write_unsignd(int is_negative, int i,
char buffer[],
	int flag, int width, int precision, int s);


/**************** UTILS ****************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_s_number(long int num, int s);
long int convert_s_unsgnd(unsigned long int num, int s);

#endif
