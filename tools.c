/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:16:45 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/26 22:37:50 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int n)
{
	if (n == 0)
	{
		ft_printf("usage: ./fractol <fractal>\nFractals available:\n");
		ft_printf("> Mandelbrot\n> Julia\n> Burningship\n");
		exit(0);
	}
    if (n == 1)
		perror("mlx() error");
	exit(EXIT_FAILURE);
}

void	ft_check(int ac, char **av, t_fractol *fractol)
{
	if (ft_strncmp(av[1], "Mandelbrot", ft_strlen(av[1])) || \
		ft_strncmp(av[1], "Julia", ft_strlen(av[1])) || \
		ft_strncmp(av[1], "Julia", ft_strlen(av[1])))
		ft_error(0);
	fractol->fractal = av[1];

}
