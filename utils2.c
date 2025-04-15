/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:31:26 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/15 17:03:31 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strlen(char *str)
{
	int i ;

	i  = 0;
	while (str[i])
		i++;
	return i;
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
void	f_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

static double	handl_atoi(char *s)
{
	double	fractional_part;
	double	pow;

	fractional_part = 0;
	pow = 1;
	if ('.' == *s)
		++s;
	if(*s == '\0')
		f_error("Error");
	while (*s)
	{
		if (*s < '0' || *s > '9')
			f_error("Error");
		else
		{
			pow /= 10;
			fractional_part = fractional_part + (*s++ - 48) * pow;
		}
	}
	return (fractional_part);
}

double	ft_atoi(char *s)
{
	double	result;
	long	integer_part;
	int		sign;

	sign = +1;
	integer_part = 0;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	if ('+' == *s || '-' == *s)
	{
		if ('-' == *s)
			sign = -sign;
		s++;
	}
	if (*s == '\0')
		f_error("Error");
	while (*s != '.' && *s)
	{
		if (*s < '0' || *s > '9')
			f_error("Error");
		else
			integer_part = (integer_part * 10) + (*s++ - 48);
	}
	result = handl_atoi(s) + integer_part;
	return ((result * sign));
}
