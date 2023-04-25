#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 *print_spec - function that prints a specifier
 *@l: args
 *Return:the number of characters
 */
int print_spec(va_list l)
{
	(void) l;
	write(STDOUT_FILENO, "%", 1);

	return (1);
}
/**
 * is_spec - function checks a spec
 *@spacifiers: array of specifiers
 *@format: pointer to an array
 *Return: -1 or i
 */
int is_spec(specifier_t spacifiers[], char *format)
{
	int i;
	char ch;

	i = 0;
	if (format[i] == '%')
	{
		if (format[i + 1] == '\0')
			return (-1);
		ch = format[i + 1];

		for (i = 0; i < 14; i++)
		{
			if (spacifiers[i].s == ch)
				return (i);
		}
	}

	return (-2);
}
