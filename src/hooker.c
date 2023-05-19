/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:52 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/19 16:14:48 by adi-nata         ###   ########.fr       */
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
		ft_exit(fractol);
	if (key == ARROW_UP)
		fractol->y_min -= fractol->img_shift;
	if (key == ARROW_DOWN)
		fractol->y_min += fractol->img_shift;
	if (key == ARROW_LEFT)
		fractol->x_min -= fractol->img_shift;
	if (key == ARROW_RIGHT)
		fractol->x_min += fractol->img_shift;
	if (key == C_KEY || key == Z_KEY)
		ft_coloriter(key, fractol);
	ft_render(fractol);
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
		fractol->zoom *= ZOOM_FACTOR;
		fractol->img_shift /= ZOOM_FACTOR;
	}
	else if (button == ROT_DOWN)
	{
		fractol->zoom /= ZOOM_FACTOR;
		fractol->img_shift *= ZOOM_FACTOR;
	}
	else
		return (0);
	fractol->x_min = tmpx - (x / fractol->zoom);
	fractol->y_min = tmpy - (y / fractol->zoom);
	ft_render(fractol);
	return (0);
}

void	ft_coloriter(int key, t_fractol *fractol)
{
	int	i;

	i = fractol->color_iter;
	if (key == C_KEY)
	{
		if (i < COLOR_SETS - 1)
			i++;
		else
			i = 0;
	}
	if (key == Z_KEY)
	{
		if (i > 0)
			i--;
		else
			i = COLOR_SETS - 1;
	}
	fractol->color_iter = i;
}
