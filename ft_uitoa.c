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

char	*ustring(unsigned int n)
{
	int		i;
	char	*s;

	i = 0;
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

char	*urecursive(char *s, unsigned int n)
{
	if (n >= 10)
		s = urecursive(s, n / 10);
	*s++ = '0' + (n % 10);
	return (s);
}

char	*ft_uitoa(unsigned int n)
{
	char			*s;
	unsigned int	ln;

	ln = n;
	s = ustring(ln);
	if (s == 0)
		return (0);
	urecursive (s, ln);
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