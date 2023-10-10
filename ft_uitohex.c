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
#include "libftprintf.h"

char	*hexstring(unsigned long n)
{
	int		i;
	char	*s;

	i = 0;
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	s = malloc((i + 2) * sizeof(char));
	if (s == 0)
		return (0);
	s[i + 1] = '\0';
	return (s);
}

char	*hexrecursive(char *s, unsigned long n, int cs)
{
	char	*hex_base;
	char	*hex_base_upper;

	hex_base = "0123456789abcdef";
	hex_base_upper = "0123456789ABCDEF";
	if (n >= 16)
		s = hexrecursive(s, n / 16, cs);
	if (cs == 'X')
		*s++ = hex_base_upper[n % 16];
	else
		*s++ = hex_base[n % 16];
	return (s);
}

char	*ft_uitohex(unsigned long n, int cs)
{
	char			*s;
	unsigned long	ln;

	ln = n;
	s = hexstring(ln);
	if (s == 0)
		return (0);
	hexrecursive (s, ln, cs);
	return (s);
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