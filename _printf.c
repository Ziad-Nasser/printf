#include <string.h>
#include <unistd.h>
#include "main.h"
/**
*write_string - function that prints a string
 *@l: args
 *Return: the number of characters
*/
int print_string(va_list l)
{
	int len;
	char *str;

	str = va_arg(l, char*);
	if (str == NULL)
		str = "(null)";
	len = strlen(str);
	write(STDOUT_FILENO, str, len);

	return (len);
}
/**
 *print_char - function that prints a char
 *@l: args
 *Return: the number of characters
*/
int print_char(va_list l)
{
	char c;

	c = (char) va_arg(l, int);
	write(STDOUT_FILENO, &c, 1);

	return (1);
}
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
*is_spec - function checks a spec
 *@spac: array of specifiers
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
/**
 *_printf - print function
 *@format: pointer to an array
 *Return: count or -1
 */
int _printf(const char *format, ...)
{
	int i, s_index, print_count;
	va_list l;

	specifier_t spacifiers[] = {
	  {'s', print_string}, {'c', print_char}
	, {'%', print_spec}, {'d', print_int}
	, {'i', print_int}, {'b', print_binary}};

	if (format == NULL)
		return (-1);

	va_start(l, format);
	print_count = 0;
	for (i = 0; (format != NULL) && (format[i] != '\0'); i++)
	{
		s_index = is_spec(spacifiers, (char *) (format + i));

		if (s_index == -2)
		{
			write(STDOUT_FILENO, (char *) (format + i), 1);
			print_count++;
		}
		else if (s_index == -1)
		{
			return (-1);
		}
		else
		{
			print_count = print_count + spacifiers[s_index].f(l);
			i++;
		}
	}
	va_end(l);
return (print_count);
}
