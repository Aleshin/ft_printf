/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:00:28 by saleshin          #+#    #+#             */
/*   Updated: 2023/08/14 18:34:19 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*string(long n)
{
	int		i;
	char	*s;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	s = malloc((i + 2) * sizeof(char));
	if (s == 0)
		return (0);
	s[i + 1] = '\0';
	return (s);
}

char	*recursive(char *s, long n)
{
	if (n < 0)
	{
		*s++ = '-';
		n = -n;
	}
	if (n >= 10)
		s = recursive(s, n / 10);
	*s++ = '0' + (n % 10);
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	ln;

	ln = n;
	s = string(ln);
	if (s == 0)
		return (0);
	recursive (s, ln);
	return (s);
}

int	di_function(va_list args, int *counter)
{
	char	*str;

	str = ft_itoa(va_arg(args, int));
	if (str == 0)
		return (-1);
	if (write(1, str, ft_strlen(str)) == -1)
	{
		free(str);
		return (-1);
	}
	*counter = *counter + ft_strlen(str) - 1;
	free(str);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s\n", ft_itoa(-2147483647-1));
	printf("%s\n", ft_itoa(atoi(argv[1])));
	return (0);
}
*/