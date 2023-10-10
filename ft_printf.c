/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:36:32 by saleshin          #+#    #+#             */
/*   Updated: 2023/09/28 15:36:41 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		counter;
	int		c;

	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd')
			{
				str = ft_itoa(va_arg(args, int));
				write(1, str, strlen(str));
				counter = counter + strlen(str) - 1;
				free(str);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str != NULL)
				{
				write(1, str, strlen(str));
				counter = counter + strlen(str) - 1;
				}
				else
					{
						write(1, "(null)", 6);
						counter = counter + 5;
					}
			}
			format++;
			counter++;
		}
		else
		{
		write(1, format, 1);
		format++;
		counter++;
		}
	}
	va_end(args);
	return (counter);
}
/*
int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
//	ft_printf("%c", "x");
//	printf(argv[1], 'w'); //argv[2]);
	printf("%s\n", NULL);
	ft_printf("%s", NULL);
//	ft_printf(argv[1], argv[2]);
	return (0);
}
*/