#include "main.h"
/**
 * print_binary - print binary
 * @l: args
 * Return: number
 */
int print_binary(va_list l)
{
	unsigned int num;
	unsigned int binary[32];
	int j, i = 0, counter = 0, result = 0;

	num = va_arg(l, unsigned int);
	while (num > 0)
	{
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		result = _putchar('0' + binary[j]);
		counter = counter + result;
	}
	return (counter);
}
