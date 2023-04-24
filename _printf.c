#include "main.h"
#include <string.h>
#include <unistd.h>
/**
*print_string - a function that writes a string to the standard output
 *@l:variadic arguments
 *Return:the number of characters printed
*/
int print_string(va_list l)
{
	int len;
	char *str;

	str = va_arg(l, char*);
	if (str == NULL)
		str = "(null)";
	len = strlen(str);
	print(STDOUT_FILENO, str, len);

	return (len);
}
/**
 *print_char - a function that writes a char to the standard output
 *@l:variadic arguments
 *Return:the number of characters printed
*/
int print_char(va_list l)
{
	char c;

	c = (char) va_arg(l, int);
	write(STDOUT_FILENO, &c, 1);

	return (1);
}
/**
 *print_specifier - a function that writes a specifier to the standard output
 *@l:variadic arguments
 *Return:the number of characters printed
*/
int print_specifier(va_list l)
{
	(void) l;
	write(STDOUT_FILENO, "%", 1);

	return (1);
}
/**
 * is_spec - checks if a character is a format specifier
 * @spacifiers: an array of specifier_t structs
 * @format: p to arr
 * Return: the index of the specifier if found, or -2 if not found
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

		for (i = 0; i < 12; i++)
		{
			if (spacifiers[i].s == ch)
				return (i);
		}
	}

	return (-2);
}
/**
 *_printf - a function to print a string using a format
 *@format: pointer to an array containing the string of chars to be handled
 *Return: count or error upon failing (-1)
 */
int _printf(const char *format, ...)
{
	int i, s_input, print_count;
	va_list l;
	specifier_t spacifiers[] = {
	  {'s', print_string}, {'c', print_char}
	, {'%', print_specifier}, {'d', print_int}
	, {'i', print_int}, {'b', print_binary}};

	if (format == NULL)
		return (-1);

	va_start(l, format);
	print_count = 0;
	for (i = 0; (format != NULL) && (format[i] != '\0'); i++)
	{
		s_input = is_specifier(spacifiers, (char *) (format + i));

		if (s_input == -2)
		{
			write(STDOUT_FILENO, (char *) (format + i), 1);
			print_count++;
		}
		else if (s_input == -1)
		{
			return (-1);
		}
		else
		{
			print_count = print_count + spacifiers[s_input].f(l);
			i++;
		}
	}
	va_end(l);
return (print_count);
}
