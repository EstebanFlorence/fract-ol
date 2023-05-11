/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:15:14 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/11 15:04:22 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_yarrr(t_fractol *fractol)
{
	double	tmpx;

	ft_coordinates(fractol);
	fractol->iter = 0;
	while ((fractol->zx * fractol->zx + fractol->zy * fractol->zy < 4) \
			&& fractol->iter < MAX_ITER)
	{
		tmpx = fractol->zx * fractol->zx - fractol->zy * fractol->zy \
				+ fractol->cx;
		fractol->zy = 2 * fabs(fractol->zx * fractol->zy) + fractol->cy;
		fractol->zx = fabs(tmpx);
		fractol->iter++;
	}
	if (fractol->iter < MAX_ITER)
		ft_pixelput(fractol->img, fractol->x, fractol->y, \
					0xFF66B0F0 / fractol->iter);
	else
		ft_pixelput(fractol->img, fractol->x, fractol->y, 0x00000000);
}
