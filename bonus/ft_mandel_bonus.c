/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:25:21 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/16 11:10:39 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_mandelbrot(t_fractol *fract)
{
	double	tmp;
	int		i;

	fract->zx = 0;
	fract->zy = 0;
	fract->cx = ((fract->x / fract->zoom) - fract->offset_x);
	fract->cy = ((fract->y / fract->zoom) - fract->offset_y);
	i = 0;
	while (++i < fract->iteration)
	{
		tmp = fract->zx;
		fract->zx = (fract->zx * fract->zx) - (fract->zy * fract->zy)
			+ fract->cx;
		fract->zy = 2 * tmp * fract->zy + fract->cy;
		if ((fract->zx * fract->zx) + (fract->zy * fract->zy) > 4)
			break ;
	}
	fract->i = i;
	if (i == fract->iteration)
		mlx_put_pixel(fract->image, fract->x, fract->y, fract->color);
	else
	{
		fract->color_2 = get_rg_l(fract->r, fract->g, fract->b, fract);
		mlx_put_pixel(fract->image, fract->x, fract->y, fract->color_2);
	}
}
