#include "main.h"
/**
 * print_binary - converts a number from decimal to binary
 * @l: unsigned integer to convert
 * Return: integer
 */
int print_binary(va_list l)
{
	unsigned int num;
	unsigned int binary[32];
	int j, i = 0, count = 0, res = 0;

	num = va_arg(l, unsigned int);
	while (num > 0)
	{
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		res = _putchar('0' + binary[j]);
		count = count + res;
	}
	return (count);
}
