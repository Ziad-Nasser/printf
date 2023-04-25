#include "main.h"

/**
 * print_hex - prints an ascii value in lowercase
 * hexidecimal
 * @ap: variadic argument
 * Return: integer
 */
int print_hex(va_list ap)
{
	unsigned int i[8];
	unsigned int j, m = 268435456, n, res = 0;
	char diff;
	int count = 0;

	n = va_arg(ap, unsigned int);
	diff = 'a' - ':';
	i[0] = n / m;
	for (j = 1; j < 8; j++)
	{
		m /= 16;
		i[j] = (n / m) % 16;
	}
	for (j = 0; j < 8; j++)
	{
		res += i[j];
		if (res || j == 7)
		{
			if (i[j] < 10)
				_putchar('0' + i[j]);
			else
				_putchar('0' + diff + i[j]);
			count++;
		}
	
	return (count);
}
