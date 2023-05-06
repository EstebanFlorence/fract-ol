/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:29:52 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/07 00:24:36 by adi-nata         ###   ########.fr       */
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
	if (!mlx_hook(fractol->win, ))
		ft_error(2);
	if (!mlx_hook(fractol->win, ))
		ft_error(2);
	if (!mlx_hook(fractol->win, ))
		ft_error(2);
}

int	key_hook()
{

	return (0);
}

int	zoom_hook()
{

	return (0);
}

int	window_close()
{

	return (0);
}