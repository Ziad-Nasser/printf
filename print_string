#include "main.h"

/**
 * print_string - prints a string
 * @l: a va_list containing the string to print
 *
 * Return: the number of characters printed
 */
int print_string(va_list l)
{
        char *s;
        int i = 0;

        s = va_arg(l, char *);

        if (!s)
                return (0);

        while (*s) {
                putchar(*s);
                s++;
                i++;
        }

        write(STDOUT_FILENO, s - i, i);
        return (i);
}
