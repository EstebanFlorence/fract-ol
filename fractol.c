/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:13:08 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/06 18:15:28 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol(t_fractol *fractol)
{
	if (fractol->fractal == "Mandelbrot")
		ft_mandelbrot(fractol);
	else if (fractol->fractal == "Julia")
		ft_julia();
	else if (fractol->fractal == "Burningship")
		ft_yarrr();
}

void	ft_structinnit(t_fractol *fractol)
{
	fractol->x = 0;
	fractol->x_min = -2.0;
	fractol->x_max = 2.0;
	fractol->y = 0;
	fractol->y_min = -2.0;
	fractol->y_max = 2.0;
	fractol->zoom = MAX_ITER;
	fractol->iter = 0;
}

//	Colora un singolo pixel. NB: img->data
void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->data + (y * img->size_line + x * (img->bitsxpixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_mlxinnit(t_fractol *fractol)
{
	int	i = 0;
	
	fractol->mlx = mlx_init();
	if (!(fractol->mlx))
		ft_error(1);
	fractol->win = mlx_new_window(fractol->mlx, WIN_WIDTH, WIN_HEIGHT, fractol->fractal);
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
	ft_fractol(fractol);
	//ft_mlxplay(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img->ptr, 0, 0);
	mlx_loop(fractol->mlx);
}

void	ft_check(int ac, char **av, t_fractol *fractol)
{
	if (ac != 2)
		ft_error(0);
	if (ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])) && \
		ft_strncmp(av[1], "Julia", ft_strlen(av[1])) && \
		ft_strncmp(av[1], "Burningship", ft_strlen(av[1])))
		ft_error(0);
	fractol->fractal = av[1];

}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	fractol.img = malloc(sizeof(t_image));
	ft_check(ac, av, &fractol);
	ft_mlxinnit(&fractol);
	ft_fractol(&fractol);
	//ft_structinnit(&fractol);

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
