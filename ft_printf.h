/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:43:13 by saleshin          #+#    #+#             */
/*   Updated: 2023/09/28 15:43:17 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

int		ft_printf(const char *format, ...);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_uitohex(unsigned long n, int cs);
int		di_function(va_list args, int *counter);
int		u_function(va_list args, int *counter);
int		xp_function(va_list args, int cs, int *counter);
int		s_function(va_list args, int *counter);

#endif