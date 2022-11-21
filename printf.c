#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
#include <stdlib.h>

/**
 * check_for_specifiers - checks if there is a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 * find_correct_func - finding the format for _printf
 * @format: format
 * Return: NULL
 */
static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int i;
	print_t p[] = {
		{"c", print_char},
                {"s", print_string},
                {"i", print_int},
                {"d", print_dec},
                {"r", print_rev},
                {"b", print_bin},
                {"u", print_unsigned},
                {"o", print_octal},
                {"x", print_hex},
                {"X", print_HEX},
                {"R", print_rot13},
                {"S", print_S},
                {"p", print_p},
                {NULL, NULL}
	};
	for (i = 0; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
		{
			break;
		}
	}
	return (p[i].f);
int (*find_correct_func(const char *format))(va_list)
{
unsigned int i = 0;
code_f find_f[] = {
{"c", print_char},
{"s", print_string},
{"i", print_int},
{"d", print_dec},
{"r", print_rev},
{"b", print_bin},
{"u", print_unsigned},
{"o", print_octal},
{"x", print_hex},
{"X", print_HEX},
{"R", print_rot13},
{"S", print_S},
{"p", print_p},
{NULL, NULL}
};

while (find_f[i].sc)
{
if (find_f[i].sc[0] == (*format))
return (find_f[i].f);
i++;
}
return (NULL);
}

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 * _printf - produces an output based on format
 * @format: format
 * Return: size
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(valist, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = check_for_specifiers(&format[i + 1]);
		if (f != NULL)
		{
			count += f(valist);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	a_end(valist);
	return (count);
va_list list;
int (*f)(va_list);
unsigned int i = 0, len = 0;
if (format == NULL)
return (-1);
va_start(list, format);
while (format[i])
{
while (format[i] != '%' && format[i])
{
_putchar(format[i]);
len++;
i++;
}
if (format[i] == '\0')
return (len);
f = find_correct_func(&format[i + 1]);
if (f != NULL)
{
len += f(list);
i += 2;
continue;
}
if (!format[i + 1])
return (-1);
_putchar(format[i]);
len++;
if (format[i + 1] == '%')
i += 2;
else
i++;
}
va_end(list);
return (len);
}
