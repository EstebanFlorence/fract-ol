/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:52 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/07 16:38:29 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* int	key_hook(int key, t_fractol *fractol)
{
	ft_printf("KEY HOOK!\n");
	return (0);
} */

void	ft_mlxhooks(t_fractol *fractol)
{
	if (!mlx_hook(fractol->win, 2, 1L<<0, key_hook, fractol))
		ft_error(2);
	if (!mlx_hook(fractol->win, 4, 1L<<2, zoom_hook, fractol))
		ft_error(2);
}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == B_ESC)
		exit(0);
	else if (key == W_KEY)
		fractol->y_max -= 0.1 / fractol->zoom;
	else if (key == A_KEY)
		fractol->x_min -= 0.1 / fractol->zoom;
	else if (key == S_KEY)
		fractol->y_max += 0.1 / fractol->zoom;
	else if (key == D_KEY)
		fractol->x_min += 0.1 / fractol->zoom;
	else if (key == Q_KEY)
		fractol->zoom *= 1.1;
	else if (key == E_KEY)
		fractol->zoom /= 1.1;
	else if (key == R_KEY)
		fractol->max_iter += 10;
	else if (key == T_KEY)
		fractol->max_iter -= 10;
/* 	else if (key == MIN_KEY)
		fractol->color -= 0x010101;
	else if (key == MAG_KEY)
		fractol->color += 0x010101; */
	ft_printf("key hook\n");
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img->ptr, 0, 0);
	return (0);
}

int	zoom_hook(int button, int x, int y, t_fractol *fractol)
{
	if (button == ROT_UP)
	{
		fractol->x_min += (x / fractol->zoom) / 2;
		fractol->y_max += (y / fractol->zoom) / 2;
		fractol->zoom *= 1.1;
	}
	else if (button == ROT_DOWN)
	{
		fractol->x_min += (x / fractol->zoom) / 2;
		fractol->y_max += (y / fractol->zoom) / 2;
		fractol->zoom /= 1.1;
	}
	ft_printf("mouse hook\n");
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img->ptr, 0, 0);
	return (0);
}

int	window_close()
{

	return (0);
}