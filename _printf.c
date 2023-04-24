#include <unistd.h>
#include <string.h>
#include "main.h"
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
		/*to select spacifier*/
		for (i = 0; i < 10; i++)
		{
			if (spacifiers[i].s == ch)
				return (i);
		}
	}
	/*not found*/
	return (-2);
}
/**
 *_printf - a function to print a string using a format
 *@format: pointer to an array containing the string of chars to be handled
 *Return: count or error upon failing (-1)
 */
int _printf(const char *format, ...)
{
	int i, s_input, print_count = 0;
	va_list l;
	specifier_t spacifiers[] = {
	{'s', print_string}, {'c', print_char}, {'%', print_percent}
	, {'d', print_int}, {'i', print_int}, {'b', print_binary}
	, {NULL, NULL}};

	if (format == NULL)
		return (-1);

	va_start(l, format);
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
