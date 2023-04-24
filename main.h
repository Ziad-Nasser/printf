#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/**
 * struct specifier - Struct specifier
 * @s: specifier char
 * @f: function to deal with this specifier
 */
typedef struct specifier
{
	char s;
	int (*f)(va_list args);
} specifier_t;

int print_char(va_list l );
int print_string(va_list l);
int _printf(const char *format, ...);
int print_int(va_list args);
int _putchar(char c);
int print_percent(va_list l);
#endif
