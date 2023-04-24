#include "main.h"

/**
 * print_char - prints character
 * @l: argument pointer
 *
 * Return: number chars printed
 */
int print_char(va_list l)
{
	char *c;

	c = va_arg(l, char *);

	if (!c)
		return (NULL);

	write(STDOUT_FILENO, &c, 1);
	return (putchar(*c));
}
