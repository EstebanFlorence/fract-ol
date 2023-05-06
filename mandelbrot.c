/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:20:32 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:10 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractolinnit(t_fractol *fractol)
{
	fractol->cx = fractol->x / fractol->zoom + fractol->x_min;
	fractol->cy = fractol->y / fractol->zoom + fractol->y_max;
	fractol->zx = 0;
	fractol->zy = 0;
}

void	ft_mandelbrot(t_fractol *fractol)
{
	double	tmpx;

	while (fractol->y < WIN_HEIGHT)
	{
		while (fractol->x < WIN_WIDTH)
		{
			ft_fractolinnit(fractol);
			while ((fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4) && fractol->iter < MAX_ITER)
			{
				tmpx = fractol->zx * fractol->zx - fractol->zy * fractol->zy + fractol->cx;
				fractol->zy = 2 * fractol->zx * fractol->zy + fractol->cy;
				fractol->zx = tmpx;
				fractol->iter++;
			}
			my_mlx_pixel_put(fractol->img, fractol->x, fractol->y, 0x000FF0FF);
			fractol->x++;
		}
		fractol->y++;
	}
}
