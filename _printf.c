#include "main.h"

/**
* _printf - A function that produces output
* @format: format string
* Return: The number of characters printed (excluding the null byte
*
*/

int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
	int printed_characters = 0;
	va_list list_arguments;

	return ((format == NULL) ? (-1) :);

	va_start(list_arcguments, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_characters++;
		}

		else

		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				printed_characters++;
			}

			else if (*format == 'c')

			{
				char c = va_arg(list_arguments, int);

				write(1, &c, 1);
				printed_characters++;
			}

			else if (*format == 's')

			{
				char *str = va_arg(list_arguments, char*);
				int str_len = 0;

				while (str[str_len] != '\0')
					str_len++;

				write(1, str, str_len);
				printed_characters += str_len;
			}

		}

		format++;

	}

	va_end(list_arguments);

}
