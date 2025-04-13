/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:25:35 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/13 11:56:43 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	// if(!d || !s)
	// 	return 0;
	while ((d[i] || s[i]) && i < n)
	{
		if (d[i] != s[i])
			return (d[i] - s[i]);
		i++;
	}
	return (0);
}
double	ft_atoi(char *str)
{
	int		i;
	int		result;
	float 	res;
	int		sign;
	float 	pow = 1;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.' )
		i++;
	res = result;
	while ( str[i]  && str[i] >= '0' &&  str[i] <= '9' )
	{
		pow /= 10;
		res = res + (str[i] - '0') * pow ;
		i++;
	}
	return (res  * sign);
}
// int main()
// {
// 	char *str = "	 -34.75";
// 	printf("%f\n",ft_atoi(str) );
// 	char *str2 = "	 -34";
// 	printf("%d\n",atoi(str2) );
// }