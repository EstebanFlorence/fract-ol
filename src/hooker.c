/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:52 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/10 18:50:48 by adi-nata         ###   ########.fr       */
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
	mlx_hook(fractol->win, 17, 0, zoom_hook, fractol);
	mlx_mouse_hook(fractol->win, zoom_hook, fractol);
	mlx_loop(fractol->mlx);

}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == B_ESC)
		exit(0);


	printf("key : %d\n", key);
	printf("y min : %f\n", fractol->y_min);
	printf("y max : %f\n", fractol->y_max);
	printf("x min : %f\n", fractol->x_min);
	printf("x max : %f\n", fractol->x_max);
	printf("zoom : %f\n", fractol->zoom);

	//ft_fractol(fractol);
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
	}
	else if (button == ROT_DOWN)
	{
		fractol->zoom /= 1.1;
	}
	fractol->x_min = tmpx - (x / fractol->zoom);
	fractol->y_min = tmpy - (y / fractol->zoom);

	printf("button : %d\n", button);
	printf("y max : %f\n", fractol->y_max);
	printf("x min : %f\n", fractol->x_min);
	printf("zoom : %f\n", fractol->zoom);

	ft_fractol(fractol);
	return (0);
}

int	window_close()
{

	return (0);
}