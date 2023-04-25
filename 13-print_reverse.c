#include "main.h"
/**
 * print_reverse - function that prints  reverse
 * @l: args
 * Return: count
 */
int print_reverse(va_list l)
{
	int i = 0, count = 0;
	char *rev;

	rev = va_arg(l, char *);
	if (rev == NULL)
		rev = ")llun(";
	while (rev[i])
		i++;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(rev[i]);
		count++;
	}
	return (count);
}
