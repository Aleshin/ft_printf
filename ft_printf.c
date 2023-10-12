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
#include "ft_printf.h"

int	s_function(va_list args, int *counter)
{
	char	*str;

	str = va_arg(args, char *);
	if (str != NULL)
	{
		if (write(1, str, ft_strlen(str)) == -1)
			return (-1);
		*counter = *counter + ft_strlen(str) - 1;
	}
	else
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*counter = *counter + 5;
	}
	return (0);
}

int	check(const char *format, va_list args, int *counter)
{
	int		c;		

	if (*format == 'd' || *format == 'i')
		if (di_function(args, counter) == -1)
			return (-1);
	if (*format == 'u')
		if (u_function(args, counter) == -1)
			return (-1);
	if (*format == 'x' || *format == 'X' || *format == 'p')
		if (xp_function(args, *format, counter) == -1)
			return (-1);
	if (*format == '%')
		if (write(1, format, 1) == -1)
			return (-1);
	if (*format == 'c')
	{
		c = va_arg(args, int);
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	if (*format == 's')
		if (s_function(args, counter) == -1)
			return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (check(format, args, &counter) == -1)
				return (-1);
		}
		else if (write(1, format, 1) == -1)
			return (-1);
		format++;
		counter++;
	}
	va_end(args);
	return (counter);
}
