/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:13:08 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/26 23:19:57 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



void	ft_fractol(t_fractol *fractol)
{
	if (fractol->fractal == "Mandelbrot")
		ft_mandelbrot();
	else if (fractol->fractal == "Julia")
		ft_julia();
	else if (fractol->fractal == "Burningship")
		ft_yarrr();
}

void	ft_innit(t_fractol *fractol)
{
	fractol->x_min = -2.0;
	fractol->x_max = 2.0;
	fractol->y_min = -2.0;
	fractol->y_max = 2.0;
}

void	ft_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!(fractol->mlx))
		ft_error(1);
	fractol->win = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	if (!(fractol->win))
		ft_error(1);
	fractol->img->ptr = mlx_new_image(fractol->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!(fractol->img))
		ft_error(1);
	fractol->img->data = mlx_get_data_addr(fractol->img->ptr, \
						&fractol->img->bitsxpixel, \
						&fractol->img->size_line, \
						&fractol->img->endian);
	if (!(fractol->img->data))
		ft_error(1);
	
}

void	ft_check(int ac, char **av, t_fractol *fractol)
{
	if (ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])) || \
		ft_strncmp(av[1], "Julia", ft_strlen(av[1])) || \
		ft_strncmp(av[1], "Julia", ft_strlen(av[1])))
		ft_error(0);
	fractol->fractal = av[1];

}

int	key_hook(int key, t_fractol *fractol)
{
	ft_printf("KEY HOOK!\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac != 2)
		ft_error(0);
	ft_check(ac, av, &fractol);
	ft_mlx(&fractol);
	ft_innit(&fractol);
	ft_fractol(&fractol);

	return (0);
}


/* int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, 1000, 700, "Ciao");
	mlx_key_hook(fractol.win, key_hook, &fractol);
	mlx_loop(fractol.mlx);

	return (0);
} */
