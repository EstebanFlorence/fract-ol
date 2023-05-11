/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:52 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/11 14:16:14 by adi-nata         ###   ########.fr       */
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
//	mlx_hook(fractol->win, 17, 0, exit, 1);
	mlx_mouse_hook(fractol->win, zoom_hook, fractol);
	mlx_loop(fractol->mlx);

}

int	key_hook(int key, t_fractol *fractol)
{
	if (key == B_ESC)
		exit(0);


	printf("key : %d\n", key);
/* 	printf("y min : %f\n", fractol->y_min);
	printf("y max : %f\n", fractol->y_max);
	printf("x min : %f\n", fractol->x_min);
	printf("x max : %f\n", fractol->x_max);*/
	printf("zoom : %f\n", fractol->zoom); 

	//ft_fractol(fractol);
	return (0);
}

int	zoom_hook(int button, int x, int y, t_fractol *fractol)
{
/* 	double	old_x;
	double	old_y;
	double	new_x;
	double	new_y;

	old_x = fractol->x_max - fractol->x_min;
	old_y = fractol->y_max - fractol->y_min; */

	if (button == ROT_UP)
	{
		fractol->zoom *= 1.1;
	}
	else if (button == ROT_DOWN)
	{
		fractol->zoom /= 1.1;
	}
/* 	else
		return (0); */
/* 	fractol->x_min = fractol->x_min + ((old_x - new_x) / 2) - (x / fractol->zoom);
	fractol->x_max = fractol->x_min + new_x;
	fractol->y_min = fractol->y_min + ((old_y - new_y) / 2) - (y / fractol->zoom);
	fractol->y_max = fractol->y_min + new_y;
 */
	printf("button : %d\n", button);
	printf("x : %d\n", x);
	printf("y : %d\n", y);
	printf("zoom : %f\n", fractol->zoom); 

	ft_matrix(fractol);
	return (0);
}

int	window_close()
{

	return (0);
}