#include "main.h"
/**
 * print_binary - print binary
 * @l: args
 * Return: integer
 */
int print_binary(va_list l)
{
	unsigned int num, max, i, sum;
	unsigned int a[32];
	int count;

	num = va_arg(l, unsigned int);
	max = 2147483648; /* (2 ^ 31) */
	a[0] = num / max;
	for (i = 1; i < 32; i++)
	{
		max /= 2;
		a[i] = (num / max) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
