/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:52 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/11 16:39:57 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlxhooks(t_fractol *fractol)
{
	mlx_hook(fractol->win, 2, 1L << 0, key_hook, fractol);
	mlx_hook(fractol->win, 17, 0, ft_exit, fractol);
	mlx_mouse_hook(fractol->win, zoom_hook, fractol);
	mlx_loop(fractol->mlx);
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == B_ESC)
		exit(0);
	if (key == ARROW_UP)
		fractol->y_min -= fractol->img_shift;
	if (key == ARROW_DOWN)
		fractol->y_min += fractol->img_shift;
	if (key == ARROW_LEFT)
		fractol->x_min -= fractol->img_shift;
	if (key == ARROW_RIGHT)
		fractol->x_min += fractol->img_shift;
	printf("key : %d\n", key);
	printf("zoom : %f\n", fractol->zoom);
	ft_rendering(fractol);
	return (0);
}

int	zoom_hook(int button, int x, int y, t_fractol *fractol)
{
	double	tmpx;
	double	tmpy;

	tmpx = x / fractol->zoom + fractol->x_min;
	tmpy = y / fractol->zoom + fractol->y_min;
	if (button == ROT_UP)
	{
		fractol->zoom *= 1.1;
		fractol->img_shift /= 1.1;
	}
	else if (button == ROT_DOWN)
	{
		fractol->zoom /= 1.1;
		fractol->img_shift *= 1.1;
	}
	else
		return (0);
	fractol->x_min = tmpx - (x / fractol->zoom);
	fractol->y_min = tmpy - (y / fractol->zoom);
	printf("display shift : %f\n", fractol->img_shift);
	ft_rendering(fractol);
	return (0);
}
