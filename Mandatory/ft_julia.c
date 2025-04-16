/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:36:43 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/16 09:33:45 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fractol *fract)
{
	double	tmp;
	int		color;
	int		i;

	fract->zx = ((fract->x / fract->zoom) - fract->offset_x);
	fract->zy = ((fract->y / fract->zoom) - fract->offset_y);
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
	fract->j = i;
	if (i == fract->iteration)
		mlx_put_pixel(fract->image, fract->x, fract->y, fract->color);
	else
	{
		color = get_rg_julia(0x49, 0x2e, 0x5e, fract);
		mlx_put_pixel(fract->image, fract->x, fract->y, color);
	}
}
