/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:52 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/09 23:50:18 by adi-nata         ###   ########.fr       */
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
	mlx_hook(fractol->win, 2, 1L<<0, key_hook, fractol);
	mlx_hook(fractol->win, 4, 1L<<2, zoom_hook, fractol);
	mlx_loop(fractol->mlx);

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

	printf("key : %d\n", key);
	printf("y min : %f\n", fractol->y_min);
	printf("y max : %f\n", fractol->y_max);
	printf("x min : %f\n", fractol->x_min);
	printf("x max : %f\n", fractol->x_max);
	printf("zoom : %f\n", fractol->zoom);

	ft_fractol(fractol);
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

/* 	printf("button : %d\n", button);
	printf("y max : %f\n", fractol->y_max);
	printf("x min : %f\n", fractol->x_min);
	printf("zoom : %f\n", fractol->zoom); */

	ft_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img->ptr, 0, 0);
	return (0);
}

int	window_close()
{

	return (0);
}