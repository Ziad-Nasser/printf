#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/**
 * struct specifier - Struct specifier
 *
 * @s: specifier char
 * @f: function to deal with this specifier
 */
typedef struct specifier
{
	char s;
	int (*f)(va_list args);
} specifier_t;
int _printf(const char *format, ...);
int is_spec(specifier_t spacifiers[], char *format);
int print_spec(va_list l);
int print_int(va_list l);
int print_binary(va_list l);
int _putchar(char c);
int print_reverse(va_list l);
#endif
