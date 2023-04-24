#include "main.h"

/**
 * print_char - prints character
 * @l: argument pointer
 *
 * Return: number chars printed
 */
int print_char(va_list l)
{
	char c;

	c = (char) va_arg(l, int);
	write(STDOUT_FILENO, &c, 1);

	return (1);
}
