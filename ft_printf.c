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
	int		p_counter;
	int		c;

	counter = 0;
	p_counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			p_counter++;
			if (*format == 'd' || *format == 'i')
			{
				str = ft_itoa(va_arg(args, int));
				if (str == 0)
					return (-1);
				if (write(1, str, strlen(str)) == -1)
				{
					free(str);
					return(-1);
				}
				counter = counter + strlen(str) - 1;
				free(str);
			}
			else if (*format == '%')
			{
				if (write(1, format, 1) == -1)
					return (-1);
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				if (write(1, &c, 1) == -1)
					return(-1);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str != NULL)
				{
				if (write(1, str, strlen(str)) == -1)
					return (-1);
				counter = counter + strlen(str) - 1;
				}
				else
					{
						if (write(1, "(null)", 6) == -1)
							return (-1);
						counter = counter + 5;
					}
			}
			format++;
			counter++;
		}
		else
		{
		if (write(1, format, 1) == -1)
			return (-1);
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