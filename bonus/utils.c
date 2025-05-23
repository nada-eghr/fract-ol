/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:05:59 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/16 11:12:24 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}

void	init_var(t_fractol *fract)
{
	fract->iteration = 50;
	fract->zoom = 300;
	fract->offset_x = 1.9;
	fract->offset_y = 1.5;
	fract->color = get_rgba(0x05, 0x01, 0x01, 0xff);
	fract->r = 0x49;
	fract->g = 0x2e;
	fract->b = 0x5e;
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_rg_l(int r, int g, int b, t_fractol *fract)
{
	int	a;

	a = 0xff;
	r = ((float)(r) *((float)fract->i / 35));
	g = ((float)(g) *((float)fract->i / 35));
	b = ((float)(b) *((float)fract->i / 35));
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_rg_julia(int r, int g, int b, t_fractol *fract)
{
	int	a;

	a = 0xff;
	r = ((float)(r) *((float)fract->j / 5));
	g = ((float)(g) *((float)fract->j / 5));
	b = ((float)(b) *((float)fract->j / 5));
	return (r << 24 | g << 16 | b << 8 | a);
}
