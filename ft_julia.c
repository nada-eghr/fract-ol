/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:36:43 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/14 17:06:37 by naessgui         ###   ########.fr       */
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

// uint8_t r = (0x05);
// uint8_t g = (0x01);
// uint8_t b = (0x01);
// uint8_t r = ((float)(0x72) * ((float)i / (fract->iteration / 10)));
// uint8_t g = ((float)(0xb5) * ((float)i / (fract->iteration / 10)));
// uint8_t b = ((float)(0x48) * ((float)i / (fract->iteration / 10)));