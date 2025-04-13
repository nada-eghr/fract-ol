/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:25:21 by naessgui          #+#    #+#             */
/*   Updated: 2025/04/13 15:42:04 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void ft_mandelbrot(t_fractol *fract)
{
	fract->Zx = 0;
	fract->Zy = 0;
	double tmp;

	fract->Cx= ((fract->x / fract->zoom) - fract->offset_x) ;
	fract->Cy= ((fract->y / fract->zoom) - fract->offset_y) ;
	int i = 0;
	fract->iteration = 800;
	while ( ++i < fract->iteration )
	{
		tmp = fract->Zx;
		fract->Zx = (fract->Zx * fract->Zx) - (fract->Zy * fract->Zy) + fract ->Cx;
		fract->Zy = 2 * tmp * fract->Zy + fract->Cy;	
		if (( fract->Zx * fract->Zx) + (fract->Zy * fract->Zy) > 4)
			break;
	}
	if(i == fract->iteration)
		mlx_put_pixel(fract->image, fract->x, fract->y, 0x00FF00);
	else 
		mlx_put_pixel(fract->image, fract->x, fract->y, 0x4484bd);
}
	
