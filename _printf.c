#include "main.h"

/**
 * _printf - prints formatted output to stdout
 * @format: a string containing zero or more format specifiers
 * Return: the number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list l;
	int s_input, write_count = 0;
	char *p;

	specifier_t spacifiers[] = {
		{'s', print_string},
		{'c', print_char},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{NULL, NULL}
	};
	va_start(l, format);
	if (!format || (format[0] == '%' && !format[1])
			|| (format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			s_input = is_spec(spacifiers, l);
			if (s_input == -2)
			{
				write(STDOUT_FILENO, p + 1, 1);
				write_count++;
			}
			else if (s_input == -1)
				return (-1);

			else
				write_count += spacifiers[s_input].f(l);
		}
		else
		{
			write(STDOUT_FILENO, p, 1);
			write_count++;
		}
	}
	va_end(l);
	return (write_count);
}
