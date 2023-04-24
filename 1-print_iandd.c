#include <unistd.h>
#include "main.h"
#include <stdarg.h>
/**
 * print_int - function that prints integer number
 * @args: args
 * Return: the number of digit
*/
int print_int(va_list args)
{
	int size = 0, num;
	unsigned int number;
	char c;

	num = va_arg(args, int);
	if (num < 0)
	{
		c = '-';
		write(STDOUT_FILENO, &c, 1);
		size = 1;
		number = c * -1;
	}
	else
		number = num;

	if (num == 0)
	{
		c = '0';
		write(STDOUT_FILENO, &c, 1);
		return (1);
	}
	num = 1;
	while ((number / num) > 9)
	{
		num *= 10;
	}
	while (num != 0)
	{
		c = '0' + (number / num);
		write(STDOUT_FILENO, &c, 1);
		number %= num;
		num /= 10;
		size++;
	}
	return (size);
}
