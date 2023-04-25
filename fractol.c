/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:13:08 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/25 19:48:18 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int n)
{
    if (n == 0)
        perror("args error");
    
    exit(EXIT_FAILURE);
}

void	ft_innit(int ac, char **av)
{
    if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])))
		ft_mandelbrot();
    else if (ft_strncmp(av[1], "julia", ft_strlen(av[1])))
		ft_julia();
    else if (ft_strncmp(av[1], "burning-ship", ft_strlen(av[1])))
        ft_burningship();
    else
}

int	main(int ac, char **av)
{
    if (ac != 2)
        ft_error(0);
    ft_innit(ac, av);

    return (0);
}
